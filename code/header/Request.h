#ifndef AED_PROJECT_REQUEST_H
#define AED_PROJECT_REQUEST_H

#include <stack>
#include "Change.h"

class Request{
    private:
        std::stack<Change> changes;
    public:
        void addStack(Change& change);
        void showMostRecent() const;
        bool isEmpty() const;
        void pop();
};

#endif //AED_PROJECT_REQUEST_H
