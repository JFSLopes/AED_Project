#ifndef AED_PROJECT_SCHEDULE_H
#define AED_PROJECT_SCHEDULE_H

#include "Subject.h"
#include <list>
#include <set>
#include <map>

class Schedule{
private:
    std::map<std::string, short> week{{"Monday", 1},
                                    {"Tuesday",2},
                                    {"Wednesday",3},
                                    {"Thursday",4},
                                    {"Friday",5}};
    std::list<Subject> mon;
    std::list<Subject> tue;
    std::list<Subject> wed;
    std::list<Subject> thu;
    std::list<Subject> fri;
public:
    void addSubject(Subject& subject, std::string day);
    void print() const;
    void getUcSchedule(short value, std::stack<std::pair<Subject, std::string>>& s) const;
    void sortSchedule();
};

#endif //AED_PROJECT_SCHEDULE_H
