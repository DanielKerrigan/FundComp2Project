#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebView>
#include <QWebHistory>
#include <QApplication>
#include <QVBoxLayout>
#include <QTimer>
#include <QProgressBar>
#include <QLineEdit>
#include <QMessageBox>
#include <QDebug>
#include <QPushButton>
#include <QLCDNumber>
#include <QLabel>
#include <QTime>
#include <string>
#include "url_collections.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    // helper method to change page's HTML
    void setHTML(QString html, QString tabName, QString urlBox);
    // Window Buttons
    void on_backButton_clicked();
    void on_forwardButton_clicked();
    void on_goButton_clicked();
    void on_refreshButton_clicked();
    void on_urlEdit_returnPressed();
    void updateUrlBox();
    void tabSelected();
    void onTimeout();
    void onClicked();
    void on_googleButton_clicked();
    void on_google_returnPressed();
    void on_actionRemove_Bookmark_triggered();
    void on_actionRemove_Blocked_triggered();
    void on_actionClose_Tab_triggered();
    void on_actionClose_Window_triggered();
    void on_closeTab_pressed();
    void on_newTab_pressed();
    
    // Menus
        // File
        void on_actionNew_Tab_triggered();
        // Edit
        void on_actionBack_triggered();
        void on_actionForward_triggered();
        // History
        void on_actionView_History_triggered();
        // Bookmarks
        void on_actionAdd_Bookmark_triggered();
        void on_actionView_Bookmarks_triggered();
        // Blocked
        void on_actionBlock_site_triggered();
        void on_actionView_Blocked_triggered();
        // Timer
        void on_actionNew_Timer_triggered();
        void on_actionShow_Timer_2_triggered();
        void on_actionHide_Timer_triggered();

private:
    Ui::MainWindow *ui;
    QWebView* current; // the current web view that is being displayed
    url_collections urls; // contains history, bookmarks, and blocked sites
    // Timer:
    QTimer *timer;
    QProgressBar *progressBar;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *start_button;
    QVBoxLayout *vlayout;
    QHBoxLayout *hlayout1;
    QWidget *wrapper;
    QLabel *input_label;
    int currentNumOfTabs;
};

#endif // MAINWINDOW_H
