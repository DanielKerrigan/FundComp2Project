#include "dialog.h"
#include <QApplication>

// Adding a comment to check if Qt commit works from git windows
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    return a.exec();
}
