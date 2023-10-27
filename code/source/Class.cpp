#include "../header/Class.h"

using namespace std;


void Class::completeSchedule(Subject &subject, std::string day){
    schedule.addSubject(subject, day);
}

void Class::showSchedule(){
    schedule.sortSchedule();
    schedule.print();
}

set<int> Class::getStudents() const{
    return students;
}

void Class::addStudent(int up){
    students.insert(up);
}

void Class::getUcScheduleFromSchedule(short id, stack<pair<Subject,string>>& s) const{
    schedule.getUcSchedule(id, s);
}

void Class::showAvailableUc() const{
    set<short> uc;
    schedule.getUc(uc);
    for(short x : uc) cout << (x > 100 ? "UP" : "L.EIC") << setw(3) << setfill('0') << x << " ";
    cout << '\n';
}
