#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QDate>

class Client
{
private:
    int id;
    QString first_name;
    QString last_name;
    QDate birth_date;
    QString email;
    QString phone;

public:
    Client();
    Client(const QString &first_name,
           const QString &last_name,
           const QDate &birth_date,
           const QString &email,
           const QString &phone);
    Client(const Client &other);

    int Id() const;
    QString First_name() const;
    QString Last_name() const;
    QDate Birth_date() const;
    QString Email() const;
    QString Phone() const;

    void First_name(const QString &ptr);
    void Last_name(const QString &ptr);
    void Birth_date(const QDate &ptr);
    void Email(const QString &ptr);
    void Phone(const QString &ptr);

    void SetId(int newId);
    void Write_out_Client() const;
};

#endif // CLIENT_H
