#ifndef AED_PROJECT_STUDENT_H
#define AED_PROJECT_STUDENT_H

class Class;

#include <string>
#include <list>
#include "Class.h"
/**
 * @class Student
 * @brief Stores all data related to a student, to set and get information and to check conditions.
 *
 * This class stores all the important information related to a student.
 * Allows to check condition and to set and get data.
 */
class Student{
private:
    std::string enrolledYears; ///< String that stores the year/s the student is enrolled.
    int UPnumber; ///< Stores the UP number of the student.
    std::string name; ///< Stores the name of the student.
    std::list<std::pair<int,short>> class_Uc; ///< Stores all pairs of classes and UC that the student has.
    /**
     * @brief Calculates the schedule of this student and returns it.
     * @param c1 Vector containing the first year classes.
     * @param c2 Vector containing the second year classes.
     * @param c3 Vector containing the third year classes.
     * @return Returns an object of Schedule
     */
    Schedule calculateSchedule(const std::vector<Class> &c1, const std::vector<Class> &c2, const std::vector<Class> &c3) const;

public:
    /**
     * @brief Default constructor of a student.
     */
    Student();
    /**
     * @brief Constructor of a student that receives his UP number.
     */
    Student(int number);
    /**
     * @brief Constructor of a student that receives his UP number and name.
     */
    Student(int number, std::string& name);
    /**
     * @brief Returns the UP number of this student's object.
     * @return Return student's UP number.
     */
    int getUpNumber() const;
    /**
     * @brief Returns the number of UC the student is enrolled.
     * @return Returns the number of UC.
     */
    int getNumberOfUc() const;
    /**
     * @brief Removes the UC.
     *
     * This function removes the given UC if the student has it.
     * Return -1 if there is no other UC with the same class has the removed UC had. Otherwise returns the class ID.
     *
     * @param ucId Indicates the UC ID.
     * @return Return -1 if there is another class equal to the class that was removed together with the Uc or the class ID that was removed otherwise.
     */
    int removeUc(short ucId);
    /**
     * @brief Returns the UP number of this student.
     * @return Returns the UP number.
     */
    std::string getName() const;
    /**
     * @brief Returns the class that corresponds to the given UC ID.
     * @param ucId Indicates the UC ID.
     * @return Return the class ID associated with the UC or -1 otherwise.
     */
    int getClass(short ucId) const;
    /**
     * @brief Returns a list containing all UC and classes he is enrolled in.
     * @return Returns student's UC and classes his enrolled.
     */
    std::list<std::pair<int,short>> getList() const;
    /**
     * @brief This function receives a list of UC/class pair and stores it.
     * @param l List of all pairs of UC and classes the student is enrolled.
     */
    void setclass_uc(std::list<std::pair<int,short>>& l);
    /**
     * @brief This function receives a pair of UC/class and stores it.
     * @param l Pair of UC and class the student is enrolled.
     */
    void setclass_uc(std::pair<int,short> l);
    /**
     * @brief This function stores a string containing the years a student is enrolled.
     * @param s String containing the year the student is enrolled.
     */
    void setEnrolledYears(const std::string& s);
    /**
     * @brief Displays the content of the student.
     *
     * This functions displays the student name and UP number.
     */
    void showStudentData() const;
    /**
     * @brief Displays this student schedule.
     * @param c1 Vector containing the first year classes.
     * @param c2 Vector containing the second year classes.
     * @param c3 Vector containing the third year classes.
     */
    void showSchedule(const std::vector<Class> &c1, const std::vector<Class> &c2, const std::vector<Class> &c3) const;
    /**
     * @brief Displays the UC the student is enrolled.
     */
    void showAvailableUc() const;
    /**
     * @brief Checks for conflicts between the UC schedule and the student schedule.
     *
     * This function is going to check if there is conflict between an UC schedule and a student schedule.
     * Conflicts only exists between (TP) or (PL) subjects and if the student would have two of this subject at the same time.
     *
     * @param s Stack containing the schedule of an UC.
     * @param c1 Vector containing the first year classes.
     * @param c2 Vector containing the second year classes.
     * @param c3 Vector containing the third year classes.
     * @return Returns true if the schedules have a conflict, false otherwise.
     */
    bool checkForConflict(std::stack<std::pair<Subject,std::string>>& s, const std::vector<Class> &c1, const std::vector<Class> &c2, const std::vector<Class> &c3) const;
    /**
     * @brief Check if a student is enrolled in a given year.
     * @param year Indicates the year.
     * @return Returns true if the student belong to that year, false otherwise.
     */
    bool belongToYear(char year) const;
    /**
     * @brief Receives a pair of a class and UC and check if the student has it.
     * @param classId Indicates the class ID.
     * @param ucId Indicates the UC ID.
     * @return Return true if the student has this pair, false otherwise.
     */
    bool class_uc(int classId, short ucId) const;
    /**
     * @brief Checks if students have the same UP number.
     * @param student Object of student.
     * @return Returns true if two students share the exact same UP number.
     */
    bool operator==(const Student& student);
    /**
     * @brief This function check if the student has a given UC.
     * @param ucId Indicates the UC ID.
     * @return Returns true if the student has the UC, false otherwise.
     */
    bool checkUc(short ucId) const;
    /**
     * @brief This function checks if the student has a given class.
     *
     * O(n), where n is the number of pairs class_uc.
     *
     * @param classId Indicates the class ID.
     * @return Returns -1 the student has the class or the same class ID otherwise.
     */
    int checkClass(int classId) const;
};
/**
 * @brief Compares two objects of students by their UP number.
 * @param student1 Object of student.
 * @param student2 Object of student.
 * @return Returns true if the UP number of student1 is less that student2 UP number.
 */
bool operator<(const Student& student1, const Student& student2);

#endif //AED_PROJECT_STUDENT_H
