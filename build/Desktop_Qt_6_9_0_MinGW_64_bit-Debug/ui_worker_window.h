/********************************************************************************
** Form generated from reading UI file 'worker_window.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKER_WINDOW_H
#define UI_WORKER_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Worker_Window
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_add_client;
    QPushButton *pushButton_add_book;
    QPushButton *pushButton_add_loan;
    QPushButton *pushButton_return_book;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Worker_Window)
    {
        if (Worker_Window->objectName().isEmpty())
            Worker_Window->setObjectName("Worker_Window");
        Worker_Window->resize(800, 600);
        Worker_Window->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::UserAvailable));
        Worker_Window->setWindowIcon(icon);
        centralwidget = new QWidget(Worker_Window);
        centralwidget->setObjectName("centralwidget");
        pushButton_add_client = new QPushButton(centralwidget);
        pushButton_add_client->setObjectName("pushButton_add_client");
        pushButton_add_client->setGeometry(QRect(120, 280, 271, 81));
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana")});
        pushButton_add_client->setFont(font);
        pushButton_add_book = new QPushButton(centralwidget);
        pushButton_add_book->setObjectName("pushButton_add_book");
        pushButton_add_book->setGeometry(QRect(400, 280, 271, 81));
        pushButton_add_book->setFont(font);
        pushButton_add_loan = new QPushButton(centralwidget);
        pushButton_add_loan->setObjectName("pushButton_add_loan");
        pushButton_add_loan->setGeometry(QRect(120, 170, 271, 81));
        pushButton_add_loan->setFont(font);
        pushButton_return_book = new QPushButton(centralwidget);
        pushButton_return_book->setObjectName("pushButton_return_book");
        pushButton_return_book->setGeometry(QRect(400, 170, 271, 81));
        pushButton_return_book->setFont(font);
        pushButton_return_book->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 70, 361, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Verdana")});
        font1.setPointSize(24);
        font1.setBold(true);
        label->setFont(font1);
        Worker_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Worker_Window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Worker_Window->setMenuBar(menubar);
        statusbar = new QStatusBar(Worker_Window);
        statusbar->setObjectName("statusbar");
        Worker_Window->setStatusBar(statusbar);

        retranslateUi(Worker_Window);

        QMetaObject::connectSlotsByName(Worker_Window);
    } // setupUi

    void retranslateUi(QMainWindow *Worker_Window)
    {
        Worker_Window->setWindowTitle(QCoreApplication::translate("Worker_Window", "LibSys", nullptr));
        pushButton_add_client->setText(QCoreApplication::translate("Worker_Window", "Klienci", nullptr));
        pushButton_add_book->setText(QCoreApplication::translate("Worker_Window", "Ksi\304\205\305\274ki", nullptr));
        pushButton_add_loan->setText(QCoreApplication::translate("Worker_Window", "Wypo\305\274ycz", nullptr));
        pushButton_return_book->setText(QCoreApplication::translate("Worker_Window", "Zwr\303\263\304\207", nullptr));
        label->setText(QCoreApplication::translate("Worker_Window", "Panel Pracownika", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Worker_Window: public Ui_Worker_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKER_WINDOW_H
