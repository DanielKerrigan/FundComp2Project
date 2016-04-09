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
// maybe remove the duplication in the future
url_collections::~url_collections(){
    // erase history.txt and write contents of history
    QFile history_file("history.txt");
    if(history_file.open(QIODevice::WriteOnly| QIODevice::Truncate)){
        QTextStream stream(&history_file);
        for(int i = history.size()-1; i >= 0; i--){
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
        for(int i = bookmarks.size()-1; i >= 0; i--){
            stream << bookmarks[i] << "\n";
        }
    }
}

void url_collections::addToHistory(QString url){
    history.push_back(url);
}

void url_collections::addToBlocked(QString url_host){
    blocked.insert(url_host);
}

void url_collections::addToBookmarks(QString url){
    bookmarks.push_back(url);
}
// returns true if url is in blocked
bool url_collections::is_blocked(QString urlHost){
    return (blocked.find(urlHost) != blocked.end());
}
