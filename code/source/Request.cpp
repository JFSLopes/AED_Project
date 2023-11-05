#include "../header/Request.h"

void Request::addStack(Change* change) {
    changes.push(change);
}

bool Request::isEmpty() const {
    return changes.empty();
}

void Request::pop(bool delete_){
    if(!isEmpty()){
        std::cout << "Successfully undone the most recent change.\n";
        if(delete_) delete changes.top();
        changes.pop();
    }
    else std::cout << "There is no change to be undone.\n";
}

void Request::showMostRecent() const{
    if(!isEmpty()){
        changes.top()->showChange();
    }
    else std::cout << "There are no changes.\n";
}

Change* Request::top() const{
    return changes.top();
}

void Request::clean(){
    while(!changes.empty()){
        delete changes.top();
        changes.pop();
    }
}

