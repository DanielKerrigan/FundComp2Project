#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->webView->load(QUrl("http://www.jamocracy.xyz"));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_backButton_clicked()
{
    ui->webView->back();
}

void Dialog::on_forwardButton_clicked()
{
    ui->webView->forward();
}

void Dialog::on_goButton_clicked()
{
    ui->webView->load(("http://"+ui->urlEdit->text()));
    //ui->webView->
}

void Dialog::on_refreshButton_clicked()
{
    ui->webView->reload();
}

void Dialog::on_urlEdit_returnPressed()
{
    on_goButton_clicked();
}
