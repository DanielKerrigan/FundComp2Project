#ifndef URL_COLLECTIONS_H
#define URL_COLLECTIONS_H

/* The purpose of this class is to store collections of URLs history, blocked
 * sites, and bookmarks. These lists are stored in text files to save them
 * from one browser session to another.
 */

#include <vector>
#include <set>
#include <QString>
#include <QFile>
#include <QTextStream>
class url_collections
{
public:
    url_collections(); // constructor
    ~url_collections(); // deconstructor
    // add the passed url to the collection
    void addToHistory(QString);
    void addToBlocked(QString);
    void addToBookmarks(QString);
    // remove the passed url from the collection
    void removeFromHistory(QString);
    void removeFromBookmarks(QString);
    void removeFromBlocked(QString);
    bool is_blocked(QString);
    // returns HTML for pages that show
    QString getHistoryHTML();
    QString getBlockedHTML();
    QString getBookmarksHTML();
private:
    std::vector<QString> history;
    std::set<QString> blocked;
    std::vector<QString> bookmarks;
};

#endif // URL_COLLECTIONS_H
