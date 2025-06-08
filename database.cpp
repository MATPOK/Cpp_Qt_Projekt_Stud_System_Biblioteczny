#include "database.h"

Database::Database()
{
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName("localhost");
        db.setDatabaseName("Library");
        db.setUserName("postgres");
        db.setPassword("admin");
    }
}

bool Database::openConnection()
{
    if (!db.isOpen()) {
        if (!db.open()) {
            qDebug() << "Błąd otwierania połączenia:" << db.lastError().text();
            return false;
        }
    }
    return true;
}

void Database::closeConnection()
{
    // Połączenie nie jest jawnie zamykane – można dodać db.close() jeśli wymagane
}

QSqlDatabase Database::getDb() const
{
    return db;
}

QSqlTableModel* Database::getClientsModel()
{
    QSqlTableModel* model = new QSqlTableModel();
    model->setTable("clients");
    model->select();
    return model;
}

bool Database::addClient(const Client &client)
{
    if (!db.isOpen()) {
        qDebug() << "Połączenie nie jest otwarte!";
        return false;
    }

    QSqlQuery query;
    if (!query.prepare("INSERT INTO clients (first_name, last_name, birth_date, email, phone) "
                       "VALUES (:first_name, :last_name, :birth_date, :email, :phone)")) {
        qDebug() << "Błąd PREPARE:" << query.lastError().text();
        return false;
    }

    query.bindValue(":first_name", client.First_name());
    query.bindValue(":last_name", client.Last_name());
    query.bindValue(":birth_date", client.Birth_date());
    query.bindValue(":email", client.Email());
    query.bindValue(":phone", client.Phone());

    if (!query.exec()) {
        qDebug() << "Błąd SQL:" << query.lastError().text();
        return false;
    }

    return true;
}

bool Database::addBook(const Book &book)
{
    if (!db.isOpen()) return false;

    QSqlQuery query;
    query.prepare("INSERT INTO books (title, author, publisher, publish_date, available) "
                  "VALUES (:title, :author, :publisher, :publish_date, :available)");
    query.bindValue(":title", book.Title());
    query.bindValue(":author", book.Author());
    query.bindValue(":publisher", book.Publisher());
    query.bindValue(":publish_date", book.Publish_date());
    query.bindValue(":available", book.Available());

    if (!query.exec()) {
        qDebug() << "Błąd SQL:" << query.lastError().text();
        return false;
    }

    return true;
}

bool Database::addLoan(int client_id, int book_id, const QDate &loan_date, const QDate &return_date)
{
    if (!db.isOpen()) return false;

    QSqlQuery query(db);
    query.prepare("INSERT INTO loans (client_id, book_id, loan_date, return_date, returned) "
                  "VALUES (:client_id, :book_id, :loan_date, :return_date, false)");
    query.bindValue(":client_id", client_id);
    query.bindValue(":book_id", book_id);
    query.bindValue(":loan_date", loan_date);
    query.bindValue(":return_date", return_date);

    if (!query.exec()) {
        qDebug() << "Błąd INSERT loans:" << query.lastError().text();
        return false;
    }

    QSqlQuery updateQuery(db);
    updateQuery.prepare("UPDATE books SET available = false WHERE id = :book_id");
    updateQuery.bindValue(":book_id", book_id);

    if (!updateQuery.exec()) {
        qDebug() << "Błąd UPDATE books:" << updateQuery.lastError().text();
        return false;
    }

    return true;
}

bool Database::returnLoan(int loan_id)
{
    if (!db.isOpen()) return false;

    QSqlQuery bookQuery(db);
    bookQuery.prepare("UPDATE books SET available = true "
                      "WHERE id = (SELECT book_id FROM loans WHERE id = :loan_id)");
    bookQuery.bindValue(":loan_id", loan_id);

    if (!bookQuery.exec()) {
        qDebug() << "Błąd aktualizacji książki:" << bookQuery.lastError().text();
        return false;
    }

    QSqlQuery loanQuery(db);
    loanQuery.prepare("UPDATE loans SET returned = true, return_date = CURRENT_DATE WHERE id = :loan_id");
    loanQuery.bindValue(":loan_id", loan_id);

    if (!loanQuery.exec()) {
        qDebug() << "Błąd aktualizacji wypożyczenia:" << loanQuery.lastError().text();
        return false;
    }

    return true;
}

void Database::markBookAsAvailableByLoanId(int loanId)
{
    QSqlQuery query(db);
    query.prepare("UPDATE books SET available = true "
                  "WHERE id = (SELECT book_id FROM loans WHERE id = :loanId)");
    query.bindValue(":loanId", loanId);
    query.exec();
}
