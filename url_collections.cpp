#include "url_collections.h"


url_collections::url_collections(){

}

url_collections::~url_collections(){
    QFile hist("history.txt");
    if(hist.open(QIODevice::ReadWrite)){
        QTextStream stream(&hist);
        for(int i = history.size()-1; i >= 0; i--){
            stream << history[i] << "\n";
        }
    }
}

void url_collections::addToHistory(QString url){
    history.push_back(url);
}

void url_collections::addToBlocked(QString url){
    blocked.insert(url);
}

void url_collections::addToBookmarks(QString url){
    bookmarks.push_back(url);
}
