#include "../header/Class.h"

Class::Class() : numStudents(0) {}

void Class::completeSchedule(Subject &subject, std::string day){
    schedule.addSubject(subject, day);
}

void Class::show(){
    schedule.print();
}