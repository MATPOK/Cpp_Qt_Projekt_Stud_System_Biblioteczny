#include "client_history.h"
#include "ui_client_history.h"

Client_history::Client_history(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Client_history)
    , database(nullptr)
    , clientId(-1)
{
    ui->setupUi(this);
}

Client_history::~Client_history()
{
    delete ui;
}

void Client_history::setDatabase(Database *db)
{
    this->database = db;
}

void Client_history::setClientId(int id)
{
    this->clientId = id;
    loadLoanHistory();
}

void Client_history::setClientName(const QString &firstName, const QString &lastName)
{
    clientFirstName = firstName;
    clientLastName = lastName;

    if (ui && ui->label) {
        ui->label->setText(
            QString("Historia wypożyczeń: %1 %2").arg(clientFirstName, clientLastName));
    }
}

void Client_history::loadLoanHistory()
{
    if (!database || clientId == -1) return;

    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery(
        QString(
            "SELECT books.title AS \"Tytuł\", "
            "loans.loan_date AS \"Data wypożyczenia\", "
            "loans.return_date AS \"Planowany zwrot\", "
            "loans.returned AS \"Zwrócono\" "
            "FROM loans "
            "JOIN books ON loans.book_id = books.id "
            "WHERE loans.client_id = %1")
            .arg(clientId),
        database->getDb()
        );

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}
