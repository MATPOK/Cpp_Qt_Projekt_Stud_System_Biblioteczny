/********************************************************************************
** Form generated from reading UI file 'return_book.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RETURN_BOOK_H
#define UI_RETURN_BOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Return_book
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *search_client;
    QTableView *client_table;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QListWidget *return_loan_list;
    QPushButton *return_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Return_book)
    {
        if (Return_book->objectName().isEmpty())
            Return_book->setObjectName("Return_book");
        Return_book->resize(800, 600);
        centralwidget = new QWidget(Return_book);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 130, 361, 231));
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana")});
        layoutWidget->setFont(font);
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        search_client = new QLineEdit(layoutWidget);
        search_client->setObjectName("search_client");
        search_client->setFont(font);

        verticalLayout->addWidget(search_client);

        client_table = new QTableView(layoutWidget);
        client_table->setObjectName("client_table");
        client_table->setFont(font);

        verticalLayout->addWidget(client_table);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(460, 130, 311, 251));
        widget->setFont(font);
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        return_loan_list = new QListWidget(widget);
        return_loan_list->setObjectName("return_loan_list");
        return_loan_list->setFont(font);

        verticalLayout_2->addWidget(return_loan_list);

        return_button = new QPushButton(widget);
        return_button->setObjectName("return_button");
        return_button->setFont(font);

        verticalLayout_2->addWidget(return_button);

        Return_book->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Return_book);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Return_book->setMenuBar(menubar);
        statusbar = new QStatusBar(Return_book);
        statusbar->setObjectName("statusbar");
        Return_book->setStatusBar(statusbar);

        retranslateUi(Return_book);

        QMetaObject::connectSlotsByName(Return_book);
    } // setupUi

    void retranslateUi(QMainWindow *Return_book)
    {
        Return_book->setWindowTitle(QCoreApplication::translate("Return_book", "LibSys", nullptr));
        search_client->setPlaceholderText(QCoreApplication::translate("Return_book", "Wyszukaj", nullptr));
        return_button->setText(QCoreApplication::translate("Return_book", "Zwr\303\263\304\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Return_book: public Ui_Return_book {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RETURN_BOOK_H
