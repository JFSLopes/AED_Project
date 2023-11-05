#include "../header/Class.h"

using namespace std;
int CAP = 28;

void Class::completeSchedule(Subject &subject, std::string day){
    schedule.addSubject(subject, day);
}

void Class::showSchedule() const{
    schedule.print();
}

int Class::getNumberOfStudents() const{
    return (int)students.size();
}

void Class::addStudent(int up){
    students.insert(up);
}

void Class::removeStudent(int up) {
    students.erase(up);
}

void Class::getUcScheduleFromSchedule(short id, stack<pair<Subject,string>>& s) const{
    schedule.getUcSchedule(id, s);
}

void Class::showAvailableUc() const{
    set<short> uc;
    schedule.getUc(uc);
    for(short x : uc) cout << (x > 100 ? "UP" : "L.EIC") << right << setw(3) << setfill('0') << x%100 << " ";
    cout << '\n';
}

std::set<int> Class::getStudents() const{
    return students;
}

bool Class::isPossibleAddStudent(int number) const {
    return number < CAP;
}

std::set<short> Class::getUc() const{
    return schedule.getAllUc();
}
