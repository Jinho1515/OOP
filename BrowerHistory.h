#ifndef BROWSER_HISTORY_H
#define BROWSER_HISTORY_H

#include <stack>
#include <string>

class BrowserHistory {
private:
    std::stack<std::string> backHistory; // previously visited pages
    std::string currentPage;             // current page URL

public:
    // Constructor: start at "home page"
    BrowserHistory();

    // Visit a new page: push current into history, then move to url
    void visitPage(const std::string& url);

    // Go back to the most recent page in history if possible
    void goBack();

    // Is there any page to go back to?
    bool canGoBack() const;

    // Accessors
    std::string getCurrentPage() const;
    int getBackHistorySize() const;
};

#endif // BROWSER_HISTORY_H
