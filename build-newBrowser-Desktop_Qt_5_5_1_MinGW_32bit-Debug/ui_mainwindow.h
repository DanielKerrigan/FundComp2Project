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
#include <QtWebKitWidgets/QWebView>
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
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *backButton;
    QPushButton *forwardButton;
    QLineEdit *urlEdit;
    QPushButton *goButton;
    QPushButton *refreshButton;
    QWebView *webView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(785, 552);
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
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        backButton = new QPushButton(centralWidget);
        backButton->setObjectName(QStringLiteral("backButton"));

        gridLayout->addWidget(backButton, 0, 0, 1, 1);

        forwardButton = new QPushButton(centralWidget);
        forwardButton->setObjectName(QStringLiteral("forwardButton"));

        gridLayout->addWidget(forwardButton, 0, 1, 1, 1);

        urlEdit = new QLineEdit(centralWidget);
        urlEdit->setObjectName(QStringLiteral("urlEdit"));

        gridLayout->addWidget(urlEdit, 0, 2, 1, 1);

        goButton = new QPushButton(centralWidget);
        goButton->setObjectName(QStringLiteral("goButton"));

        gridLayout->addWidget(goButton, 0, 3, 1, 1);

        refreshButton = new QPushButton(centralWidget);
        refreshButton->setObjectName(QStringLiteral("refreshButton"));

        gridLayout->addWidget(refreshButton, 0, 4, 1, 1);

        webView = new QWebView(centralWidget);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setUrl(QUrl(QStringLiteral("about:blank")));

        gridLayout->addWidget(webView, 1, 0, 1, 5);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 785, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionNew_Tab);
        menuFile->addAction(actionNew_Window);
        menuEdit->addAction(actionBack);
        menuEdit->addAction(actionForward);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);

        retranslateUi(MainWindow);

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
        backButton->setText(QApplication::translate("MainWindow", "<-", 0));
        forwardButton->setText(QApplication::translate("MainWindow", "->", 0));
        goButton->setText(QApplication::translate("MainWindow", "Go", 0));
        refreshButton->setText(QApplication::translate("MainWindow", "Ref", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
