#include "../header/Class.h"

using namespace std;


void Class::completeSchedule(Subject &subject, std::string day){
    schedule.addSubject(subject, day);
}

void Class::showSchedule(){
    schedule.sortSchedule();
    schedule.print();
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

void Class::showStudents(const std::set<Student> &allStudents) const{
    int count = 1;
    for(int x : students){
        cout << count << " ";
        count++;
        set<Student>::iterator itr = allStudents.find(Student(x));
        if(itr != allStudents.end()) itr->showStudentData();
    }
}

void Class::OrderedByName(const std::set<Student> &allStudents, std::vector<Student>& ordered) const{
    for(int x : students){
        set<Student>::iterator itr = allStudents.find(Student(x));
        if(itr != allStudents.end()) ordered.push_back(*itr);
    }
    sort(ordered.begin(), ordered.end(), [](const Student& a, const Student& b) {return a.getName() < b.getName();});
}

void Class::showStudentsOrderedByName(const std::set<Student> &allStudents) const{
    vector<Student> ordered;
    OrderedByName(allStudents, ordered);
    for(const Student& x : ordered) x.showStudentData();
}
