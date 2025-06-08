#include "book.h"
#include <QDebug>

Book::Book()
    : id(1)
{
}

Book::Book(int id,
           const QString &title,
           const QString &author,
           const QString &publisher,
           const QDate &publish_date,
           bool available)
    : id(id),
    title(title),
    author(author),
    publisher(publisher),
    publish_date(publish_date),
    available(available)
{
}

Book::Book(const Book &other)
    : id(other.id),
    title(other.title),
    author(other.author),
    publisher(other.publisher),
    publish_date(other.publish_date),
    available(other.available)
{
}

Book::Book(const QString &title,
           const QString &author,
           const QString &publisher,
           const QDate &publish_date,
           bool available)
    : title(title),
    author(author),
    publisher(publisher),
    publish_date(publish_date),
    available(available)
{
}

int Book::Id() const
{
    return id;
}

QString Book::Title() const
{
    return title;
}

QString Book::Author() const
{
    return author;
}

QString Book::Publisher() const
{
    return publisher;
}

QDate Book::Publish_date() const
{
    return publish_date;
}

bool Book::Available() const
{
    return available;
}

void Book::Title(const QString &ptr)
{
    title = ptr;
}

void Book::Author(const QString &ptr)
{
    author = ptr;
}

void Book::Publisher(const QString &ptr)
{
    publisher = ptr;
}

void Book::Publish_date(const QDate &ptr)
{
    publish_date = ptr;
}

void Book::Available(bool ptr)
{
    available = ptr;
}

void Book::Write_out_Book() const
{
    qDebug() << id
             << title
             << author
             << publisher
             << publish_date.toString()
             << (available ? "dostępna" : "niedostępna");
}
