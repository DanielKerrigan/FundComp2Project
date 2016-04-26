#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>

// constructor
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
    // set the index of the tab
     ui->tabWidget->setCurrentIndex(0);
     currentNumOfTabs = 1;
     timer_exists = 0;
}
// Deconstructor
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
// Go back when the menu back option is selected
void MainWindow::on_actionBack_triggered(){
    on_backButton_clicked();
}
// Go forward when the menu forward option is selected
void MainWindow::on_actionForward_triggered(){
    on_forwardButton_clicked();
}
// Load the URL in the URL Edit Box when go is clicked
void MainWindow::on_goButton_clicked(){
    QString inputURL = QUrl(ui->urlEdit->text()).toString();
    if (inputURL.contains("http://") || inputURL.contains("https://")){
        current->load(inputURL);
    } else {
        current->load(inputURL.prepend("http://"));
    }
}
// Reload the page when the refresh button is clicked
void MainWindow::on_refreshButton_clicked(){
    current->reload();
}
// Indicate that a search is being made
void MainWindow::on_google_returnPressed(){
    on_googleButton_clicked();
}
// Load the page for the search bar
void MainWindow::on_googleButton_clicked() {
    current->load(QUrl(QString("http://www.google.com/#q=")+(ui->google->text())));
}
// When enter is pressed in the URL edit box, load the page
void MainWindow::on_urlEdit_returnPressed(){
    on_goButton_clicked();
}
// Update the text in the URL Edit Box to match the true URL
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
        QFile file(":/HTML/blocked.html");
        if (!file.open(QIODevice::ReadOnly))
            qDebug() << "Couldn't open file";
        QTextStream in(&file);
        // history_string is rows of history items in html
        QString blocked_string = urls.getBlockedHTML();
        // replace %1 and %2 in html with website currently visiting and table
        QString html = QString(in.readAll()).arg(qurl.host(), blocked_string);
        setHTML(html, "Emrich says no!", qurl.host());
    }
}


// Called when a new tab is added.
// create a new web view, adds the web view as a tab, and switches to this tab
void MainWindow::on_actionNew_Tab_triggered()
{
    int currentTabIndex = ui->tabWidget->currentIndex();
    QWebView *newWebView = new QWebView();
    newWebView->setUrl(QUrl("http://www.google.com"));
    ui->tabWidget->addTab(newWebView, newWebView->url().host());
    currentNumOfTabs++;
    ui->tabWidget->setCurrentIndex(currentTabIndex+1);
}
// change current to be the web view of the selected tab. update tab title
void MainWindow::tabSelected(){
    current = (QWebView*) ui->tabWidget->currentWidget();
    connect(current, SIGNAL(urlChanged(const QUrl &)), this, SLOT(updateUrlBox()));
    ui->urlEdit->setText(current->url().toString());
}
// close the current tab when the menu option is selected
void MainWindow::on_actionClose_Tab_triggered(){
    currentNumOfTabs--;
    int currentTabIndex = ui->tabWidget->currentIndex();
    if(currentNumOfTabs != 0){
        ui->tabWidget->removeTab(currentTabIndex);
    } else {
        QApplication::quit();
    }
}
// close the entire browser
void MainWindow::on_actionClose_Window_triggered(){
    QApplication::quit();
}
// close the tab when the close tab button is pressed
void MainWindow::on_closeTab_pressed(){
    on_actionClose_Tab_triggered();
}
// open a new tab when the new tab button is pressed
void MainWindow::on_newTab_pressed(){
    on_actionNew_Tab_triggered();
}
// add the current page to the bookmarks
void MainWindow::on_actionAdd_Bookmark_triggered(){
    urls.addToBookmarks(current->url().toString());
}
// add the current page to the blocked sites
void MainWindow::on_actionBlock_site_triggered(){
    urls.addToBlocked(current->url().host());
}
// remove the current page from the bookmarks
void MainWindow::on_actionRemove_Bookmark_triggered(){
    urls.removeFromBookmarks(current->url().toString());
}
// remove the current page from the list of blocked sites
void MainWindow::on_actionRemove_Blocked_triggered(){
    //QString urlHost = ui->urlEdit->text();
    QString urlHost = current->history()->currentItem().url().host();
    urls.removeFromBlocked(urlHost);
}

  //------------//
  // Timer Code //
  //------------//

void MainWindow::on_actionNew_Timer_triggered(){
    if( !timer_exists ){
        //indicator
        timer_exists = 1;

        //timer implementation
        //progress bar is used to increment
        progressBar = new QProgressBar();
        progressBar->setMinimum(0);
        progressBar->setMaximum(10800);
        progressBar->setValue(0);

        lineEdit = new QLineEdit();
        lineEdit->setAlignment(Qt::AlignHCenter);
        start_button = new QPushButton;
        start_button->setText("Start");
        label = new QLabel();
        label->setAlignment(Qt::AlignCenter);
        input_label = new QLabel();
        input_label->setText("minutes");

        //horizontal layout puts
        //input box next to label
        hlayout1 = new QHBoxLayout();
        hlayout1->addWidget(lineEdit);
        hlayout1->addWidget(input_label);

        //vertical layout for timer
        vlayout = new QVBoxLayout();
        vlayout->addLayout(hlayout1);
        vlayout->addWidget(label);
        vlayout->addWidget(start_button);

        //timer object
        wrapper = new QWidget();
        wrapper->setLayout(vlayout);
        wrapper->show();

        QObject::connect(start_button, SIGNAL(clicked()), this, SLOT(onClicked()));
    }
}

void MainWindow::onClicked(){
    if( start_button->text() == "Start"){
        QString stringValue = lineEdit->text();
        int startValue = stringValue.toInt();

        //change button
        start_button->setText("Get to Work");
        start_button->setCheckable(true);
        start_button->setChecked(true);

        // user inputs number of minutes, timer is in seconds
        startValue = startValue*60;
        progressBar->setValue(startValue);
        timer = new QTimer();
        QObject::connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
        timer->start(1000);
    }else{
        start_button->setChecked(true);
    }

}

//slot that takes action every second
void MainWindow::onTimeout(){
    int value = progressBar->value();
    if( value == 0){
        close();
        qApp->exit();
    }else{
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
        ui->statusBar->showMessage(display);
        value--;
        progressBar->setValue(value);
    }
}

// change the html, tab label, and text in the url edit box
void MainWindow::setHTML(QString html, QString tabName, QString urlBox){
    current->setHtml(html);
    ui->urlEdit->setText(urlBox);
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), tabName);
}

// Show history links in an html page
void MainWindow::on_actionView_History_triggered(){    
    // load html for history page
    QFile file(":/HTML/history.html");
    if (!file.open(QIODevice::ReadOnly))
        qDebug() << "Couldn't open file";
    QTextStream in(&file);
    // history_string is rows of history items in html
    QString history_string = urls.getHistoryHTML();
    // replace %1 in html with table
    QString html = QString(in.readAll()).arg(history_string);
    setHTML(html, "History", "");

}
// Show blocked links in an html page
void MainWindow::on_actionView_Blocked_triggered(){    
    // load html for allblocked page (doesn't say that current page is necessarily blocked)
    QFile file(":/HTML/allblocked.html");
    if (!file.open(QIODevice::ReadOnly))
        qDebug() << "Couldn't open file";
    QTextStream in(&file);
    // blocked_string is rows of history items in html
    QString blocked_string = urls.getBlockedHTML();
    // replace %1 in html with table
    QString html = QString(in.readAll()).arg(blocked_string);
    setHTML(html, "Blocked Pages", "");
}
// Show bookmark links in an html page
void MainWindow::on_actionView_Bookmarks_triggered(){
    // load html for bookmarks page
    QFile file(":/HTML/bookmarks.html");
    if (!file.open(QIODevice::ReadOnly))
        qDebug() << "Couldn't open file";
    QTextStream in(&file);
    // bookmarks_string is rows of history items in html
    QString bookmarks_string = urls.getBookmarksHTML();
    // replace %1 in html with table
    QString html = QString(in.readAll()).arg(bookmarks_string);
    setHTML(html, "Bookmarks", "");
}


void MainWindow::on_actionShow_Timer_2_triggered(){
    if( timer_exists ){
            if( start_button->text() == "Get to Work"){
                hlayout1->removeWidget(lineEdit);
                hlayout1->removeWidget(input_label);
                delete lineEdit;
                delete input_label;
                wrapper->update();
                wrapper->setLayout(vlayout);
                start_button->setText("Time Left");
            }
            wrapper->show();
    }
    //button takes no action if timer doesn't exist
}

void MainWindow::on_actionHide_Timer_triggered(){
    if( timer_exists) wrapper->hide();
    //button takes no action if timer doesn't exist
}
