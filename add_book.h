#ifndef ADD_BOOK_H
#define ADD_BOOK_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
#include "database.h"

namespace Ui {
class Add_book;
}

class Add_book : public QMainWindow
{
    Q_OBJECT

public:
    explicit Add_book(QWidget *parent = nullptr);
    ~Add_book();

    void setDatabase(Database* db);
    void setPreviousWindow(QWidget* previous);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_book_add_book_clicked();
    void on_book_available_checkStateChanged(const Qt::CheckState &arg1);
    void on_book_delete_button_clicked();
    void on_book_toggle_button_clicked();

private:
    void refreshBookTable();
    void deleteSelectedBook();
    void toggleBookAvailability();

    Ui::Add_book *ui;
    Database* database;
    QWidget* previousWindow;
};

#endif // ADD_BOOK_H
