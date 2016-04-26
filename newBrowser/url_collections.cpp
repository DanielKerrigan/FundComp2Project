#include "url_collections.h"

// constructor: read lines from files into containers
// maybe remove the duplication in the future
url_collections::url_collections(){
    QFile blocked_file("blocked.txt");
    if(blocked_file.open(QIODevice::ReadOnly)){
        QTextStream stream(&blocked_file);
        while(!stream.atEnd()){
            blocked.insert(stream.readLine());
        }
    }
    QFile bookmarks_file("bookmarks.txt");
    if(bookmarks_file.open(QIODevice::ReadOnly)){
        QTextStream stream(&bookmarks_file);
        while(!stream.atEnd()){
            bookmarks.push_back(stream.readLine());
        }
    }
    QFile history_file("history.txt");
    if(history_file.open(QIODevice::ReadOnly)){
        QTextStream stream(&history_file);
        while(!stream.atEnd()){
            history.push_back(stream.readLine());
        }
    }
}
// deconstructor: write data from containers to text files
// for now, I am overwriting each file, rather than keeping track
// of what was added/removed in the current session
// this is easier, but more wasteful
url_collections::~url_collections(){
    // erase history.txt and write contents of history
    QFile history_file("history.txt");
    if(history_file.open(QIODevice::WriteOnly| QIODevice::Truncate)){
        QTextStream stream(&history_file);
        for(unsigned long i = 0; i < history.size(); i++){
            stream << history[i] << "\n";
        }
    }
    // erase blocked.txt and write contents of blocked
    QFile blocked_file("blocked.txt");
    if(blocked_file.open(QIODevice::WriteOnly | QIODevice::Truncate)){
        QTextStream stream(&blocked_file);
        std::set<QString>::iterator it;
        for(it = blocked.begin(); it != blocked.end(); ++it){
            stream << *it << "\n";
        }
    }
    // erase bookmarks.txt and write contents of bookmarks to it
    QFile bookmarks_file("bookmarks.txt");
    if(bookmarks_file.open(QIODevice::WriteOnly | QIODevice::Truncate)){
        QTextStream stream(&bookmarks_file);
        for(unsigned long i = 0; i < bookmarks.size(); i++){
            stream << bookmarks[i] << "\n";
        }
    }
}
// add the url to the history list
void url_collections::addToHistory(QString url){
    history.push_back(url);
}
// add the url host to the blocked sites set
void url_collections::addToBlocked(QString url_host){
    blocked.insert(url_host);
}
// add the url to the bookmarks list
void url_collections::addToBookmarks(QString url){
    bookmarks.push_back(url);
}
// returns true if url is in blocked
bool url_collections::is_blocked(QString urlHost){
    return (blocked.find(urlHost) != blocked.end());
}
// Return HTML for a page that lists the history urls
QString url_collections::getHistoryHTML(){
    QString html = QString("");
    std::vector<QString>::reverse_iterator it;
    for(it = history.rbegin(); it != history.rend(); ++it){
        html += QString("<tr><td><a href='%1'>%1</a></td></tr>").arg(*it);
    }
    return html;
}
// Return HTML for a page that lists the blocked urls
QString url_collections::getBlockedHTML(){
    QString html = QString("");
    std::set<QString>::iterator it;
    for(it = blocked.begin(); it != blocked.end(); ++it){
        html += QString("<tr><td><a href='%1'>%1</a></td></tr>").arg(*it);
    }
    return html;
}
// Return HTML for a page that lists the bookmark urls
QString url_collections::getBookmarksHTML(){
    QString html = QString("");
    std::vector<QString>::reverse_iterator it;
    for(it = bookmarks.rbegin(); it != bookmarks.rend(); ++it){
        html += QString("<tr><td><a href='%1'>%1</a></td></tr>").arg(*it);
    }
    return html;
}
// remove the url from the history list, if it is in the list
void url_collections::removeFromHistory(QString url){
    std::vector<QString>::iterator it = std::find(history.begin(), history.end(), url);
    if(it != history.end()){
        history.erase(it);
    }
}
// remove the url from the bookmarks list, if it is in the list
void url_collections::removeFromBookmarks(QString url){
    std::vector<QString>::iterator it = std::find(bookmarks.begin(), bookmarks.end(), url);
    if(it != bookmarks.end()){
        bookmarks.erase(it);
    }
}
// remove the url from the blocked sites set, if it is in the set
void url_collections::removeFromBlocked(QString url){
    std::set<QString>::iterator it = blocked.find(url);
    if(it != blocked.end()){
        blocked.erase(it);
    }
}
