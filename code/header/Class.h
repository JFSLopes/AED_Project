#ifndef AED_PROJECT_CLASS_H
#define AED_PROJECT_CLASS_H

#include "Schedule.h"

class Class{
private:
    int numStudents;
    Schedule schedule;
public:
    Class();
    void completeSchedule(Subject& subject, std::string day);
    void show();
};

#endif //AED_PROJECT_CLASS_H
