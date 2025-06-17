/********************************************************************************
** Form generated from reading UI file 'client_history.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_HISTORY_H
#define UI_CLIENT_HISTORY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client_history
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Client_history)
    {
        if (Client_history->objectName().isEmpty())
            Client_history->setObjectName("Client_history");
        Client_history->resize(800, 600);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::UserAvailable));
        Client_history->setWindowIcon(icon);
        centralwidget = new QWidget(Client_history);
        centralwidget->setObjectName("centralwidget");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(50, 80, 711, 481));
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana")});
        tableView->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 30, 691, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Verdana")});
        font1.setPointSize(18);
        label->setFont(font1);
        Client_history->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Client_history);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Client_history->setMenuBar(menubar);
        statusbar = new QStatusBar(Client_history);
        statusbar->setObjectName("statusbar");
        Client_history->setStatusBar(statusbar);

        retranslateUi(Client_history);

        QMetaObject::connectSlotsByName(Client_history);
    } // setupUi

    void retranslateUi(QMainWindow *Client_history)
    {
        Client_history->setWindowTitle(QCoreApplication::translate("Client_history", "LibSys", nullptr));
        label->setText(QCoreApplication::translate("Client_history", "Historia wypo\305\274ycze\305\204 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client_history: public Ui_Client_history {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_HISTORY_H
