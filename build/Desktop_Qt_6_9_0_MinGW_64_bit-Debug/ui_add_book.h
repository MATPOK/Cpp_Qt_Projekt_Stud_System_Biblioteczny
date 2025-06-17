/********************************************************************************
** Form generated from reading UI file 'add_book.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_BOOK_H
#define UI_ADD_BOOK_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Add_book
{
public:
    QWidget *centralwidget;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QLabel *label;
    QLineEdit *book_title;
    QSplitter *splitter_2;
    QLabel *label_2;
    QLineEdit *book_author;
    QSplitter *splitter_3;
    QLabel *label_3;
    QLineEdit *book_publisher;
    QSplitter *splitter_4;
    QLabel *label_4;
    QDateEdit *book_publish_date;
    QCheckBox *book_available;
    QPushButton *book_add_book;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QTableView *book_table_view;
    QPushButton *book_delete_button;
    QPushButton *book_toggle_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Add_book)
    {
        if (Add_book->objectName().isEmpty())
            Add_book->setObjectName("Add_book");
        Add_book->resize(800, 600);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::UserAvailable));
        Add_book->setWindowIcon(icon);
        centralwidget = new QWidget(Add_book);
        centralwidget->setObjectName("centralwidget");
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(550, 60, 331, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana")});
        font.setPointSize(21);
        font.setBold(true);
        label_5->setFont(font);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(420, 330, 97, 24));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Verdana")});
        font1.setBold(true);
        label_6->setFont(font1);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(420, 330, 97, 24));
        label_7->setFont(font1);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(420, 330, 98, 25));
        label_8->setFont(font1);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(420, 330, 97, 24));
        label_9->setFont(font1);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(520, 120, 271, 391));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(widget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Orientation::Horizontal);
        label = new QLabel(splitter);
        label->setObjectName("label");
        label->setFont(font1);
        splitter->addWidget(label);
        book_title = new QLineEdit(splitter);
        book_title->setObjectName("book_title");
        splitter->addWidget(book_title);

        verticalLayout->addWidget(splitter);

        splitter_2 = new QSplitter(widget);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setOrientation(Qt::Orientation::Horizontal);
        label_2 = new QLabel(splitter_2);
        label_2->setObjectName("label_2");
        label_2->setFont(font1);
        splitter_2->addWidget(label_2);
        book_author = new QLineEdit(splitter_2);
        book_author->setObjectName("book_author");
        splitter_2->addWidget(book_author);

        verticalLayout->addWidget(splitter_2);

        splitter_3 = new QSplitter(widget);
        splitter_3->setObjectName("splitter_3");
        splitter_3->setOrientation(Qt::Orientation::Horizontal);
        label_3 = new QLabel(splitter_3);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);
        splitter_3->addWidget(label_3);
        book_publisher = new QLineEdit(splitter_3);
        book_publisher->setObjectName("book_publisher");
        splitter_3->addWidget(book_publisher);

        verticalLayout->addWidget(splitter_3);

        splitter_4 = new QSplitter(widget);
        splitter_4->setObjectName("splitter_4");
        splitter_4->setOrientation(Qt::Orientation::Horizontal);
        label_4 = new QLabel(splitter_4);
        label_4->setObjectName("label_4");
        label_4->setFont(font1);
        splitter_4->addWidget(label_4);
        book_publish_date = new QDateEdit(splitter_4);
        book_publish_date->setObjectName("book_publish_date");
        splitter_4->addWidget(book_publish_date);

        verticalLayout->addWidget(splitter_4);

        book_available = new QCheckBox(widget);
        book_available->setObjectName("book_available");
        book_available->setAcceptDrops(false);
        book_available->setAutoFillBackground(true);
        book_available->setChecked(true);

        verticalLayout->addWidget(book_available);

        book_add_book = new QPushButton(widget);
        book_add_book->setObjectName("book_add_book");

        verticalLayout->addWidget(book_add_book);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(10, 70, 501, 441));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        book_table_view = new QTableView(widget1);
        book_table_view->setObjectName("book_table_view");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Verdana")});
        book_table_view->setFont(font2);

        verticalLayout_2->addWidget(book_table_view);

        book_delete_button = new QPushButton(widget1);
        book_delete_button->setObjectName("book_delete_button");
        book_delete_button->setFont(font2);

        verticalLayout_2->addWidget(book_delete_button);

        book_toggle_button = new QPushButton(widget1);
        book_toggle_button->setObjectName("book_toggle_button");
        book_toggle_button->setFont(font2);

        verticalLayout_2->addWidget(book_toggle_button);

        Add_book->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Add_book);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Add_book->setMenuBar(menubar);
        statusbar = new QStatusBar(Add_book);
        statusbar->setObjectName("statusbar");
        Add_book->setStatusBar(statusbar);

        retranslateUi(Add_book);

        QMetaObject::connectSlotsByName(Add_book);
    } // setupUi

    void retranslateUi(QMainWindow *Add_book)
    {
        Add_book->setWindowTitle(QCoreApplication::translate("Add_book", "LibSys", nullptr));
        label_5->setText(QCoreApplication::translate("Add_book", "Dodaj ksi\304\205\305\274k\304\231", nullptr));
        label_6->setText(QCoreApplication::translate("Add_book", "Autor", nullptr));
        label_7->setText(QCoreApplication::translate("Add_book", "Wydawnictwo", nullptr));
        label_8->setText(QCoreApplication::translate("Add_book", "Data wydania", nullptr));
        label_9->setText(QCoreApplication::translate("Add_book", "Tytu\305\202", nullptr));
        label->setText(QCoreApplication::translate("Add_book", "Tytu\305\202", nullptr));
        book_title->setPlaceholderText(QCoreApplication::translate("Add_book", "Tytu\305\202", nullptr));
        label_2->setText(QCoreApplication::translate("Add_book", "Autor", nullptr));
        book_author->setPlaceholderText(QCoreApplication::translate("Add_book", "Autor", nullptr));
        label_3->setText(QCoreApplication::translate("Add_book", "Wydawnictwo", nullptr));
        book_publisher->setPlaceholderText(QCoreApplication::translate("Add_book", "Wydawnictwo", nullptr));
        label_4->setText(QCoreApplication::translate("Add_book", "Data wydania", nullptr));
        book_available->setText(QCoreApplication::translate("Add_book", "dost\304\231pna", nullptr));
        book_add_book->setText(QCoreApplication::translate("Add_book", "Dodaj ksi\304\205\305\274k\304\231", nullptr));
        book_delete_button->setText(QCoreApplication::translate("Add_book", "Usu\305\204", nullptr));
        book_toggle_button->setText(QCoreApplication::translate("Add_book", "Zmie\305\204 dost\304\231pno\305\233\304\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Add_book: public Ui_Add_book {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_BOOK_H
