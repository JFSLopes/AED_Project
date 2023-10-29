#ifndef AED_PROJECT_APP_H
#define AED_PROJECT_APP_H

class Uc;
class Class;
class Student;
class Display;
class Request;

#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>
#include "Uc.h"
#include "Request.h"
#include "Display.h"
#include "Class.h"
#include "Student.h"

/**
 * @class App
 * @brief App reads from the files and stores the data
 *
 * App reads the information about classes, uc's, students, schedule from files and stores it in the corresponding container.
 */
class App{
private:

    std::vector<Uc> vUc; ///< stores all uc's of type L.EICxxx
    std::vector<Uc> vUp; ///< stores UPxxx uc
    std::vector<Class> vClass1; ///< stores all the classes from the first year
    std::vector<Class> vClass2; ///< stores all the classes from the second year
    std::vector<Class> vClass3; ///< stores all the classes from the third year
    std::set<Student> students; ///< stores all students
    Request requests;
    Display display;
    /**
     * @brief receives a Students vector and orders that same vector by student's name
     *
     * @param v Vector that is going to be ordered
     */
    void sortByName(std::vector<Student>& v) const;
    /**
     * @brief receives a set of integers and fills a vector with the students related to values in the set
     *
     * @param s Set containing the up number of students
     * @param v Vector that is going to be filled with the students
     */
    void copySetOfIntToVector(const std::set<int>& s, std::vector<Student>& v) const;
    /**
     * @brief copies the values from the set to the given vector
     *
     * @param s Set containing the Students
     * @param v Vector that is going to be filled with the students
     */
    void copySetOfStudentsToVector(const std::set<Student>& s, std::vector<Student>& v) const;
    /**
     * @brief Check if the given class is valid and return the id of the class as an integer if exists or -1 otherwise.
     *
     * @param s
     * @return Return an integer representing the id of the class or -1 if class does not exist.
     */
    int convertStringToClassId(std::string& s) const;

public:
    /**
     * @brief Treats the information related to classes and University Courses (UC).
     *
     * This method reads line by line the UC and classes from the file and populates the vectors that will
     * contain these objects. The vectors used are vClass1, vClass2, vClass3 for classes and vUp, vUc for the UC.
     * Classes are in the format yLEICxxx, where 1 <= y <= 3. This information is used to determine the appropriate
     * vector (vClass1, vClass2, vClass3) and 'xxx' indicates the position in the vector.
     * UCs are either UPxxx or L.EICxxx, stored in vUp and vUc, respectively. 'xxx' indicates the position.
     *
     * @param file An input file stream containing the information about classes and UCs.
     */
    void read_classes_per_uc(std::ifstream& file);
    /**
     * @brief Treats the information related to the schedule of University Courses (UC).
     *
     * This method reads line by line the start and end hour of a UC, the weekday, and the corresponding class.
     * It uses this information to create the schedules for each class and completes the classes' vectors.
     *
     * @param file Input file stream containing the information related to UC schedules.
     */
    void read_classes(std::ifstream& file);
    /**
     * @brief Processes information regarding students.
     *
     * This function reads information line by line from the given file. Each line contains a student ID, their
     * name, and the UC/Class they are enrolled in. It processes this information to update records related to
     * students and some other data structures used.
     *
     * @param file An input file stream containing data representing student.
     */
    void read_students(std::ifstream& file);

    void inicialize();
    void showSchedules();
    void openFiles();
    /**
     * @brief Displays the schedule of a given student.
     *
     * This function takes a student ID as input, checks if the student is in the database, and then prints the
     * student's schedule. It utilizes methods from other classes to calculate and present the student's schedule.
     *
     * @param upNumber The student's ID to retrieve and display their schedule.
     */
    void showStudentSchedule(int upNumber);
    /**
     * @brief Displays the list of students belonging to a specific year.
     *
     * This method presents a list of students enrolled in a particular year.
     *
     * @param year The academic year for which the list of students is to be displayed.
     */
    void showStudentsPerYear(short year) const;
    /**
     * @brief Displays the list of students belonging to a specific year sorted by name.
     *
     * This method presents a sorted list of students enrolled in a particular year, arranged by their names.
     *
     * @param year The academic year for which the list of students is to be displayed.
     */
    void showStudentsPerYearByName(short year) const;
    /**
     * @brief Displays the list of students belonging to a specific class.
     *
     * This method presents a list of students enrolled in a particular class identified by its ID.
     *
     * @param classId The ID of the class for which the list of students is to be displayed.
     */
    void showStudentsPerClass(int classId) const;
    /**
     * @brief Displays the list of students belonging to a specific class sorted by name.
     *
     * This method presents a sorted list of students enrolled in a particular class identified by its ID,
     * arranged by their names.
     *
     * @param classId The ID of the class for which the list of students is to be displayed.
     */
    void showStudentsPerClassByName(int classId) const;
    /**
     * @brief Displays the list of students enrolled in a specific UC.
     *
     * This method presents a list of students enrolled in a particular UC identified by its ID.
     *
     * @param ucId The ID of the UC for which the list of students is to be displayed.
     */
    void showStudentsPerUc(short ucId) const;
    /**
     * @brief Displays the list of students enrolled in at least a specified number of University Subjects (UC).
     *
     * This function presents a list of students who are enrolled in a minimum number of UC.
     *
     * @param numberOfUc The minimum number of UC a student must be enrolled in to be included.
     */
    void showStudentsIn_n_uc(int numberOfUc) const;
    /**
     * @brief Displays the classes associated with a specific UC.
     *
     * This function presents a list of classes related to a particular UC identified by its ID.
     *
     * @param ucId The ID of the UC for which the classes are displayed.
     */
    void showClassFromUc(short ucId) const;
    /**
     * @brief Displays the UC associated with a specific class.
     *
     * This function presents a list of University Subjects related to a particular class identified by its ID.
     *
     * @param classId The ID of the class for which the UC are displayed.
     */
    void showUcFromClass(int classId) const;
    /**
     * @brief Returns the number of students within a specific class.
     *
     * @param classId The ID of the class for which the return value is calculated.
     * @return The number of students in the class.
     */
    int getNumberOfStudentsInClass(int classId) const;

    void studentsPerClassPerUc(int classId, short ucId) const;

    void showUcWithGreaterOccupation(int n) const;

    void showClassSchedule(int classId) const;
};

#endif //AED_PROJECT_APP_H
