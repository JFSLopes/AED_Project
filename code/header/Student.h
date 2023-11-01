#ifndef AED_PROJECT_STUDENT_H
#define AED_PROJECT_STUDENT_H

class Class;

#include <string>
#include <list>
#include "Class.h"

class Student{
private:
    std::string enrolledYears;
    int UPnumber;
    std::string name;
    std::list<std::pair<int,short>> class_Uc;

    Schedule calculateSchedule(const std::vector<Class> &c1, const std::vector<Class> &c2, const std::vector<Class> &c3) const;

public:
    Student();
    Student(int number);
    Student(const std::set<Student>::iterator student);
    Student(int number, std::string& name);
    bool operator<(const Student& student);

    int getUpNumber() const;
    int getNumberOfUc() const;
    int removeUc(short ucId);
    std::string getName() const;
    std::list<std::pair<int,short>> getList() const;

    void setclass_Uc(std::list<std::pair<int,short>>& l);
    void setclass_uc(std::pair<int,short> l);
    void setEnrolledYears(const std::string& s);

    void showStudentData() const;
    void showSchedule(const std::vector<Class> &c1, const std::vector<Class> &c2, const std::vector<Class> &c3) const;
    void showAvailableUc() const;

    bool checkForConflict(std::stack<std::pair<Subject,std::string>>& s, const std::vector<Class> &c1, const std::vector<Class> &c2, const std::vector<Class> &c3) const;
    bool belongToYear(char year) const;
    bool class_uc(int classId, short ucId) const;

    bool operator==(const Student& student);
    bool checkUc(short ucId) const;
    int checkClass(int classId) const;


};

bool operator<(const Student& student1, const Student& student2);

#endif //AED_PROJECT_STUDENT_H
