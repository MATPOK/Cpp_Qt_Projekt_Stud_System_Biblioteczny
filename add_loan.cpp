#include "add_loan.h"
#include "ui_add_loan.h"

Add_loan::Add_loan(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Add_loan)
    , database(nullptr)
    , previousWindow(nullptr)
    , selectedClientId(-1)
{
    ui->setupUi(this);

    QDate today = QDate::currentDate();
    ui->loan_loan_date->setDate(today);
    ui->loan_return_date->setDate(today.addDays(1));
}

Add_loan::~Add_loan()
{
    delete ui;
}

void Add_loan::setDatabase(Database* db)
{
    this->database = db;
    loadClients();
    loadBooks();
}

void Add_loan::setPreviousWindow(QWidget* prev)
{
    this->previousWindow = prev;
}

void Add_loan::closeEvent(QCloseEvent *event)
{
    if (previousWindow)
        previousWindow->show();
    QMainWindow::closeEvent(event);
}

void Add_loan::loadClients(const QString &filter)
{
    QString queryStr = "SELECT id, first_name, last_name FROM clients";
    if (!filter.isEmpty()) {
        queryStr += " WHERE first_name ILIKE '%" + filter + "%' OR last_name ILIKE '%" + filter + "%'";
    }

    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery(queryStr, database->getDb());

    model->setHeaderData(1, Qt::Horizontal, "Imię");
    model->setHeaderData(2, Qt::Horizontal, "Nazwisko");

    ui->client_table->setModel(model);
    ui->client_table->hideColumn(0);
    ui->client_table->horizontalHeader()->setStretchLastSection(true);
    ui->client_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->client_table->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->client_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void Add_loan::loadBooks()
{
    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery("SELECT id, title FROM books WHERE available = true", database->getDb());

    ui->loan_book_box->setModel(model);
    ui->loan_book_box->setModelColumn(1);
}

void Add_loan::on_search_client_textChanged(const QString &text)
{
    loadClients(text);
}

void Add_loan::on_client_table_clicked(const QModelIndex &index)
{
    QSqlQueryModel* model = qobject_cast<QSqlQueryModel*>(ui->client_table->model());
    if (!model) return;

    int row = index.row();
    selectedClientId = model->data(model->index(row, 0)).toInt();
}

void Add_loan::on_loan_add_button_clicked()
{
    if (selectedClientId == -1) {
        QMessageBox::warning(this, "Błąd", "Nie wybrano klienta.");
        return;
    }

    int bookIndex = ui->loan_book_box->currentIndex();
    QSqlQueryModel* bookModel = qobject_cast<QSqlQueryModel*>(ui->loan_book_box->model());

    if (!bookModel) {
        QMessageBox::critical(this, "Błąd", "Nie można pobrać książek.");
        return;
    }

    int bookId = bookModel->data(bookModel->index(bookIndex, 0)).toInt();
    QDate loanDate = ui->loan_loan_date->date();
    QDate returnDate = ui->loan_return_date->date();

    if (returnDate <= loanDate) {
        QMessageBox::warning(this, "Błąd daty", "Data zwrotu musi być późniejsza niż data wypożyczenia.");
        return;
    }

    if (database->addLoan(selectedClientId, bookId, loanDate, returnDate)) {
        QMessageBox::information(this, "Sukces", "Dodano wypożyczenie.");

        loadBooks();
        ui->loan_book_box->setCurrentIndex(0);

        QDate today = QDate::currentDate();
        ui->loan_loan_date->setDate(today);
        ui->loan_return_date->setDate(today.addDays(1));
    } else {
        QMessageBox::warning(this, "Błąd", "Nie udało się dodać wypożyczenia.");
    }
}
