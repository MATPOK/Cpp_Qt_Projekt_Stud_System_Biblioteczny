#include "loan.h"
#include <QDebug>

Loan::Loan()
    : id(0)
    , client_id(0)
    , book_id(0)
    , loan_date(QDate::currentDate())
    , return_date(QDate::currentDate())
    , returned(false)
{
}

Loan::Loan(int id, int client_id, int book_id, const QDate &loan_date, const QDate &return_date, bool returned)
    : id(id)
    , client_id(client_id)
    , book_id(book_id)
    , loan_date(loan_date)
    , return_date(return_date)
    , returned(returned)
{
}

Loan::Loan(const Loan &other)
    : id(other.id)
    , client_id(other.client_id)
    , book_id(other.book_id)
    , loan_date(other.loan_date)
    , return_date(other.return_date)
    , returned(other.returned)
{
}

int Loan::Id() const
{
    return id;
}

int Loan::Client_id() const
{
    return client_id;
}

int Loan::Book_id() const
{
    return book_id;
}

QDate Loan::Loan_date() const
{
    return loan_date;
}

QDate Loan::Return_date() const
{
    return return_date;
}

bool Loan::Returned() const
{
    return returned;
}

void Loan::Client_id(int ptr)
{
    client_id = ptr;
}

void Loan::Book_id(int ptr)
{
    book_id = ptr;
}

void Loan::Loan_date(const QDate &ptr)
{
    loan_date = ptr;
}

void Loan::Return_date(const QDate &ptr)
{
    return_date = ptr;
}

void Loan::Returned(bool ptr)
{
    returned = ptr;
}

void Loan::Write_out_Loan() const
{
    qDebug() << id
             << client_id
             << book_id
             << loan_date.toString()
             << return_date.toString()
             << (returned ? "zwrócona" : "niezwrócona");
}
