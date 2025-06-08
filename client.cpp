#include "client.h"
#include <QDebug>

Client::Client()
    : id(0),
    first_name(""),
    last_name(""),
    birth_date(QDate::currentDate()),
    email(""),
    phone("")
{
}

Client::Client(const QString &first_name,
               const QString &last_name,
               const QDate &birth_date,
               const QString &email,
               const QString &phone)
    : id(0),
    first_name(first_name),
    last_name(last_name),
    birth_date(birth_date),
    email(email),
    phone(phone)
{
}

Client::Client(const Client &other)
    : id(other.id),
    first_name(other.first_name),
    last_name(other.last_name),
    birth_date(other.birth_date),
    email(other.email),
    phone(other.phone)
{
}

int Client::Id() const
{
    return id;
}

void Client::SetId(int newId)
{
    id = newId;
}

QString Client::First_name() const
{
    return first_name;
}

QString Client::Last_name() const
{
    return last_name;
}

QDate Client::Birth_date() const
{
    return birth_date;
}

QString Client::Email() const
{
    return email;
}

QString Client::Phone() const
{
    return phone;
}

void Client::First_name(const QString &ptr)
{
    first_name = ptr;
}

void Client::Last_name(const QString &ptr)
{
    last_name = ptr;
}

void Client::Birth_date(const QDate &ptr)
{
    birth_date = ptr;
}

void Client::Email(const QString &ptr)
{
    email = ptr;
}

void Client::Phone(const QString &ptr)
{
    phone = ptr;
}

void Client::Write_out_Client() const
{
    qDebug() << id
             << first_name
             << last_name
             << birth_date.toString()
             << email
             << phone;
}
