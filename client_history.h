#ifndef CLIENT_HISTORY_H
#define CLIENT_HISTORY_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include "database.h"

namespace Ui {
class Client_history;
}

class Client_history : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client_history(QWidget *parent = nullptr);
    ~Client_history();

    void setDatabase(Database* db);
    void setClientId(int id);
    void setClientName(const QString &firstName, const QString &lastName);

private:
    Ui::Client_history *ui;
    Database* database;
    int clientId;
    QString clientFirstName;
    QString clientLastName;

    void loadLoanHistory();
};

#endif // CLIENT_HISTORY_H
