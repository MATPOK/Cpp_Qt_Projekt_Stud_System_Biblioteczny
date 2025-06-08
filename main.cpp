#include "librarysys.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    LibrarySys window;
    window.show();

    return app.exec();
}
