#include "../header/Request.h"

void Request::addStack(Change &change) {
    changes.push(change);
}

bool Request::isEmpty() const {
    return changes.empty();
}

void Request::pop() {
    changes.pop();
}

void Request::showMostRecent() const {
    changes.top().showChange();
}


