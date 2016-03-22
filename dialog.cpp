#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->webView->load(QUrl("http://www.jamocracy.xyz")); // loads preset homepage
    ui->urlEdit->setText("http://www.jamocracy.xyz"); // this sets the urlEdit to display the homepage url
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

}

void Dialog::on_refreshButton_clicked()
{
    ui->webView->reload();
    ui->urlEdit->setText(ui->webView->url().toString()); //urlEdit displays current url when page is refreshed
}

void Dialog::on_urlEdit_returnPressed()
{
    on_goButton_clicked();
}
