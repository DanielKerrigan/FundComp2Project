#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){

    ui->setupUi(this);

    ui->webView->load(QUrl("http://www.google.com"));

    connect(ui->webView, SIGNAL(urlChanged(const QUrl &)), this, SLOT(updateUrlBox()));

//    QWebView *webView = new QWebView;
//    QVBoxLayout *layout = new QVBoxLayout;
//    this->centralWidget()->setLayout(layout);
//    layout->addWidget(webView);
}

MainWindow::~MainWindow(){
    delete ui;
}

// Go back a page when the back button is clicked
void MainWindow::on_backButton_clicked(){
    ui->webView->back();
}
// Go forward a page when the forward button is clicked
void MainWindow::on_forwardButton_clicked(){
    ui->webView->forward();
}
// Load the URL in the URL Edit Box when go is clicked
void MainWindow::on_goButton_clicked(){
    ui->webView->load((ui->urlEdit->text()));
}
// Reload the page when the refresh button is clicked
void MainWindow::on_refreshButton_clicked(){
    ui->webView->reload();
}
// When enter is pressed in the URL edit box, load the page
void MainWindow::on_urlEdit_returnPressed(){
    on_goButton_clicked();
}
// Updat the text in the URL Edit Box to match the true URL
void MainWindow::updateUrlBox(){
    QUrl qurl = ui->webView->url();
    if(!urls.is_blocked(qurl.host())){
        urls.addToHistory(qurl.toString());
        ui->urlEdit->setText(qurl.toString());
    } else {
        // website is blocked
        QString html = QString("<html><body><h1>%1 is blocked!</h1><img src='qrc:/Images/emrich.png'></body></html>").arg(qurl.host());
        ui->webView->setHtml(html);
    }
}
