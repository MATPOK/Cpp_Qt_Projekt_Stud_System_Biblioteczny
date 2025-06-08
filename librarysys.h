#ifndef LIBRARYSYS_H
#define LIBRARYSYS_H

#include <QMainWindow>
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class LibrarySys;
}
QT_END_NAMESPACE

class LibrarySys : public QMainWindow
{
    Q_OBJECT

public:
    explicit LibrarySys(QWidget *parent = nullptr);
    ~LibrarySys();

private slots:
    void on_pushButton_worker_clicked();

private:
    Ui::LibrarySys *ui;
    Database db;

    void setupDatabase();
};

#endif // LIBRARYSYS_H
