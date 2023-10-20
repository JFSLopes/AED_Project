#include "../header/Student.h"

using namespace std;

Student::Student(int number, string& name) : UPnumber(number), name(name) {}

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

