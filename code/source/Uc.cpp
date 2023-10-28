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

void Uc::showClassesForUc() const{
    cout << (UcIdentifier > 100 ? "UP" : "L.EIC") << setw(3) << setfill('0') << UcIdentifier%100 <<'\n';
    for(int x : classes){
        cout << x/100 << "LEIC" << setw(2) << setfill('0') << x%100 << " ";
    }
    cout<< '\n';
}

void Uc::addStudent(int up){
    students.insert(up);
}

std::set<int> Uc::getStudents() const{
    return students;
}