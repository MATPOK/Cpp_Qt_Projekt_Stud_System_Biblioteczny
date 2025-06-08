#ifndef WORKER_WINDOW_H
#define WORKER_WINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include "database.h"

namespace Ui {
class Worker_Window;
}

class Worker_Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Worker_Window(Database* db, QWidget* previousWindow, QWidget* parent = nullptr);
    ~Worker_Window();

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void on_pushButton_add_client_clicked();
    void on_pushButton_add_book_clicked();
    void on_pushButton_add_client_2_clicked();  // Przycisk do otwarcia Add_book
    void on_pushButton_add_loan_clicked();
    void on_pushButton_return_book_clicked();

private:
    Ui::Worker_Window* ui;
    Database* database;
    QWidget* previousWindow;
};

#endif // WORKER_WINDOW_H
