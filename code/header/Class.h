#ifndef AED_PROJECT_CLASS_H
#define AED_PROJECT_CLASS_H

class Schedule;
class Student;

#include "Schedule.h"
#include "Student.h"

class Class{
private:
    Schedule schedule;
    std::set<int> students;

    void OrderedByName(const std::set<Student>& allStudents, std::vector<Student>& ordered) const;

public:
    void completeSchedule(Subject& subject, std::string day);
    /**
     * @brief gets the Uc schedule from a certain class
     *
     * This method is used to fill parameter 's' with a pair of Subject and string where the Subject stores
     * the information related to the Uc (start hour, name, ...) and the string indicates de day of the week
     *
     * @param id The code that identifies the Uc
     * @param s Container where the information about the Uc being search is going to be stored
     */
    void getUcScheduleFromSchedule(short id, std::stack<std::pair<Subject,std::string>>& s) const;
    /**
     * @brief sorts the schedule by starting hour and prints it to the console
     */
    void showSchedule() const;
    int getNumberOfStudents() const;
    bool isPossibleAddStudent() const;
    bool isPossibleRemoveStudent() const;
    std::set<int> getStudents() const;
    void showAvailableUc() const;
    void addStudent(int up);
};

#endif //AED_PROJECT_CLASS_H
