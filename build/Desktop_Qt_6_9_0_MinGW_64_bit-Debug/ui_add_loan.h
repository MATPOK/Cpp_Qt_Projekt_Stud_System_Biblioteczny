/********************************************************************************
** Form generated from reading UI file 'add_loan.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_LOAN_H
#define UI_ADD_LOAN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Add_loan
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *search_client;
    QTableView *client_table;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QComboBox *loan_book_box;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateEdit *loan_loan_date;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDateEdit *loan_return_date;
    QPushButton *loan_add_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Add_loan)
    {
        if (Add_loan->objectName().isEmpty())
            Add_loan->setObjectName("Add_loan");
        Add_loan->resize(800, 600);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::UserAvailable));
        Add_loan->setWindowIcon(icon);
        centralwidget = new QWidget(Add_loan);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 150, 361, 231));
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana")});
        widget->setFont(font);
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        search_client = new QLineEdit(widget);
        search_client->setObjectName("search_client");
        search_client->setFont(font);

        verticalLayout->addWidget(search_client);

        client_table = new QTableView(widget);
        client_table->setObjectName("client_table");
        client_table->setFont(font);

        verticalLayout->addWidget(client_table);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(390, 180, 271, 151));
        widget1->setFont(font);
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        loan_book_box = new QComboBox(widget1);
        loan_book_box->setObjectName("loan_book_box");
        loan_book_box->setFont(font);

        verticalLayout_2->addWidget(loan_book_box);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget1);
        label->setObjectName("label");
        label->setFont(font);

        horizontalLayout->addWidget(label);

        loan_loan_date = new QDateEdit(widget1);
        loan_loan_date->setObjectName("loan_loan_date");
        loan_loan_date->setFont(font);

        horizontalLayout->addWidget(loan_loan_date);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(widget1);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        loan_return_date = new QDateEdit(widget1);
        loan_return_date->setObjectName("loan_return_date");
        loan_return_date->setFont(font);

        horizontalLayout_2->addWidget(loan_return_date);


        verticalLayout_2->addLayout(horizontalLayout_2);

        loan_add_button = new QPushButton(widget1);
        loan_add_button->setObjectName("loan_add_button");
        loan_add_button->setFont(font);

        verticalLayout_2->addWidget(loan_add_button);

        Add_loan->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Add_loan);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Add_loan->setMenuBar(menubar);
        statusbar = new QStatusBar(Add_loan);
        statusbar->setObjectName("statusbar");
        Add_loan->setStatusBar(statusbar);

        retranslateUi(Add_loan);

        QMetaObject::connectSlotsByName(Add_loan);
    } // setupUi

    void retranslateUi(QMainWindow *Add_loan)
    {
        Add_loan->setWindowTitle(QCoreApplication::translate("Add_loan", "LibSys", nullptr));
        search_client->setPlaceholderText(QCoreApplication::translate("Add_loan", "Wyszukaj", nullptr));
        loan_book_box->setPlaceholderText(QCoreApplication::translate("Add_loan", "Wybierz ksi\304\205\305\274k\304\231", nullptr));
        label->setText(QCoreApplication::translate("Add_loan", "Data wypo\305\274yczenia", nullptr));
        label_2->setText(QCoreApplication::translate("Add_loan", "Data zwrotu", nullptr));
        loan_add_button->setText(QCoreApplication::translate("Add_loan", "Wypo\305\274ycz", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Add_loan: public Ui_Add_loan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_LOAN_H
