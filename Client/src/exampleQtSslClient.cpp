#include <QApplication>
#include "gui.hpp"

int main(int argc, char* argv[])
    {
    QApplication app(argc, argv);
	userInterface theUserInterface(NULL);
	theUserInterface.show();
    return app.exec();
    }
