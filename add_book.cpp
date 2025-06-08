#include "add_book.h"
#include "ui_add_book.h"
#include "book.h"

Add_book::Add_book(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Add_book)
    , database(nullptr)
    , previousWindow(nullptr)
{
    ui->setupUi(this);
}

Add_book::~Add_book()
{
    delete ui;
}

void Add_book::setDatabase(Database* db)
{
    this->database = db;
    refreshBookTable();
}

void Add_book::setPreviousWindow(QWidget* previous)
{
    this->previousWindow = previous;
}

void Add_book::closeEvent(QCloseEvent *event)
{
    if (previousWindow)
        previousWindow->show();
    QMainWindow::closeEvent(event);
}

void Add_book::on_book_add_book_clicked()
{
    QString title     = ui->book_title->text().trimmed();
    QString author    = ui->book_author->text().trimmed();
    QString publisher = ui->book_publisher->text().trimmed();
    QDate date        = ui->book_publish_date->date();
    bool available    = ui->book_available->isChecked();

    if (title.isEmpty() || author.isEmpty() || publisher.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Wszystkie pola muszą być wypełnione.");
        return;
    }

    if (date > QDate::currentDate()) {
        QMessageBox::warning(this, "Błąd", "Data publikacji nie może być z przyszłości.");
        return;
    }

    Book book(title, author, publisher, date, available);

    if (!database->openConnection()) {
        QMessageBox::critical(this, "Błąd", "Nie udało się połączyć z bazą.");
        return;
    }

    if (database->addBook(book)) {
        QMessageBox::information(this, "Sukces", "Dodano książkę.");

        ui->book_title->clear();
        ui->book_author->clear();
        ui->book_publisher->clear();
        ui->book_publish_date->setDate(QDate(2020, 1, 1));
        ui->book_available->setChecked(false);
        ui->book_available->setText("niedostępna");
    } else {
        QMessageBox::warning(this, "Błąd", "Nie udało się dodać książki.");
    }

    refreshBookTable();
}

void Add_book::on_book_available_checkStateChanged(const Qt::CheckState &arg1)
{
    ui->book_available->setText(arg1 == Qt::Checked ? "dostępna" : "niedostępna");
}

void Add_book::refreshBookTable()
{
    if (!database || !database->getDb().isOpen()) return;

    QSqlTableModel* model = new QSqlTableModel(this, database->getDb());
    model->setTable("books");
    model->select();

    model->setHeaderData(1, Qt::Horizontal, "Tytuł");
    model->setHeaderData(2, Qt::Horizontal, "Autor");
    model->setHeaderData(3, Qt::Horizontal, "Wydawnictwo");
    model->setHeaderData(4, Qt::Horizontal, "Data");
    model->setHeaderData(5, Qt::Horizontal, "Dostępność");

    ui->book_table_view->setModel(model);
    ui->book_table_view->resizeColumnsToContents();
    ui->book_table_view->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->book_table_view->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->book_table_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->book_table_view->setSortingEnabled(true);
}

void Add_book::deleteSelectedBook()
{
    auto selection = ui->book_table_view->selectionModel();
    if (!selection->hasSelection()) {
        QMessageBox::warning(this, "Brak zaznaczenia", "Zaznacz książkę do usunięcia.");
        return;
    }

    QModelIndex viewIndex  = selection->selectedRows().first();
    QModelIndex modelIndex = ui->book_table_view->model()->index(viewIndex.row(), 0);
    int bookId             = ui->book_table_view->model()->data(modelIndex).toInt();

    QSqlQuery query(database->getDb());
    query.prepare("DELETE FROM books WHERE id = :id");
    query.bindValue(":id", bookId);

    if (query.exec()) {
        QMessageBox::information(this, "Sukces", "Usunięto książkę.");
        refreshBookTable();
    } else {
        QMessageBox::warning(this, "Błąd", "Nie udało się usunąć książki.");
    }
}

void Add_book::toggleBookAvailability()
{
    auto selection = ui->book_table_view->selectionModel();
    if (!selection->hasSelection()) {
        QMessageBox::warning(this, "Brak zaznaczenia", "Zaznacz książkę.");
        return;
    }

    int row               = selection->selectedRows().first().row();
    auto model            = ui->book_table_view->model();
    int bookId            = model->data(model->index(row, 0)).toInt();
    bool currentAvailable = model->data(model->index(row, 5)).toBool();

    QSqlQuery query(database->getDb());
    query.prepare("UPDATE books SET available = :a WHERE id = :id");
    query.bindValue(":a", !currentAvailable);
    query.bindValue(":id", bookId);

    if (query.exec()) {
        QMessageBox::information(this, "Sukces", "Zmieniono dostępność książki.");
        refreshBookTable();
    } else {
        QMessageBox::warning(this, "Błąd", "Nie udało się zmienić dostępności.");
    }
}

void Add_book::on_book_delete_button_clicked()
{
    deleteSelectedBook();
}

void Add_book::on_book_toggle_button_clicked()
{
    toggleBookAvailability();
}
