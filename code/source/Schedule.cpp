#include "../header/Schedule.h"

using namespace std;

void Schedule::addSubject(Subject &subject, string day){
    switch(week[day]){
        case 1:
            mon.push_back(subject);
            break;
        case 2:
            tue.push_back(subject);
            break;
        case 3:
            wed.push_back(subject);
            break;
        case 4:
            thu.push_back(subject);
            break;
        case 5:
            fri.push_back(subject);
            break;
    }
    sortSchedule();
}

void Schedule::print() const{
    cout << "\nMonday\n";
    for(const Subject& x : mon) x.show();
    if(mon.size() == 0) cout << "/*******************/\n";
    cout << "\nTuesday\n";
    for(const Subject& x : tue) x.show();
    if(tue.size() == 0) cout << "/*******************/\n";
    cout << "\nWednesday\n";
    for(const Subject& x : wed) x.show();
    if(wed.size() == 0) cout << "/*******************/\n";
    cout << "\nThursday\n";
    for(const Subject& x : thu) x.show();
    if(thu.size() == 0) cout << "/*******************/\n";
    cout << "\nFriday\n";
    for(const Subject& x : fri) x.show();
    if(fri.size() == 0) cout << "/*******************/\n";
}

void Schedule::getUcSchedule(short value, stack<pair<Subject,string>>& s) const{
    for(const Subject& subject : mon){
        if(subject.getUcNumber() == value) s.push(make_pair(subject, "Monday"));
    }
    for(const Subject& subject : tue){
        if(subject.getUcNumber() == value) s.push(make_pair(subject, "Tuesday"));
    }
    for(const Subject& subject : wed){
        if(subject.getUcNumber() == value) s.push(make_pair(subject, "Wednesday"));
    }
    for(const Subject& subject : thu){
        if(subject.getUcNumber() == value) s.push(make_pair(subject, "Thursday"));
    }
    for(const Subject& subject : fri){
        if(subject.getUcNumber() == value) s.push(make_pair(subject, "Friday"));
    }
}

void Schedule::sortSchedule(){
    mon.sort(); tue.sort(); wed.sort(); thu.sort(); fri.sort();
}

void Schedule::getUc(std::set<short> &s) const{
    for(const Subject& x : mon) s.insert(x.getUcNumber());
    for(const Subject& x : tue) s.insert(x.getUcNumber());
    for(const Subject& x : wed) s.insert(x.getUcNumber());
    for(const Subject& x : thu) s.insert(x.getUcNumber());
    for(const Subject& x : fri) s.insert(x.getUcNumber());
}

bool Schedule::conflict(std::stack<std::pair<Subject,std::string>>& s) const{
    while(!s.empty()){
        if(s.top().first.getType() != "T") {
            if (s.top().second == "Monday") {
                for (auto itr = mon.begin(); itr != mon.end(); itr++) {
                    if ((itr->getType() != "T" and itr->getStartHour() >= s.top().first.getStartHour() and itr->getStartHour() < s.top().first.getEndHour()) or
                       (itr->getType() != "T" and s.top().first.getStartHour() >= itr->getStartHour() and s.top().first.getStartHour() < itr->getEndHour()))
                        return true;
                }
            }
            else if(s.top().second == "Tuesday") {
                for (auto itr = tue.begin(); itr != tue.end(); itr++) {
                    if ((itr->getType() != "T" and itr->getStartHour() >= s.top().first.getStartHour() and itr->getStartHour() < s.top().first.getEndHour()) or
                        (itr->getType() != "T" and s.top().first.getStartHour() >= itr->getStartHour() and s.top().first.getStartHour() < itr->getEndHour()))
                        return true;
                }
            }
            else if(s.top().second == "Wednesday") {
                for (auto itr = wed.begin(); itr != wed.end(); itr++) {
                    if ((itr->getType() != "T" and itr->getStartHour() >= s.top().first.getStartHour() and itr->getStartHour() < s.top().first.getEndHour()) or
                        (itr->getType() != "T" and s.top().first.getStartHour() >= itr->getStartHour() and s.top().first.getStartHour() < itr->getEndHour()))
                        return true;
                }
            }
            else if(s.top().second == "Thursday") {
                for (auto itr = thu.begin(); itr != thu.end(); itr++) {
                    if ((itr->getType() != "T" and itr->getStartHour() >= s.top().first.getStartHour() and itr->getStartHour() < s.top().first.getEndHour()) or
                        (itr->getType() != "T" and s.top().first.getStartHour() >= itr->getStartHour() and s.top().first.getStartHour() < itr->getEndHour()))
                        return true;
                }
            }
            else if(s.top().second == "Friday") {
                for (auto itr = fri.begin(); itr != fri.end(); itr++) {
                    if ((itr->getType() != "T" and itr->getStartHour() >= s.top().first.getStartHour() and itr->getStartHour() < s.top().first.getEndHour()) or
                        (itr->getType() != "T" and s.top().first.getStartHour() >= itr->getStartHour() and s.top().first.getStartHour() < itr->getEndHour()))
                        return true;
                }
            }
        }
        s.pop();
    }
    return false;
}

std::set<short> Schedule::getAllUc() const{
    set<short> s;
    for(auto x : mon) s.insert(x.getUcNumber());
    for(auto x : tue) s.insert(x.getUcNumber());
    for(auto x : wed) s.insert(x.getUcNumber());
    for(auto x : thu) s.insert(x.getUcNumber());
    for(auto x : fri) s.insert(x.getUcNumber());
    return s;
}