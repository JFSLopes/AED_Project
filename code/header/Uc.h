#ifndef AED_PROJECT_UC_H
#define AED_PROJECT_UC_H

#include "Schedule.h"
#include "Class.h"


class Uc{
private:
    short UcIdentifier;
    std::set<int> students;
    std::set<int> classes;
    Schedule calculateSchedule(const std::vector<Class> &c1,
                               const std::vector<Class> &c2,
                               const std::vector<Class> &c3) const;

public:
    Uc(short id);
    void addStudents(int num);
    void addClass(int c);
    void showSchedule(const std::vector<Class> &c1,
                      const std::vector<Class> &c2,
                      const std::vector<Class> &c3) const;


};

#endif //AED_PROJECT_UC_H
