#include "../header/Uc.h"

using namespace std;

Uc::Uc(short id) : UcId(id) {}

void Uc::addClass(int classId){
    classes.insert(classId);
}

void Uc::showSchedule(const std::vector<Class> &c1,
                      const std::vector<Class> &c2,
                      const std::vector<Class> &c3) const {
    Schedule schedule = calculateSchedule(c1, c2, c3);
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
                c1[classNumber-1].getUcScheduleFromSchedule(UcId, temp);
                break;
            case 2:
                c2[classNumber-1].getUcScheduleFromSchedule(UcId, temp);
                break;
            case 3:
                c3[classNumber-1].getUcScheduleFromSchedule(UcId, temp);
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

void Uc::addStudent(int upNumber){
    students.insert(upNumber);
}

void Uc::removeStudent(int upNumber) {
    students.erase(upNumber);
}

std::set<int> Uc::getStudents() const{
    return students;
}

std::set<int> Uc::getClasses() const {
    return classes;
}

int Uc::numberStudents() const{
    return (int) students.size();
}

short Uc::getId() const{
    return UcId;
}

bool operator<(const Uc& a, const Uc& b){
    return a.UcId < b.UcId;
}