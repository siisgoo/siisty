#include <QApplication>

#include "Controller.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Settings settings;

    Controller w(settings);

    w.show();
    return a.exec();
}
