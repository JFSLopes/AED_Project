#include "../header/Student.h"

using namespace std;

Student::Student() {}
Student::Student(int number, string& name) : UPnumber(number), name(name) {}
Student::Student(int number) : UPnumber(number) {}
Student::Student(const set<Student>::iterator student){
    UPnumber = student->getUpNumber();
    name = student->getName();
    class_Uc = student->getList();
}

bool Student::operator<(const Student &student){
    return this->UPnumber < student.UPnumber;
}

bool Student::operator==(const Student &student){
    return this->getUpNumber() == student.getUpNumber();
}

int Student::getUpNumber() const {
    return UPnumber;
}

int Student::getNumberOfUc() const{
    return (int) class_Uc.size();
}

bool operator<(const Student& student1, const Student& student2){
    return student1.getUpNumber() < student2.getUpNumber();
}

void Student::setclass_Uc(std::list<std::pair<int, short>>& l){
    class_Uc = l;
}

void Student::setEnrolledYears(const std::string &s){
    enrolledYears = s;
}

list<pair<int, short>> Student::getList() const{
    return class_Uc;
}

Schedule Student::calculateSchedule(const std::vector<Class>& c1, const std::vector<Class>& c2, const std::vector<Class>& c3) const{
    Schedule schedule;
    stack<pair<Subject,string>> temp;
    for(const pair<int, short>& x : class_Uc){
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
    schedule.sortSchedule();
    return schedule;
}

void Student::showSchedule(const std::vector<Class>& c1, const std::vector<Class>& c2, const std::vector<Class>& c3) const{
    cout << "\n\t\t\tStudent: " << name << '\n' << "\t\t\tUP number: " << UPnumber << '\n';
    Schedule schedule = calculateSchedule(c1, c2, c3);
    schedule.print();
}

void Student::showStudentData() const{
    cout << string(3, ' ') << left << setw(30) << name << std::setw(9) << right << UPnumber << left << '\n';
    cout << string(46, '-') << '\n';
}

bool Student::belongToYear(char year) const{
    return (enrolledYears.find(year) != string::npos);
}

string Student::getName() const{
    return name;
}

bool Student::class_uc(int classId, short ucId) const{
    return find(class_Uc.begin(), class_Uc.end(), make_pair(classId, ucId)) != class_Uc.end();
}

bool Student::checkUc(short ucId) const {
    for (auto x : class_Uc) {
        if(x.second == ucId) return true;
    }
    return false;
}

void Student::setclass_uc(std::pair<int, short> l){
    class_Uc.push_back(l);
}

bool Student::checkForConflict(std::stack<std::pair<Subject, std::string>> &s, const std::vector<Class> &c1, const std::vector<Class> &c2, const std::vector<Class> &c3) const{
    Schedule schedule = calculateSchedule(c1, c2, c3);
    return schedule.conflict(s);
}

int Student::removeUc(short ucId){
    ///<Remove UC from schedule
    pair<int,short> p;
    for(auto itr = class_Uc.begin(); itr != class_Uc.end(); itr++){
        if(itr->second == ucId){
            p = *itr;
            class_Uc.erase(itr);
            break;
        }
    }
    ///< check if there is another UC with the same class removed
    for(auto itr = class_Uc.begin(); itr != class_Uc.end(); itr++){
        if(itr->first == p.first) return -1;
    }
    return p.first;
}

void Student::showAvailableUc() const {
    for(auto x : class_Uc) cout << (x.second > 100 ? "UP" : "L.EIC") << setw(3) << setfill('0') << x.second%100 << "   ";
    cout << '\n';
}