#include "advisor.h"
//#include "databasemanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Advisor w;
    w.show();
    return a.exec();
}
