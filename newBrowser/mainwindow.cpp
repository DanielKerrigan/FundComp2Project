#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    // remove tab that is there by default
    ui->tabWidget->removeTab(0);
    // add new tab with web view
    on_actionNew_Tab_triggered();
    // set the current web view to be this tab
    current = (QWebView*) ui->tabWidget->widget(0);
    // update url edit box text to match url of new tab
    ui->urlEdit->setText(current->url().toString());
    // when the url is changed, update the url edit box
    connect(current, SIGNAL(urlChanged(const QUrl &)), this, SLOT(updateUrlBox()));
    // when a tab is cicked
    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabSelected()));


}

MainWindow::~MainWindow(){
    delete ui;
}

// Go back a page when the back button is clicked
void MainWindow::on_backButton_clicked(){
    current->back();
}
// Go forward a page when the forward button is clicked
void MainWindow::on_forwardButton_clicked(){
    current->forward();
}
// Load the URL in the URL Edit Box when go is clicked
void MainWindow::on_goButton_clicked(){
    current->load(QUrl(ui->urlEdit->text()));
}
// Reload the page when the refresh button is clicked
void MainWindow::on_refreshButton_clicked(){
    current->reload();
}
// When enter is pressed in the URL edit box, load the page
void MainWindow::on_urlEdit_returnPressed(){
    on_goButton_clicked();
}
// Updat the text in the URL Edit Box to match the true URL
void MainWindow::updateUrlBox(){
    QUrl qurl = current->url();
    QString qurlStr = qurl.toString();
    if(!urls.is_blocked(qurl.host())){ // if the website is not blocked
        // if the url is not empty, this would happen when we load html below
        if(qurlStr.size() > 0){
            urls.addToHistory(qurlStr);
            ui->urlEdit->setText(qurlStr);
            ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), qurl.host());
        }
    } else {  // website is blocked
        // load html for blocked page
        QString html = QString("<html><body><h1>%1 is blocked!</h1><img src='qrc:/Images/emrich.png'></body></html>").arg(qurl.host());
        current->setHtml(html);
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), "Emrich says no!");
    }
}

void MainWindow::on_actionNew_Tab_triggered()
{
    QWebView *newWebView = new QWebView();
    newWebView->setUrl(QUrl("http://www.google.com"));
    ui->tabWidget->addTab(newWebView, newWebView->url().host());
}

void MainWindow::on_actionBack_triggered(){
    on_backButton_clicked();
}

void MainWindow::on_actionForward_triggered(){
    on_forwardButton_clicked();
}
// change current to be the web view of the selected tab. update tab title
void MainWindow::tabSelected(){
    current = (QWebView*) ui->tabWidget->currentWidget();
    connect(current, SIGNAL(urlChanged(const QUrl &)), this, SLOT(updateUrlBox()));
    ui->urlEdit->setText(current->url().toString());
}

//timer methods
void MainWindow::onClicked(){

    QString stringValue = lineEdit->text();
    int startValue = stringValue.toInt();
    // user inputs number of minutes, timer is in seconds
    startValue = startValue*60;
    progressBar->setValue(startValue);
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    timer->start(1000);

}


void MainWindow::onTimeout()
{
    int value = progressBar->value();
    //if value == 0, exit everything
    int minutes = value/60;
    int seconds = value%60;
    QString mstring = QString::number(minutes);
    QString sstring = QString::number(seconds);
    QString display = "";
    if( seconds < 10){
        display = mstring + ":0" + sstring;
    }
    else{
        display = mstring + ":" + sstring;
    }
    label->setText(display);
    value--;
    progressBar->setValue(value);

}


void MainWindow::on_actionNew_Timer_triggered()
{
    //timer implementation
    //tried to work all of this into its own class haven't figured it out yet
    progressBar = new QProgressBar();
    progressBar->setMinimum(0);
    progressBar->setMaximum(10800);
    progressBar->setValue(0);
    lineEdit = new QLineEdit();
    //lineEdit->setMaximumWidth(30);
    lineEdit->setAlignment(Qt::AlignHCenter);
    QPushButton *start_button = new QPushButton;
    start_button->setText("Start");
    //QLCDNumber *timeLeft = new QLCDNumber();
    label = new QLabel();
    label->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(label);
    layout->addWidget(lineEdit);
    layout->addWidget(start_button);
    //layout->addWidget(progressBar);
    //layout->addWidget(timeLeft);


    QWidget *wrapper = new QWidget();
    wrapper->setLayout(layout);
    wrapper->show();
    //setCentralWidget(wrapper);

    QObject::connect(start_button, SIGNAL(clicked()), this, SLOT(onClicked()));
}
