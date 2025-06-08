#ifndef ADD_LOAN_H
#define ADD_LOAN_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
#include <QSqlQueryModel>
#include "database.h"

namespace Ui {
class Add_loan;
}

class Add_loan : public QMainWindow
{
    Q_OBJECT

public:
    explicit Add_loan(QWidget *parent = nullptr);
    ~Add_loan();

    void setDatabase(Database* db);
    void setPreviousWindow(QWidget* prev);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_loan_add_button_clicked();
    void on_search_client_textChanged(const QString &text);
    void on_client_table_clicked(const QModelIndex &index);

private:
    void loadClients(const QString &filter = "");
    void loadBooks();

    Ui::Add_loan *ui;
    Database* database;
    QWidget* previousWindow;
    int selectedClientId;
};

#endif // ADD_LOAN_H
