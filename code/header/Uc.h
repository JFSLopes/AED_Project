#ifndef AED_PROJECT_UC_H
#define AED_PROJECT_UC_H

#include "Schedule.h"

class Uc{
private:
    int numStudents;
    Schedule schedule;
public:
    Uc();
    void addStudents(int num);
};

#endif //AED_PROJECT_UC_H
