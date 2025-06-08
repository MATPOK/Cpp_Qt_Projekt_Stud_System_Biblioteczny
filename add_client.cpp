#include "add_client.h"
#include "ui_add_client.h"
#include "client.h"
#include "client_history.h"

Add_client::Add_client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Add_client)
    , database(nullptr)
    , previousWindow(nullptr)
    , rawModel(nullptr)
    , proxyModel(nullptr)
{
    ui->setupUi(this);
}

Add_client::~Add_client()
{
    delete ui;
}

void Add_client::setDatabase(Database* db)
{
    this->database = db;
    refreshClientTable("");
}

void Add_client::setPreviousWindow(QWidget* previous)
{
    this->previousWindow = previous;
}

void Add_client::closeEvent(QCloseEvent *event)
{
    if (previousWindow)
        previousWindow->show();
    QMainWindow::closeEvent(event);
}

void Add_client::on_PushButton_add_client_clicked()
{
    QString name      = ui->client_first_name->text().trimmed();
    QString surname   = ui->client_last_name->text().trimmed();
    QDate birthdate   = ui->client_date_of_birth->date();
    QString email     = ui->client_email->text().trimmed();
    QString phone     = ui->client_phone->text().trimmed();

    if (name.isEmpty() || surname.isEmpty() || email.isEmpty() || phone.isEmpty()) {
        QMessageBox::warning(this, "Błąd", "Wszystkie pola muszą być wypełnione.");
        return;
    }

    QRegularExpression emailRegex(R"(^\S+@\S+$)");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Błąd", "Niepoprawny adres e-mail.");
        return;
    }

    QSqlQuery checkQuery(database->getDb());
    checkQuery.prepare("SELECT COUNT(*) FROM clients WHERE email = :email");
    checkQuery.bindValue(":email", email);
    if (!checkQuery.exec() || !checkQuery.next()) {
        QMessageBox::warning(this, "Błąd", "Nie udało się sprawdzić dostępności e-maila.");
        return;
    }

    if (checkQuery.value(0).toInt() > 0) {
        QMessageBox::warning(this, "Błąd", "Podany adres e-mail już istnieje w bazie.");
        return;
    }

    Client client(name, surname, birthdate, email, phone);

    if (!database->openConnection()) {
        QMessageBox::critical(this, "Błąd", "Nie udało się połączyć z bazą danych.");
        return;
    }

    if (database->addClient(client)) {
        QMessageBox::information(this, "Sukces", "Klient został dodany.");

        ui->client_first_name->clear();
        ui->client_last_name->clear();
        ui->client_email->clear();
        ui->client_phone->clear();
        ui->client_date_of_birth->setDate(QDate(2000, 1, 1));

        refreshClientTable("");
    } else {
        QMessageBox::warning(this, "Błąd", "Nie udało się dodać klienta.");
    }
}

void Add_client::refreshClientTable(const QString& filter)
{
    if (!database || !database->getDb().isOpen()) return;

    QString query = "SELECT * FROM clients";
    if (!filter.isEmpty()) {
        query += " WHERE first_name ILIKE '%" + filter + "%' OR last_name ILIKE '%" + filter + "%'";
    }

    delete rawModel;
    rawModel = new QSqlQueryModel(this);
    rawModel->setQuery(query, database->getDb());

    rawModel->setHeaderData(1, Qt::Horizontal, "Imię");
    rawModel->setHeaderData(2, Qt::Horizontal, "Nazwisko");
    rawModel->setHeaderData(4, Qt::Horizontal, "Email");
    rawModel->setHeaderData(5, Qt::Horizontal, "Telefon");
    rawModel->setHeaderData(3, Qt::Horizontal, "Data ur.");

    delete proxyModel;
    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(rawModel);
    proxyModel->setSortCaseSensitivity(Qt::CaseInsensitive);

    ui->client_table_view->setModel(proxyModel);
    ui->client_table_view->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->client_table_view->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->client_table_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->client_table_view->setSortingEnabled(true);
    ui->client_table_view->resizeColumnsToContents();
}

void Add_client::deleteSelectedClient()
{
    auto selection = ui->client_table_view->selectionModel();
    if (!selection->hasSelection()) {
        QMessageBox::warning(this, "Brak zaznaczenia", "Zaznacz klienta do usunięcia.");
        return;
    }

    int row = selection->selectedRows().first().row();
    auto model = ui->client_table_view->model();
    int clientId = model->data(model->index(row, 0)).toInt();

    QSqlQuery query(database->getDb());
    query.prepare("SELECT COUNT(*) FROM loans WHERE client_id = :id AND returned = false");
    query.bindValue(":id", clientId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Błąd", "Nie udało się sprawdzić wypożyczeń klienta.");
        return;
    }

    query.next();
    int activeLoans = query.value(0).toInt();

    if (activeLoans > 0) {
        QMessageBox::warning(this, "Nie można usunąć", "Klient ma aktywne wypożyczenia.");
        return;
    }

    QSqlQuery deleteLoansQuery(database->getDb());
    deleteLoansQuery.prepare("DELETE FROM loans WHERE client_id = :id");
    deleteLoansQuery.bindValue(":id", clientId);

    if (!deleteLoansQuery.exec()) {
        QMessageBox::warning(this, "Błąd", "Nie udało się usunąć historii wypożyczeń.");
        return;
    }

    query.prepare("DELETE FROM clients WHERE id = :id");
    query.bindValue(":id", clientId);

    if (query.exec()) {
        QMessageBox::information(this, "Sukces", "Usunięto klienta.");
        refreshClientTable("");
    } else {
        QMessageBox::warning(this, "Błąd", "Nie udało się usunąć klienta.");
    }
}

void Add_client::showClientHistory()
{
    auto selection = ui->client_table_view->selectionModel();
    if (!selection->hasSelection()) {
        QMessageBox::warning(this, "Brak zaznaczenia", "Zaznacz klienta.");
        return;
    }

    int row = selection->selectedRows().first().row();
    auto model = ui->client_table_view->model();
    int clientId = model->data(model->index(row, 0)).toInt();
    QString firstName = model->data(model->index(row, 1)).toString();
    QString lastName  = model->data(model->index(row, 2)).toString();

    Client_history* historyWindow = new Client_history(this);
    historyWindow->setDatabase(database);
    historyWindow->setClientId(clientId);
    historyWindow->setClientName(firstName, lastName);
    historyWindow->show();
}

void Add_client::on_client_delete_button_clicked()
{
    deleteSelectedClient();
}

void Add_client::on_client_history_button_clicked()
{
    showClientHistory();
}

void Add_client::on_search_client_lineedit_textChanged(const QString& text)
{
    refreshClientTable(text);
}
