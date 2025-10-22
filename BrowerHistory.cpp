#include "BrowserHistory.h"

// Start at "home page"
BrowserHistory::BrowserHistory() : currentPage("home page") {}

void BrowserHistory::visitPage(const std::string& url) {
    // Save current page to the back stack, then move
    backHistory.push(currentPage);
    currentPage = url;
}

void BrowserHistory::goBack() {
    if (!backHistory.empty()) {
        // IMPORTANT: read the value with top() BEFORE pop()
        currentPage = backHistory.top();
        backHistory.pop();
        // (If empty, "do nothing" per requirements)
    }
}

bool BrowserHistory::canGoBack() const {
    return !backHistory.empty();
}

std::string BrowserHistory::getCurrentPage() const {
    return currentPage;
}

int BrowserHistory::getBackHistorySize() const {
    return static_cast<int>(backHistory.size());
}
