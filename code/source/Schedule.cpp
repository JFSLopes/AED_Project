#include "../header/Schedule.h"

using namespace std;
Schedule::Schedule() {}

/*
 * Adds a subject to the corresponding vector, according to the day of the week
 */
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
}

void Schedule::print(){
    cout << "Monday\n";
    for(Subject& x : mon) x.show();
    cout << "Tuesday\n";
    for(Subject& x : tue) x.show();
    cout << "Wednesday\n";
    for(Subject& x : wed) x.show();
    cout << "Thursday\n";
    for(Subject& x : thu) x.show();
    cout << "Friday\n";
    for(Subject& x : fri) x.show();
}

void Schedule::getUcSchedule(short value, stack<pair<Subject,string>>& s){
    for(Subject& subject : mon){
        if(subject.getUcNumber() == value) s.push(make_pair(subject, "Monday"));
    }
    for(Subject& subject : tue){
        if(subject.getUcNumber() == value) s.push(make_pair(subject, "Tuesday"));
    }
    for(Subject& subject : wed){
        if(subject.getUcNumber() == value) s.push(make_pair(subject, "Wednesday"));
    }
    for(Subject& subject : thu){
        if(subject.getUcNumber() == value) s.push(make_pair(subject, "Thursday"));
    }
    for(Subject& subject : fri){
        if(subject.getUcNumber() == value) s.push(make_pair(subject, "Friday"));
    }
}