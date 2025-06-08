#include "librarysys.h"
#include "ui_librarysys.h"
#include "Worker_Window.h"
#include <QMessageBox>

LibrarySys::LibrarySys(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LibrarySys)
{
    ui->setupUi(this);

    if (!db.openConnection()) {
        QMessageBox::critical(this, "Błąd połączenia",
                              "Nie można połączyć z bazą danych.");
    }
}

LibrarySys::~LibrarySys()
{
    delete ui;
}

void LibrarySys::on_pushButton_worker_clicked()
{
    this->hide();
    Worker_Window *worker_win = new Worker_Window(&db, this);
    worker_win->show();
}
