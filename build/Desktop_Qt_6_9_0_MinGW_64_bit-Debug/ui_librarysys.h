/********************************************************************************
** Form generated from reading UI file 'librarysys.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBRARYSYS_H
#define UI_LIBRARYSYS_H

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

class Ui_LibrarySys
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_worker;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LibrarySys)
    {
        if (LibrarySys->objectName().isEmpty())
            LibrarySys->setObjectName("LibrarySys");
        LibrarySys->setWindowModality(Qt::WindowModality::WindowModal);
        LibrarySys->resize(800, 600);
        LibrarySys->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::UserAvailable));
        LibrarySys->setWindowIcon(icon);
        LibrarySys->setAutoFillBackground(false);
        centralwidget = new QWidget(LibrarySys);
        centralwidget->setObjectName("centralwidget");
        pushButton_worker = new QPushButton(centralwidget);
        pushButton_worker->setObjectName("pushButton_worker");
        pushButton_worker->setGeometry(QRect(270, 290, 241, 91));
        QFont font;
        font.setFamilies({QString::fromUtf8("Verdana")});
        font.setPointSize(14);
        font.setBold(true);
        pushButton_worker->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 140, 541, 141));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Verdana")});
        font1.setPointSize(19);
        font1.setWeight(QFont::ExtraBold);
        font1.setUnderline(true);
        label->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(300, 250, 211, 16));
        LibrarySys->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LibrarySys);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        LibrarySys->setMenuBar(menubar);
        statusbar = new QStatusBar(LibrarySys);
        statusbar->setObjectName("statusbar");
        LibrarySys->setStatusBar(statusbar);

        retranslateUi(LibrarySys);

        QMetaObject::connectSlotsByName(LibrarySys);
    } // setupUi

    void retranslateUi(QMainWindow *LibrarySys)
    {
        LibrarySys->setWindowTitle(QCoreApplication::translate("LibrarySys", "LibSys", nullptr));
        pushButton_worker->setText(QCoreApplication::translate("LibrarySys", "START", nullptr));
        label->setText(QCoreApplication::translate("LibrarySys", "SYSTEM ZARZ\304\204DZANIA BIBLIOTEK\304\204", nullptr));
        label_2->setText(QCoreApplication::translate("LibrarySys", "Made by Mateusz Pokrywka 177143", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LibrarySys: public Ui_LibrarySys {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBRARYSYS_H
