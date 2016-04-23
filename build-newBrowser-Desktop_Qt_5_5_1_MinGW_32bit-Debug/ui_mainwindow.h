/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionBack;
    QAction *actionForward;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionNew_Tab;
    QAction *actionNew_Window;
    QAction *actionAdd_Bookmark;
    QAction *actionBlock_site;
    QAction *actionView_History;
    QAction *actionNew_Timer;
    QAction *actionView_Bookmarks;
    QAction *actionView_Blocked;
    QAction *actionShow_Timer_2;
    QAction *actionHide_Timer;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QPushButton *googleButton;
    QTabWidget *tabWidget;
    QWidget *tab_11;
    QLineEdit *google;
    QPushButton *refreshButton;
    QPushButton *backButton;
    QPushButton *goButton;
    QPushButton *forwardButton;
    QLineEdit *urlEdit;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHistory;
    QMenu *menuBookmarks;
    QMenu *menuBlocked;
    QMenu *menuTimer;
    QMenu *menuCurrent_Timer;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1393, 869);
        actionBack = new QAction(MainWindow);
        actionBack->setObjectName(QStringLiteral("actionBack"));
        actionForward = new QAction(MainWindow);
        actionForward->setObjectName(QStringLiteral("actionForward"));
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        actionNew_Tab = new QAction(MainWindow);
        actionNew_Tab->setObjectName(QStringLiteral("actionNew_Tab"));
        actionNew_Window = new QAction(MainWindow);
        actionNew_Window->setObjectName(QStringLiteral("actionNew_Window"));
        actionAdd_Bookmark = new QAction(MainWindow);
        actionAdd_Bookmark->setObjectName(QStringLiteral("actionAdd_Bookmark"));
        actionBlock_site = new QAction(MainWindow);
        actionBlock_site->setObjectName(QStringLiteral("actionBlock_site"));
        actionView_History = new QAction(MainWindow);
        actionView_History->setObjectName(QStringLiteral("actionView_History"));
        actionNew_Timer = new QAction(MainWindow);
        actionNew_Timer->setObjectName(QStringLiteral("actionNew_Timer"));
        actionView_Bookmarks = new QAction(MainWindow);
        actionView_Bookmarks->setObjectName(QStringLiteral("actionView_Bookmarks"));
        actionView_Blocked = new QAction(MainWindow);
        actionView_Blocked->setObjectName(QStringLiteral("actionView_Blocked"));
        actionShow_Timer_2 = new QAction(MainWindow);
        actionShow_Timer_2->setObjectName(QStringLiteral("actionShow_Timer_2"));
        actionHide_Timer = new QAction(MainWindow);
        actionHide_Timer->setObjectName(QStringLiteral("actionHide_Timer"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        googleButton = new QPushButton(centralWidget);
        googleButton->setObjectName(QStringLiteral("googleButton"));

        gridLayout_3->addWidget(googleButton, 0, 7, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_11 = new QWidget();
        tab_11->setObjectName(QStringLiteral("tab_11"));
        tabWidget->addTab(tab_11, QString());

        gridLayout_3->addWidget(tabWidget, 1, 0, 1, 6);

        google = new QLineEdit(centralWidget);
        google->setObjectName(QStringLiteral("google"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(google->sizePolicy().hasHeightForWidth());
        google->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(google, 0, 6, 1, 1);

        refreshButton = new QPushButton(centralWidget);
        refreshButton->setObjectName(QStringLiteral("refreshButton"));
        refreshButton->setStyleSheet(QLatin1String("background-image: url(:/Images/refresh.jpg);\n"
"width: 30px;"));

        gridLayout_3->addWidget(refreshButton, 0, 5, 1, 1);

        backButton = new QPushButton(centralWidget);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setStyleSheet(QLatin1String("background-image: url(:/Images/back.jpg);\n"
"width: 90px;"));

        gridLayout_3->addWidget(backButton, 0, 0, 1, 1);

        goButton = new QPushButton(centralWidget);
        goButton->setObjectName(QStringLiteral("goButton"));
        goButton->setStyleSheet(QLatin1String("background-image: url(:/Images/go.jpg);\n"
"width: 90px;"));

        gridLayout_3->addWidget(goButton, 0, 3, 1, 1);

        forwardButton = new QPushButton(centralWidget);
        forwardButton->setObjectName(QStringLiteral("forwardButton"));
        forwardButton->setStyleSheet(QLatin1String("background-image: url(:/Images/forward.jpg);\n"
"width: 90px;"));

        gridLayout_3->addWidget(forwardButton, 0, 1, 1, 1);

        urlEdit = new QLineEdit(centralWidget);
        urlEdit->setObjectName(QStringLiteral("urlEdit"));

        gridLayout_3->addWidget(urlEdit, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1393, 31));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHistory = new QMenu(menuBar);
        menuHistory->setObjectName(QStringLiteral("menuHistory"));
        menuBookmarks = new QMenu(menuBar);
        menuBookmarks->setObjectName(QStringLiteral("menuBookmarks"));
        menuBlocked = new QMenu(menuBar);
        menuBlocked->setObjectName(QStringLiteral("menuBlocked"));
        menuTimer = new QMenu(menuBar);
        menuTimer->setObjectName(QStringLiteral("menuTimer"));
        menuCurrent_Timer = new QMenu(menuTimer);
        menuCurrent_Timer->setObjectName(QStringLiteral("menuCurrent_Timer"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHistory->menuAction());
        menuBar->addAction(menuBookmarks->menuAction());
        menuBar->addAction(menuBlocked->menuAction());
        menuBar->addAction(menuTimer->menuAction());
        menuFile->addAction(actionNew_Tab);
        menuFile->addAction(actionNew_Window);
        menuEdit->addAction(actionBack);
        menuEdit->addAction(actionForward);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuHistory->addAction(actionView_History);
        menuBookmarks->addAction(actionAdd_Bookmark);
        menuBookmarks->addAction(actionView_Bookmarks);
        menuBlocked->addAction(actionBlock_site);
        menuBlocked->addAction(actionView_Blocked);
        menuTimer->addAction(actionNew_Timer);
        menuTimer->addAction(menuCurrent_Timer->menuAction());
        menuCurrent_Timer->addAction(actionShow_Timer_2);
        menuCurrent_Timer->addAction(actionHide_Timer);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionBack->setText(QApplication::translate("MainWindow", "Back", 0));
        actionForward->setText(QApplication::translate("MainWindow", "Forward", 0));
        actionCut->setText(QApplication::translate("MainWindow", "Cut", 0));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", 0));
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", 0));
        actionNew_Tab->setText(QApplication::translate("MainWindow", "New Tab", 0));
        actionNew_Window->setText(QApplication::translate("MainWindow", "New Window", 0));
        actionAdd_Bookmark->setText(QApplication::translate("MainWindow", "Add Bookmark", 0));
        actionBlock_site->setText(QApplication::translate("MainWindow", "Block site", 0));
        actionView_History->setText(QApplication::translate("MainWindow", "View History", 0));
        actionNew_Timer->setText(QApplication::translate("MainWindow", "New Timer", 0));
        actionView_Bookmarks->setText(QApplication::translate("MainWindow", "View Bookmarks", 0));
        actionView_Blocked->setText(QApplication::translate("MainWindow", "View Blocked", 0));
        actionShow_Timer_2->setText(QApplication::translate("MainWindow", "Show", 0));
        actionHide_Timer->setText(QApplication::translate("MainWindow", "Hide", 0));
        googleButton->setText(QApplication::translate("MainWindow", "Google", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_11), QApplication::translate("MainWindow", "Tab 1", 0));
        refreshButton->setText(QString());
        backButton->setText(QString());
        goButton->setText(QString());
        forwardButton->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuHistory->setTitle(QApplication::translate("MainWindow", "History", 0));
        menuBookmarks->setTitle(QApplication::translate("MainWindow", "Bookmarks", 0));
        menuBlocked->setTitle(QApplication::translate("MainWindow", "Blocked", 0));
        menuTimer->setTitle(QApplication::translate("MainWindow", "Timer", 0));
        menuCurrent_Timer->setTitle(QApplication::translate("MainWindow", "Current Timer", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
