#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void on_backButton_clicked();
    void on_forwardButton_clicked();
    void on_goButton_clicked();
    void on_refreshButton_clicked();
    void on_urlEdit_returnPressed();
    void updateUrlBox();

    void on_actionBack_triggered();

    void on_actionForward_triggered();

    void on_actionCopy_triggered();

private:
    Ui::MainWindow *ui;
    url_collections urls;
};

#endif // MAINWINDOW_H
