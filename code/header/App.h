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
#include <limits>
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
    Display display; ///< it allows to call function that print useful information on console
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
     * @param s String that represents the class.
     * @return Return an integer representing the id of the class or -1 if class does not exist.
     */
    int convertStringToClassId(std::string& s) const;
    /**
     * @brief Check if the given UC is valid and return the id of the UC as an short if exists or -1 otherwise.
     *
     * @param s String that represents the UC.
     * @return Return an integer representing the id of the UC or -1 if UC does not exist.
     */
    short convertStringToUcId(std::string& s) const;
    /**
     * @brief Display the students within a vector
     *
     * Displays a vector that is already ordered according to the user's need.
     *
     * @param v Vector to be displayed
     */
    void showStudents(const std::vector<Student>& v) const;
    /**
     * @brief Display the students within a vector
     *
     * Displays, in reverse, a vector that is already ordered according to the user's need.
     *
     * @param v Vector to be displayed
     */
    void reverseShowSudents(const std::vector<Student>& v) const;

public:
    /**
     * @brief Is responsible for calling the functions that are going to read the files.
     */
    void openFiles();
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
     * name, and the respective UC/Class they are enrolled in. It processes this information to update records related to
     * students and some other data structures used.
     *
     * @param file An input file stream containing data representing student.
     */
    void read_students(std::ifstream& file);
    /**
     * @brief Responsible for starting the execution of the API.
     *
     * This function is going to call the function that read files and the ones that interact with the user.
     */
    void inicialize();
    /**
     * @brief Responsible for display all the possible schedules.
     *
     * This function receives an input from the user and from there displays the schedule requested by the user.
     */
    void showSchedules() const;
    /**
     * @brief Responsible for display the occupation of the user request.
     *
     * This function receives an input from the user anf from there displays the occupation requested by the user.
     */
    void showOccupation() const;

    void processChange();
    void ucChangeOperation();
    void classChangeOperation();

    /**
     * @brief Transforms a class input in a class ID.
     *
     * This function receives a class (yLEICxx) and return an ID corresponding to that class.
     * This function is case insensitive and verifies if the input is valid.
     *
     * @return Returns a integer thar corresponds to a valid class ID.
     */
    int classIdRequest() const;
    /**
     * @brief Transforms a UC input in a UC ID.
     *
     * This function receives a UC (L.EICxxx/UPxxx) and return an ID corresponding to that UC.
     * This function is case insensitive and verifies if the input is valid.
     *
     * @return Returns a short thar corresponds to a valid UC ID.
     */
    short ucIdRequest() const;
    /**
     * @brief Transforms a UP number request in a UP number.
     *
     * This function receives a UP number(xxxxxxxx) corresponding to a student and return that same UP number.
     * This function is case insensitive and verifies if the input is valid.
     *
     * @return Returns a integer that corresponds to a student UP number.
     */
    int studentUpRequest() const;
    void addUcRequest();
    /**
     * @brief Transforms a UC and class input in a UC and class ID.
     *
     * This function uses the 'ucIdRequest' and 'classIdRequest' to receive both inputs.
     * This function is case insensitive and verifies if the input is valid.
     *
     * @return Returns a pair of numbers where the first is a class ID and the second one is a UC ID.
     */
    std::pair<int, short> class_ucRequest() const;
    /**
     * @brief Transforms the user input in a number.
     *
     * This function receives a user input as a string and verifies if it can be converted to a number from 1 to 9.
     * If it is not possible, then it will request a new input until it is able to convert to a number.
     *
     * @param s String corresponding to the user input.
     * @return Returns a number between 1 and 9.
     */
    short singleNumberRequest(std::string& s) const;
    /**
     * @brief Stops displaying new things until the user press 'y'.
     *
     * This function purpose is to be used in a situation where it's suppose to stop displaying new information until user says otherwise.
     *
     * @return Return a boolean value indicating if the user wants to continue the execution.
     */
    bool waitingState() const;
    /**
     * @brief Displays the schedule of a given student.
     *
     * This function takes a student ID as input, checks if the student is in the database, and then prints the
     * student's schedule. It utilizes methods from other classes to calculate and present the student's schedule.
     *
     * @param upNumber The student's ID to retrieve and display their schedule.
     */
    void showStudentSchedule(int upNumber) const;
    /**
     * @brief Displays the list of students belonging to a specific year.
     *
     * This method presents a list of students enrolled in a particular academic year, ordered according to the user's choice.
     * Sorting options are based on the 'sortAlgorithm' parameter:
     * - If 'sortAlgorithm' is 1, then is sorted by student UP number in ascending order.
     * - If 'sortAlgorithm' is 2, then is sorted by student UP number in descending order.
     * - If 'sortAlgorithm' is 3, then is sorted by student name in ascending order.
     * - If 'sortAlgorithm' is 4, then is sorted by student name in descending order.
     *
     * @param year The academic year for which the list of students is to be displayed.
     * @param sortAlgorithm Indicates the preferred sorting order for displaying student information.
     */
    void showStudentsPerYear(short year, short sortAlgotithm) const;
    /**
     * @brief Displays the list of students belonging to a specific class.
     *
     * This method presents a list of students enrolled in a particular class, ordered according to the user's choice.
     * Sorting options are based on the 'sortAlgorithm' parameter:
     * - If 'sortAlgorithm' is 1, then is sorted by student UP number in ascending order.
     * - If 'sortAlgorithm' is 2, then is sorted by student UP number in descending order.
     * - If 'sortAlgorithm' is 3, then is sorted by student name in ascending order.
     * - If 'sortAlgorithm' is 4, then is sorted by student name in descending order.
     *
     * @param classId The class ID for which the list of students is to be displayed.
     * @param sortAlgorithm Indicates the preferred sorting order for displaying student information.
     */
    void showStudentsPerClass(int classId, short sortAlgorithm) const;
    /**
     * @brief Displays the list of students enrolled in a specific UC.
     *
     * This method presents a list of students enrolled in a particular UC identified by its ID.
     *
     * @param ucId The ID of the UC for which the list of students is to be displayed.
     */
    void showStudentsPerUc(short ucId, short sortAlgorithm) const;
    /**
     * @brief Displays the list of students enrolled in at least a specified number of University Subjects (UC).
     *
     * This function presents a list of students who are enrolled in a minimum number of UC.
     *
     * @param numberOfUc The minimum number of UC a student must be enrolled in to be included.
     */
    void showStudentsIn_n_uc(int numberOfUc, short sortAlgorithm) const;
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
    /**
     * @brief Displays all students from the course LEIC.
     *
     * @param sortAlgorithm Indicates the order the students are going to be displayed.
     */
    void showAllStudents(short sortAlgorithm) const;
    void showAvailableUc(int upNumber) const;
    /**
     * @brief Displays all student that are simultaneous in a class and UC.
     *
     * @param classId Identifies the class.
     * @param ucId Identifies the UC.
     * @param sortAlgorithm Indicates the order the students are going to be displayed.
     */
    void showStudentsPerClassPerUc(int classId, short ucId, short sortAlgorithm) const;
    /**
     * @brief Displays the students that are enrolled in at least n UC.
     *
     * @param n Indicates the minimum number of UC the student must be enrolled.
     */
    void showUcWithGreaterOccupation(int n) const;
    /**
     * @brief Displays the schedule of a specific class.
     *
     * @param classId Indicates the class.
     */
    void showClassSchedule(int classId) const;
    /**
     * @brief Displays the schedule of a specific class.
     *
     * @param ucId Indicates the UC.
     */
    void showUcSchedule(short ucId) const;
    bool isPossibleAddUc(int upNumber) const;
    bool isPossibleAddClass() const;
    int classWithVacancy(short ucId, int upNumber);
    bool conflict(int upNumber, std::stack<std::pair<Subject, std::string>>& s) const;
    void removeUcRequest();
};

#endif //AED_PROJECT_APP_H
