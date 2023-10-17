#ifndef AED_PROJECT_STUDENT_H
#define AED_PROJECT_STUDENT_H

#include "Schedule.h"
#include <string>

class Student{
private:
    std::string name;
    Schedule schedule;
public:
    Student(std::string& name);
};

#endif //AED_PROJECT_STUDENT_H
