QT       += core gui sql widgets
TARGET = LibrarySys
CONFIG += C++17

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_book.cpp \
    add_client.cpp \
    add_loan.cpp \
    book.cpp \
    client.cpp \
    client_history.cpp \
    database.cpp \
    loan.cpp \
    main.cpp \
    librarysys.cpp \
    return_book.cpp \
    worker_window.cpp

HEADERS += \
    add_book.h \
    add_client.h \
    add_loan.h \
    book.h \
    client.h \
    client_history.h \
    database.h \
    librarysys.h \
    loan.h \
    return_book.h \
    worker_window.h

FORMS += \
    add_book.ui \
    add_client.ui \
    add_loan.ui \
    client_history.ui \
    librarysys.ui \
    return_book.ui \
    worker_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
