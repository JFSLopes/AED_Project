#ifndef AED_PROJECT_CLASS_H
#define AED_PROJECT_CLASS_H

#include "Schedule.h"
#include "Student.h"

class Class{
private:
    Schedule schedule;
    std::set<int> students;
public:
    void completeSchedule(Subject& subject, std::string day);
    // retorna o hórario desta uc nesta turma
    void getUcScheduleFromSchedule(short id, std::stack<std::pair<Subject,std::string>>& s);
    void show();
};

#endif //AED_PROJECT_CLASS_H
