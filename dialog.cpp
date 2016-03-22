#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    // loads preset homepage
    ui->webView->load(QUrl("http://www.google.com"));
    // this sets the urlEdit to display the homepage url
    ui->urlEdit->setText("http://www.google.com");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_backButton_clicked()
{
    ui->webView->back();
    //put correct url in urlEdit box - not working right now
    //ui->urlEdit->setText(ui->webView->history()->backItem().url().toString());
}

void Dialog::on_forwardButton_clicked()
{
    ui->webView->forward();

}

void Dialog::on_goButton_clicked()
{
    ui->webView->load((ui->urlEdit->text()));

}

void Dialog::on_refreshButton_clicked()
{
    ui->webView->reload();
    //urlEdit displays current url when page is refreshed
    ui->urlEdit->setText(ui->webView->url().toString());
}

void Dialog::on_urlEdit_returnPressed()
{
    on_goButton_clicked();
}
