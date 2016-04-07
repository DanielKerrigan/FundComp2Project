#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog){
    ui->setupUi(this);
    // loads preset homepage
    ui->webView->load(QUrl("http://www.google.com"));
    connect(ui->webView, SIGNAL(urlChanged(const QUrl &)), this, SLOT(updateUrlBox()));
}

Dialog::~Dialog(){
    delete ui;
}
// Go back a page when the back button is clicked
void Dialog::on_backButton_clicked(){
    ui->webView->back();
}
// Go forward a page when the forward button is clicked
void Dialog::on_forwardButton_clicked(){
    ui->webView->forward();
}
// Load the URL in the URL Edit Box when go is clicked
void Dialog::on_goButton_clicked(){
    ui->webView->load((ui->urlEdit->text()));
}
// Reload the page when the refresh button is clicked
void Dialog::on_refreshButton_clicked(){
    ui->webView->reload();
}
// When enter is pressed in the URL edit box, load the page
void Dialog::on_urlEdit_returnPressed(){
    on_goButton_clicked();
}
// Updat the text in the URL Edit Box to match the true URL
void Dialog::updateUrlBox(){
    urls.addToHistory(ui->webView->url().toString());
    ui->urlEdit->setText(ui->webView->url().toString());
}
