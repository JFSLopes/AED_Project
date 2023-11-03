#ifndef AED_PROJECT_CLASS_H
#define AED_PROJECT_CLASS_H

class Schedule;
class Student;

#include "Schedule.h"
#include "Student.h"

/**
 * @class Class
 * @brief Stores the information related to classes and manipulates it.
 *
 * This class stores the important information related to a certain class.
 * Allows to set, get and display information.
 */
class Class{
private:
    Schedule schedule;  ///< Stores the schedule of this class object
    std::set<int> students; ///< Stores all the students UP numbers enrolled in this class.

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
     * @brief Shows the schedule on the console.
     */
    void showSchedule() const;
    /**
     * @brief Indicates the number of students that belong to this class.
     * @return Returns the number of students enrolled on this class.
     */
    int getNumberOfStudents() const;
    /**
     * @brief Returns all the UC that belong to this class.
     * @return Return a set with UC from this class
     */
    std::set<short> getUc() const;
    /**
     * @brief Receives a number of students and indicates if it is possible to add a new students.
     * @param number Number of students to compare.
     * @return True if it is possible to add student, false otherwise.
     */
    bool isPossibleAddStudent(int number) const;
    /**
     * @brief Returns the UP numbers of all students that belong to this class.
     * @return Returns a set with students.
     */
    std::set<int> getStudents() const;
    /**
     * @brief Show the UC that the class has.
     */
    void showAvailableUc() const;
    /**
     * @brief Receives a students and adds him to the students of this class.
     * @param up UP number of the student.
     */
    void addStudent(int up);
    /**
     * @brief Receives a students and removes him from the students of this class.
     * @param up UP number of the student.
     */
    void removeStudent(int up);
};

#endif //AED_PROJECT_CLASS_H
