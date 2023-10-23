#include "../header/Uc.h"

using namespace std;

Uc::Uc(short id) : UcIdentifier(id) {}

void Uc::addClass(int c){
    classes.insert(c);
}

void Uc::showSchedule(const std::vector<Class> &c1,
                      const std::vector<Class> &c2,
                      const std::vector<Class> &c3) const {
    Schedule schedule = calculateSchedule(c1, c2, c3);
    schedule.sortSchedule();
    schedule.print();
}

Schedule Uc::calculateSchedule(const std::vector<Class> &c1,
                               const std::vector<Class> &c2,
                               const std::vector<Class> &c3) const{
    Schedule schedule;
    stack<pair<Subject,string>> temp;
    for(int x : classes){
        int year = x / 100, classNumber = x % 100;
        switch (year){
            case 1:
                c1[classNumber-1].getUcScheduleFromSchedule(UcIdentifier, temp);
                break;
            case 2:
                c2[classNumber-1].getUcScheduleFromSchedule(UcIdentifier, temp);
                break;
            case 3:
                c3[classNumber-1].getUcScheduleFromSchedule(UcIdentifier, temp);
                break;
        }
    }
    set<pair<Subject,string>> removeRepetions;
    while(!temp.empty()){
        removeRepetions.insert(temp.top());
        temp.pop();
    }
    for(pair<Subject,string> x : removeRepetions){
        schedule.addSubject(x.first, x.second);
    }
    return schedule;
}