#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    // set homepage to google
    ui->webView->load(QUrl("https://www.google.com"));
    // when the url is changed, update the url edit box
    connect(ui->webView, SIGNAL(urlChanged(const QUrl &)), this, SLOT(updateUrlBox()));
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
    QUrl qurl = ui->webView->url();
    ui->webView->load((ui->urlEdit->text()));
    ui->tabWidget->setTabText(1, qurl.toString());
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
    QString qurlStr = qurl.toString();
    if(!urls.is_blocked(qurl.host())){ // if the website is not blocked
        // if the url is not empty, this would happen when we load html below
        if(qurlStr.size() > 0){
            urls.addToHistory(qurlStr);
            ui->urlEdit->setText(qurlStr);
        }
    } else {  // website is blocked
        // load html for blocked page
        QString html = QString("<html><body><h1>%1 is blocked!</h1><img src='qrc:/Images/emrich.png'></body></html>").arg(qurl.host());
        ui->webView->setHtml(html);
    }
}

void MainWindow::on_actionNew_Tab_triggered()
{
    QWebView *myNewWebView = new QWebView();
    ui->tabWidget->addTab(myNewWebView, "Test");
    myNewWebView->setUrl(QUrl("http://www.google.com"));
}

void MainWindow::on_actionBack_triggered(){
    on_backButton_clicked();
}

void MainWindow::on_actionForward_triggered(){
    on_forwardButton_clicked();
}
