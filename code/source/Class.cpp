#include "../header/Class.h"

using namespace std;

void Class::completeSchedule(Subject &subject, std::string day){
    schedule.addSubject(subject, day);
}

void Class::show(){
    schedule.print();
}

void Class::getUcScheduleFromSchedule(short id, stack<pair<Subject,string>>& s){
    schedule.getUcSchedule(id, s);
}
