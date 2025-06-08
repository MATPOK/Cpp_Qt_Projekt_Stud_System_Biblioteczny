#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

#include "client.h"
#include "book.h"

class Database
{
public:
    Database();

    bool openConnection();
    void closeConnection();

    QSqlDatabase getDb() const;
    QSqlTableModel* getClientsModel();

    bool addClient(const Client &client);
    bool addBook(const Book &book);
    bool addLoan(int client_id, int book_id, const QDate &loan_date, const QDate &return_date);
    bool returnLoan(int loan_id);
    void markBookAsAvailableByLoanId(int loanId);

private:
    QSqlDatabase db;
};

#endif // DATABASE_H
