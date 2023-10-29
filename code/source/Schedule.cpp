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
    cout << "Monday\n";
    for(const Subject& x : mon) x.show();
    cout << "Tuesday\n";
    for(const Subject& x : tue) x.show();
    cout << "Wednesday\n";
    for(const Subject& x : wed) x.show();
    cout << "Thursday\n";
    for(const Subject& x : thu) x.show();
    cout << "Friday\n";
    for(const Subject& x : fri) x.show();
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