#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QWebView>
#include <QWebHistory>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_backButton_clicked();

    void on_forwardButton_clicked();

    void on_goButton_clicked();

    void on_refreshButton_clicked();

    void on_urlEdit_returnPressed();

    void updateUrlBox();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
