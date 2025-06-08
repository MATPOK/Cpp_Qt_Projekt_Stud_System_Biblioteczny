#ifndef ADD_CLIENT_H
#define ADD_CLIENT_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
#include <QSortFilterProxyModel>
#include "database.h"

namespace Ui {
class Add_client;
}

class Add_client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Add_client(QWidget *parent = nullptr);
    ~Add_client();

    void setDatabase(Database* db);
    void setPreviousWindow(QWidget* previous);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_PushButton_add_client_clicked();
    void on_client_delete_button_clicked();
    void on_client_history_button_clicked();
    void on_search_client_lineedit_textChanged(const QString &text);

private:
    void refreshClientTable(const QString &filter);
    void deleteSelectedClient();
    void showClientHistory();

    Ui::Add_client *ui;
    Database* database;
    QWidget* previousWindow;

    QSqlQueryModel* rawModel;
    QSortFilterProxyModel* proxyModel;
};

#endif // ADD_CLIENT_H
