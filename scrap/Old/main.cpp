#include "dialog.h"
#include <QApplication>

// Adding a comment to check if Qt commit works from git windows

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
#if defined(Q_OS_SYMBIAN)
    w.showMaximized();
#else
    w.show();
#endif

    return a.exec();
}
