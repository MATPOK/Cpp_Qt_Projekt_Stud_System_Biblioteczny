#include "return_book.h"
#include "ui_return_book.h"

Return_book::Return_book(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Return_book)
    , database(nullptr)
    , previousWindow(nullptr)
    , selectedClientId(-1)
{
    ui->setupUi(this);
}

Return_book::~Return_book()
{
    delete ui;
}

void Return_book::setDatabase(Database *db)
{
    this->database = db;
    loadClients();
}

void Return_book::setPreviousWindow(QWidget *prev)
{
    this->previousWindow = prev;
}

void Return_book::closeEvent(QCloseEvent *event)
{
    if (previousWindow) {
        previousWindow->show();
    }
    QMainWindow::closeEvent(event);
}

void Return_book::loadClients(const QString &filter)
{
    QString query = "SELECT id, first_name, last_name FROM clients";
    if (!filter.isEmpty()) {
        query += " WHERE first_name ILIKE '%" + filter + "%' OR last_name ILIKE '%" + filter + "%'";
    }

    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery(query, database->getDb());
    model->setHeaderData(1, Qt::Horizontal, "Imię");
    model->setHeaderData(2, Qt::Horizontal, "Nazwisko");

    ui->client_table->setModel(model);
    ui->client_table->hideColumn(0);
    ui->client_table->horizontalHeader()->setStretchLastSection(true);
    ui->client_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->client_table->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->client_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void Return_book::on_search_client_textChanged(const QString &text)
{
    loadClients(text);
}

void Return_book::on_client_table_clicked(const QModelIndex &index)
{
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel *>(ui->client_table->model());
    if (!model) return;

    int row = index.row();
    selectedClientId = model->data(model->index(row, 0)).toInt();
    loadLoansForClient(selectedClientId);
}

void Return_book::loadLoansForClient(int clientId)
{
    ui->return_loan_list->clear();

    QSqlQuery query(database->getDb());
    query.prepare("SELECT loans.id, books.title FROM loans "
                  "JOIN books ON loans.book_id = books.id "
                  "WHERE loans.client_id = :client_id AND loans.returned = false");
    query.bindValue(":client_id", clientId);

    if (!query.exec()) return;

    while (query.next()) {
        int loanId = query.value(0).toInt();
        QString title = query.value(1).toString();

        QListWidgetItem *item = new QListWidgetItem(title);
        item->setData(Qt::UserRole, loanId);
        item->setCheckState(Qt::Unchecked);
        ui->return_loan_list->addItem(item);
    }
}

void Return_book::on_return_button_clicked()
{
    bool anyReturned = false;
    QDate today = QDate::currentDate();

    for (int i = 0; i < ui->return_loan_list->count(); ++i) {
        QListWidgetItem *item = ui->return_loan_list->item(i);
        if (item->checkState() == Qt::Checked) {
            int loanId = item->data(Qt::UserRole).toInt();

            QSqlQuery query(database->getDb());
            query.prepare("UPDATE loans SET returned = true, return_date = :today WHERE id = :id");
            query.bindValue(":today", today);
            query.bindValue(":id", loanId);

            if (query.exec()) {
                anyReturned = true;
                database->markBookAsAvailableByLoanId(loanId);
            }
        }
    }

    if (anyReturned) {
        QMessageBox::information(this, "Sukces", "Zwrócono książkę(i).");
        if (selectedClientId != -1) {
            loadLoansForClient(selectedClientId);
        }
    } else {
        QMessageBox::information(this, "Uwaga", "Nie zaznaczono żadnych książek do zwrotu.");
    }
}
