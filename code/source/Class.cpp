#include "../header/Class.h"

using namespace std;
int CAP = 100;

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
    for(short x : uc) cout << (x > 100 ? "UP" : "L.EIC") << setw(3) << setfill('0') << x%100 << " ";
    cout << '\n';
}

void Class::OrderedByName(const std::set<Student> &allStudents, std::vector<Student>& ordered) const{
    for(int x : students){
        set<Student>::iterator itr = allStudents.find(Student(x));
        if(itr != allStudents.end()) ordered.push_back(*itr);
    }
    sort(ordered.begin(), ordered.end(), [](const Student& a, const Student& b) {return a.getName() < b.getName();});
}

std::set<int> Class::getStudents() const{
    return students;
}

bool Class::isPossibleAddStudent() const {
    return getNumberOfStudents() < CAP;
}

bool Class::isPossibleRemoveStudent() const {
    return getNumberOfStudents() > 0;
}

std::set<short> Class::getUc() const{
    return schedule.getAllUc();
}
