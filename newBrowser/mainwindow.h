#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebView>
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
    QTimer *timer;
    QProgressBar *progressBar;
    QLineEdit *lineEdit;
    QLabel *label;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_backButton_clicked();
    void on_forwardButton_clicked();
    void on_goButton_clicked();
    void on_refreshButton_clicked();
    void on_urlEdit_returnPressed();
    void updateUrlBox();
    void on_actionBack_triggered();
    void on_actionForward_triggered();
    void on_actionNew_Tab_triggered();
    void tabSelected();
    void onTimeout();
    void onClicked();

private:
    Ui::MainWindow *ui;
    QWebView* current;
    url_collections urls;
};

#endif // MAINWINDOW_H
