#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Q_INIT_RESOURCE(resources);

    MainWindow window;
    window.setWindowTitle("Enter your age");

    window.show();

    return app.exec();
}
