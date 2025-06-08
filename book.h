#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QDate>

class Book
{
private:
    int id;
    QString title;
    QString author;
    QString publisher;
    QDate publish_date;
    bool available = true;

public:
    Book();
    Book(int id,
         const QString &title,
         const QString &author,
         const QString &publisher,
         const QDate &publish_date,
         bool available = true);

    Book(const Book &other);

    Book(const QString &title,
         const QString &author,
         const QString &publisher,
         const QDate &publish_date,
         bool available);

    int Id() const;
    QString Title() const;
    QString Author() const;
    QString Publisher() const;
    QDate Publish_date() const;
    bool Available() const;

    void Title(const QString &ptr);
    void Author(const QString &ptr);
    void Publisher(const QString &ptr);
    void Publish_date(const QDate &ptr);
    void Available(bool ptr);

    void Write_out_Book() const;
};

#endif // BOOK_H
