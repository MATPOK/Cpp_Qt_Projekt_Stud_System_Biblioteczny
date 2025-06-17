/********************************************************************************
** Form generated from reading UI file 'add_client.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_CLIENT_H
#define UI_ADD_CLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
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

class Ui_Add_client
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *client_first_name;
    QLineEdit *client_last_name;
    QLabel *label_3;
    QLineEdit *client_email;
    QLabel *label_4;
    QDateEdit *client_date_of_birth;
    QLabel *label_5;
    QLineEdit *client_phone;
    QPushButton *PushButton_add_client;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *search_client_lineedit;
    QVBoxLayout *verticalLayout_3;
    QTableView *client_table_view;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *client_delete_button;
    QPushButton *client_history_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Add_client)
    {
        if (Add_client->objectName().isEmpty())
            Add_client->setObjectName("Add_client");
        Add_client->resize(800, 600);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::UserAvailable));
        Add_client->setWindowIcon(icon);
        centralwidget = new QWidget(Add_client);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(520, 100, 261, 301));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana")});
        font.setPointSize(21);
        font.setBold(true);
        label_6->setFont(font);

        verticalLayout_2->addWidget(label_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");

        formLayout->setLayout(3, QFormLayout::ItemRole::LabelRole, horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");

        formLayout->setLayout(5, QFormLayout::ItemRole::LabelRole, horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label = new QLabel(widget);
        label->setObjectName("label");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Verdana")});
        font1.setBold(true);
        label->setFont(font1);

        horizontalLayout_4->addWidget(label);


        formLayout->setLayout(6, QFormLayout::ItemRole::LabelRole, horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");

        formLayout->setLayout(7, QFormLayout::ItemRole::LabelRole, horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);


        formLayout->setLayout(0, QFormLayout::ItemRole::LabelRole, horizontalLayout);

        client_first_name = new QLineEdit(widget);
        client_first_name->setObjectName("client_first_name");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, client_first_name);

        client_last_name = new QLineEdit(widget);
        client_last_name->setObjectName("client_last_name");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, client_last_name);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        client_email = new QLineEdit(widget);
        client_email->setObjectName("client_email");

        formLayout->setWidget(6, QFormLayout::ItemRole::FieldRole, client_email);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setFont(font1);

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_4);

        client_date_of_birth = new QDateEdit(widget);
        client_date_of_birth->setObjectName("client_date_of_birth");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, client_date_of_birth);

        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setFont(font1);

        formLayout->setWidget(8, QFormLayout::ItemRole::LabelRole, label_5);

        client_phone = new QLineEdit(widget);
        client_phone->setObjectName("client_phone");

        formLayout->setWidget(8, QFormLayout::ItemRole::FieldRole, client_phone);


        verticalLayout->addLayout(formLayout);

        PushButton_add_client = new QPushButton(widget);
        PushButton_add_client->setObjectName("PushButton_add_client");

        verticalLayout->addWidget(PushButton_add_client);


        verticalLayout_2->addLayout(verticalLayout);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(0, 60, 511, 401));
        verticalLayout_4 = new QVBoxLayout(widget1);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        search_client_lineedit = new QLineEdit(widget1);
        search_client_lineedit->setObjectName("search_client_lineedit");

        verticalLayout_4->addWidget(search_client_lineedit);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        client_table_view = new QTableView(widget1);
        client_table_view->setObjectName("client_table_view");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Verdana")});
        client_table_view->setFont(font2);

        verticalLayout_3->addWidget(client_table_view);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        client_delete_button = new QPushButton(widget1);
        client_delete_button->setObjectName("client_delete_button");
        client_delete_button->setFont(font2);

        horizontalLayout_6->addWidget(client_delete_button);

        client_history_button = new QPushButton(widget1);
        client_history_button->setObjectName("client_history_button");
        client_history_button->setFont(font2);

        horizontalLayout_6->addWidget(client_history_button);


        verticalLayout_3->addLayout(horizontalLayout_6);


        verticalLayout_4->addLayout(verticalLayout_3);

        Add_client->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Add_client);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Add_client->setMenuBar(menubar);
        statusbar = new QStatusBar(Add_client);
        statusbar->setObjectName("statusbar");
        Add_client->setStatusBar(statusbar);

        retranslateUi(Add_client);

        QMetaObject::connectSlotsByName(Add_client);
    } // setupUi

    void retranslateUi(QMainWindow *Add_client)
    {
        Add_client->setWindowTitle(QCoreApplication::translate("Add_client", "LibSys", nullptr));
        label_6->setText(QCoreApplication::translate("Add_client", "DODAJ KLIENTA", nullptr));
        label->setText(QCoreApplication::translate("Add_client", "Email", nullptr));
        label_2->setText(QCoreApplication::translate("Add_client", "Imie", nullptr));
        client_first_name->setPlaceholderText(QCoreApplication::translate("Add_client", "Imie", nullptr));
        client_last_name->setPlaceholderText(QCoreApplication::translate("Add_client", "Nazwisko", nullptr));
        label_3->setText(QCoreApplication::translate("Add_client", "Nazwisko", nullptr));
        client_email->setPlaceholderText(QCoreApplication::translate("Add_client", "Email", nullptr));
        label_4->setText(QCoreApplication::translate("Add_client", "Data urodzenia", nullptr));
        label_5->setText(QCoreApplication::translate("Add_client", "Tel.", nullptr));
        client_phone->setPlaceholderText(QCoreApplication::translate("Add_client", "Numer telefonu", nullptr));
        PushButton_add_client->setText(QCoreApplication::translate("Add_client", "Dodaj klienta", nullptr));
        search_client_lineedit->setPlaceholderText(QCoreApplication::translate("Add_client", "Wyszukaj", nullptr));
        client_delete_button->setText(QCoreApplication::translate("Add_client", "Usu\305\204", nullptr));
        client_history_button->setText(QCoreApplication::translate("Add_client", "Historia", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Add_client: public Ui_Add_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_CLIENT_H
