#include "worker_window.h"
#include "ui_worker_window.h"

#include "add_client.h"
#include "add_book.h"
#include "add_loan.h"
#include "return_book.h"

Worker_Window::Worker_Window(Database* db, QWidget* previousWindow, QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::Worker_Window)
    , database(db)
    , previousWindow(previousWindow)
{
    ui->setupUi(this);
}

Worker_Window::~Worker_Window()
{
    delete ui;
}

void Worker_Window::on_pushButton_add_client_clicked()
{
    this->hide();
    Add_client* addClientWin = new Add_client(this);
    addClientWin->setDatabase(database);
    addClientWin->setPreviousWindow(this);
    addClientWin->show();
}

void Worker_Window::on_pushButton_add_book_clicked()
{
    this->hide();
    Add_book* addBookWin = new Add_book(this);
    addBookWin->setDatabase(database);
    addBookWin->setPreviousWindow(this);
    addBookWin->show();
}

void Worker_Window::on_pushButton_add_client_2_clicked()
{
    this->hide();
    Add_book* addBookWin = new Add_book(this);
    addBookWin->setDatabase(database);
    addBookWin->setPreviousWindow(this);
    addBookWin->show();
}

void Worker_Window::on_pushButton_add_loan_clicked()
{
    this->hide();
    Add_loan* addLoanWin = new Add_loan(this);
    addLoanWin->setDatabase(database);
    addLoanWin->setPreviousWindow(this);
    addLoanWin->show();
}

void Worker_Window::on_pushButton_return_book_clicked()
{
    this->hide();
    Return_book* returnBookWin = new Return_book(this);
    returnBookWin->setDatabase(database);
    returnBookWin->setPreviousWindow(this);
    returnBookWin->show();
}

void Worker_Window::closeEvent(QCloseEvent* event)
{
    if (previousWindow) {
        previousWindow->show();
    }
    QMainWindow::closeEvent(event);
}
