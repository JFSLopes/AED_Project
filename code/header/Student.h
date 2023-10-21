#ifndef AED_PROJECT_STUDENT_H
#define AED_PROJECT_STUDENT_H

#include "Schedule.h"
#include "Class.h"
#include <string>
#include <list>

class Student{
private:
    short withinYears;
    int UPnumber;
    std::string name;
    std::list<std::pair<int,short>> class_Uc;

    Schedule calculateSchedule(const std::vector<Class> &c1,
                               const std::vector<Class> &c2,
                               const std::vector<Class> &c3) const;

public:
    Student(int number);
    Student(int number, std::string& name);
    bool operator<(const Student& student);

    int getUpNumber() const;
    short getNumberOfUC() const;
    std::list<std::pair<int,short>> getList() const;

    void setclass_Uc(std::list<std::pair<int,short>>& l);

    void showSchedule(const std::vector<Class> &c1,
                      const std::vector<Class> &c2,
                      const std::vector<Class> &c3) const;


};

bool operator<(const Student& student1, const Student& student2);

#endif //AED_PROJECT_STUDENT_H
