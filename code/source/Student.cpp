#include "../header/Student.h"

using namespace std;

Student::Student(int number, string& name) : UPnumber(number), name(name) {}
Student::Student(int number) : UPnumber(number) {}

bool Student::operator<(const Student &student){
    return this->UPnumber < student.UPnumber;
}

int Student::getUpNumber() const {
    return UPnumber;
}

bool operator<(const Student& student1, const Student& student2){
    return student1.getUpNumber() < student2.getUpNumber();
}

void Student::setclass_Uc(std::list<std::pair<int, short>> &l){
    class_Uc = l;
}

list<pair<int, short>> Student::getList() const{
    return class_Uc;
}

Schedule Student::calculateSchedule(const std::vector<Class>& c1,
                                    const std::vector<Class>& c2,
                                    const std::vector<Class>& c3) const{
    Schedule schedule;
    stack<pair<Subject,string>> temp;
    for(const pair<int, short>& x : class_Uc){
        // caso seja verdade a Uc é uma UPxxx;
        if(x.second / 100 == 1){

        }
        int year = x.first / 100;
        int classNumber = x.first % 100;
        switch(year){
            case 1:
                c1[classNumber - 1].getUcScheduleFromSchedule(x.second, temp);
                break;
            case 2:
                c2[classNumber - 1].getUcScheduleFromSchedule(x.second, temp);
                break;
            case 3:
                c3[classNumber - 1].getUcScheduleFromSchedule(x.second, temp);
                break;
        }
    }
    while(!temp.empty()){
        schedule.addSubject(temp.top().first, temp.top().second);
        temp.pop();
    }
    return schedule;
}

void Student::showSchedule(const std::vector<Class>& c1,
                           const std::vector<Class>& c2,
                           const std::vector<Class>& c3) const{
    cout << "Aluno: " << name << '\n' << "Número up: " << UPnumber << '\n';
    Schedule schedule = calculateSchedule(c1, c2, c3);
    schedule.sortSchedule();
    schedule.print();
}