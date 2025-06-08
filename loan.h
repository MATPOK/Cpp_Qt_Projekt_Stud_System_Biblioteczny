#ifndef LOAN_H
#define LOAN_H

#include <QString>
#include <QDate>

class Loan
{
private:
    const int id;
    int client_id;
    int book_id;
    QDate loan_date;
    QDate return_date;
    bool returned = false;

public:
    Loan();
    Loan(int id, int client_id, int book_id, const QDate &loan_date, const QDate &return_date, bool returned = false);
    Loan(const Loan &other);

    int Id() const;
    int Client_id() const;
    int Book_id() const;
    QDate Loan_date() const;
    QDate Return_date() const;
    bool Returned() const;

    void Client_id(int ptr);
    void Book_id(int ptr);
    void Loan_date(const QDate &ptr);
    void Return_date(const QDate &ptr);
    void Returned(bool ptr);

    void Write_out_Loan() const;
};

#endif // LOAN_H
