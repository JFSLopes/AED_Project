#ifndef AED_PROJECT_SCHEDULE_H
#define AED_PROJECT_SCHEDULE_H

#include "Subject.h"
#include <vector>
#include <set>
#include <map>

class Schedule{
private:
    std::map<std::string, int> week{{"Monday", 1},
                                    {"Tuesday",2},
                                    {"Wednesday",3},
                                    {"Thursday",4},
                                    {"Friday",5}};
    std::vector<Subject> mon;
    std::vector<Subject> tue;
    std::vector<Subject> wed;
    std::vector<Subject> thu;
    std::vector<Subject> fri;
public:
    Schedule();
    void addSubject(Subject& subject, std::string day);
    void print();
    void getUcSchedule(short value, std::stack<std::pair<Subject, std::string>>& s);
};

#endif //AED_PROJECT_SCHEDULE_H
