#include <iostream>
#include "BrowserHistory.h"

int main() {
    BrowserHistory bh;

    std::cout << "Start at: " << bh.getCurrentPage() << "\n";
    std::cout << "Can go back? " << (bh.canGoBack() ? "yes" : "no") << "\n\n";

    bh.visitPage("example.com");
    bh.visitPage("news.com");
    bh.visitPage("university.edu");

    std::cout << "Now at: " << bh.getCurrentPage() << "\n";
    std::cout << "Back history size: " << bh.getBackHistorySize() << "\n\n";

    // Go back twice
    if (bh.canGoBack()) bh.goBack();
    std::cout << "After 1 back -> " << bh.getCurrentPage() << "\n";

    if (bh.canGoBack()) bh.goBack();
    std::cout << "After 2 back -> " << bh.getCurrentPage() << "\n";

    // Try going back until empty (no crash, does nothing when empty)
    while (bh.canGoBack()) {
        bh.goBack();
    }
    std::cout << "After draining history -> " << bh.getCurrentPage() << "\n";
    std::cout << "Back history size: " << bh.getBackHistorySize() << "\n";

    return 0;
}
