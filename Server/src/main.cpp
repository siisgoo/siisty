#include <QApplication>

#include "GUI.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Settings settings;

    GUI w(settings);

    w.show();
    return a.exec();
}
