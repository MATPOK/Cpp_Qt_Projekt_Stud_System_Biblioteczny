#ifndef RETURN_BOOK_H
#define RETURN_BOOK_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QListWidgetItem>
#include <QCloseEvent>
#include <QMessageBox>
#include <QDate>
#include "database.h"

namespace Ui {
class Return_book;
}

class Return_book : public QMainWindow
{
    Q_OBJECT

public:
    explicit Return_book(QWidget *parent = nullptr);
    ~Return_book();

    void setDatabase(Database *db);
    void setPreviousWindow(QWidget *prev);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_search_client_textChanged(const QString &text);
    void on_client_table_clicked(const QModelIndex &index);
    void on_return_button_clicked();

private:
    Ui::Return_book *ui;
    Database *database;
    QWidget *previousWindow;
    int selectedClientId;

    void loadClients(const QString &filter = "");
    void loadLoansForClient(int clientId);
};

#endif // RETURN_BOOK_H
