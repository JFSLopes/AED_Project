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
 * @brief App reads from the files and stores the data.
 *
 * App reads the information about classes, uc's, students, schedule from files and stores it in the corresponding container.
 * After reading the files, reads inputs from the user and displays the information requested by the user.
 */
class App{
private:
    std::set<Uc> vUc; ///< stores all UC's of type L.EICxxx
    std::set<Uc> vUp; ///< stores UC's of type UPxxx
    std::vector<std::vector<short>> ucPerYear; ///< each position on the vector stores the UC's ID of an year
    std::vector<std::set<int>> classPerYear; ///< each position on the vector stores the classes' ID of an year
    std::vector<Class> vClass1; ///< stores all the classes from the first year
    std::vector<Class> vClass2; ///< stores all the classes from the second year
    std::vector<Class> vClass3; ///< stores all the classes from the third year
    std::set<Student> students; ///< stores all students
    Request requests; ///< stores the changes that were made.
    Display display; ///< it allows to call function that print useful information on console
    /**
     * @brief Receives a students vector and orders that same vector by student's name
     *
     * @param v Vector that is going to be ordered
     */
    void sortByName(std::vector<Student>& v) const;
    /**
     * @brief Copies a set to a vector.
     *
     * Receives a set of UP numbers and fills a vector with the students related to the UP numbers on the set.
     *
     * @param s Set containing the up number of students
     * @param v Vector that is going to be filled with the students
     * @complexity O(n) where 'n' is the number of elements on the set.
     */
    void copySetOfIntToVector(const std::set<int>& s, std::vector<Student>& v) const;
    /**
     * @brief Copies a set to a vector.
     *
     * Receives a set of students and fills a vector with the students from the set.
     *
     * @param s Set containing the Students.
     * @param v Vector that is going to be filled with the students.
     * @complexity O(n) where 'n' is the number of elements on the set.
     */
    void copySetOfStudentsToVector(const std::set<Student>& s, std::vector<Student>& v) const;
    /**
     * @brief Converts a string to a class ID.
     *
     * This function checks if the given string can be converted to a class ID. If possible returns the ID otherwise return -1.
     *
     * @param s String that represents the class.
     * @return Return an integer representing the id of the class or -1 if class does not exist.
     */
    int convertStringToClassId(std::string& s) const;
    /**
     * @brief Converts a string to an UC ID.
     *
     * This function checks if the given string can be converted to an UC ID. If possible returns the ID otherwise return -1.
     *
     * @param s String that represents the UC.
     * @return Return a short representing the id of the UC or -1 if UC does not exist.
     */
    short convertStringToUcId(std::string& s) const;
    /**
     * @brief Displays the students.
     *
     * This function displays the students from the vector according to the sort algorithm in use.
     *
     * @param vStudents Vector of students.
     * @param sortAlgorithm Represents the chosen sorting algorithm for displaying students.
     */
    void showStudents(std::vector<Student>& vStudents, short sortAlgorithm) const;
    /**
     * @brief Display the students.
     *
     * Displays the students from a vector that is already ordered according to the user's need, right to left.
     *
     * @param v Vector to be displayed.
     */
    void normalShowStudents(const std::vector<Student>& v) const;
    /**
     * @brief Display the students.
     *
     * Displays the students from a vector that is already ordered according to the user's need, left to right.
     *
     * @param v Vector to be displayed.
     */
    void reverseShowSudents(const std::vector<Student>& v) const;
    /**
     * @brief Reverts the changes.
     *
     * This function reverts the most recent change made by the user when requested and eliminates that changes from the data set.
     */
    void undoChange();

public:
    /**
     * @brief Constructs objects of App.
     *
     * This constructor is used to create objects of App, that allows it to start the execution.
     */
    App();
    /**
     * @brief Opens the necessary files and calls functions to read them.
     *
     * This function is responsible for opening the files containing information and invoking other functions that are
     * tasked with reading the data.
     */
    void openFiles();
    /**
     * @brief Closes the program.
     *
     * This function handles the necessary operations to terminate the application, perform cleanup activities, and provides
     * the user with options regarding the stored information.
     */
    void closeApp();
    /**
     * @brief Stores the changes.
     *
     * This function is responsible for storing the information in a CSV file specifically designed for preserving these changes.
     * It offers the functionality to either overwrite the existing file with new changes or append the new changes, based on the parameter.
     *
     * @param append Specifies whether to append the new changes to the existing file. If true, the changes will be appended, if false, the file will be overwritten.
     */
    void storeChanges(bool append);
    /**
     * @brief Reads information about classes and UC from the given file and organizes the data into appropriate vectors.
     *
     * @param file An input file stream containing information about classes and UCs.
     * @complexity O(n.log m) where n is the number of lines and m is the number of UC or classes.
     */
    void read_classes_per_uc(std::ifstream& file);
    /**
     * @brief Processes schedule information for classes.
     *
     * This method reads schedule data for classes from the given input file stream, including start and end hour, weekdays, and corresponding UC.
     * It utilizes this information to generate schedules for each class.
     *
     * @param file Input file stream containing schedule information for UCs.
     * @complexity O(n.log m) where 'n' is the number of lines and 'm' is the number of UCs.
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
     * @complexity O(n.log m) where 'n' is the number of lines and 'm' is the number of UCs.
     */
    void read_students(std::ifstream& file);
    /**
     * @brief Initiates the API execution.
     *
     * This function triggers the execution of functions responsible for reading files and interacting with the user to manage API operations.
     */
    void inicialize();
    /**
     * @brief Displays requested schedules based on user input.
     *
     * This function receives user input to determine the desired schedule and displays the corresponding information.
     */
    void showSchedules() const;
    /**
     * @brief Displays the requested occupation.
     *
     * This function receives user input to determine the desired occupation and displays the corresponding information.
     */
    void showOccupation() const;
    /**
     * @brief Handles changes based.
     *
     * This function serves as a coordinator, calling other methods to manage and implement changes made by the user.
     */
    void processChange();
    /**
     * @brief Deals with a UC change request.
     *
     * This function deals with all 3 UC changes options by calling the correct method for each scenario.
     */
    void ucChangeOperation();
    /**
     * @brief Deals with a class change request.
     *
     * This function deals with all 3 classes changes options by calling the correct method for each scenario.
     */
    void classChangeOperation();
    /**
     * @brief Transforms a class input into a class ID.
     *
     * This function takes a class (in the format yLEICxx) as input and returns the corresponding ID for that class.
     * The function is case-insensitive and verifies the validity of the input.
     *
     * @return An integer representing a valid class ID. If the input is invalid, the return value indicates an error state.
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
    /**
     * @brief Displays students based on enrollment criteria.
     *
     * This function displays students who are enrolled in at least the specified number of UC.
     * The displayed order of students is determined by the chosen sort algorithm.
     *
     * @param numberOfUc Minimum number of UCs the students must be enrolled in to be displayed.
     * @param sortAlgorithm Represents the chosen sorting algorithm for displaying students.
     */
    void studentsIn_n_UC(int numberOfUc, short sortAlgorithm) const;
    /**
     * @brief Reverts the most recent change if possible.
     */
    void undoRequest();
    /**
     * @brief Tries to add an UC to a student.
     *
     * This function is going to add, if possible, a new UC to a given student.
     */
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
     * @brief Transforms user input into a number between 1 and 9.
     *
     * This function takes a string as user input and verifies if it can be converted into a number within the range of 1 to 9.
     * If the conversion is not possible, the function requests new input until a valid number within the specified range is obtained.
     *
     * @param s The string corresponding to the user input.
     * @return A number between 1 and 9 derived from the user input.
     */
    short singleNumberRequest(std::string& s) const;
    /**
     * @brief Pauses displaying new information.
     *
     * This function stops the display of new information until the user initiates continuation.
     *
     * @return A boolean value indicating if the user wants to continue the execution. 'true' if the user inputs 'y', 'false' otherwise.
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
     *
     * @param year The academic year for which the list of students is to be displayed.
     * @param sortAlgorithm Represents the chosen sorting algorithm for displaying students.
     * @param showMessage Indicates if it is suppose to show a message.
     */
    void showStudentsPerYear(short year, short sortAlgorithm, bool showMessage) const;
    /**
     * @brief Displays the list of students belonging to a specific class.
     *
     * This method presents a list of students enrolled in a particular class, ordered according to the user's choice.
     *
     * @param classId The class ID for which the list of students is to be displayed.
     * @param sortAlgorithm Represents the chosen sorting algorithm for displaying students.
     * @param calledDirectly Indicates if the method needs to show the option to the user.
     */
    void showStudentsPerClass(int classId, short sortAlgorithm, bool calledDirectly) const;
    /**
     * @brief Displays the list of students enrolled in a specific UC.
     *
     * This method presents a list of students enrolled in a particular UC identified by its ID.
     *
     * @param ucId The ID of the UC for which the list of students is to be displayed.
     * @param sortAlgorithm Represents the chosen sorting algorithm for displaying students.
     */
    void showStudentsPerUc(short ucId, short sortAlgorithm) const;
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
     * @param sortAlgorithm Represents the chosen sorting algorithm for displaying students.
     */
    void showAllStudents(short sortAlgorithm) const;
    /**
     * @brief Displays the UC's a student is enrolled in.
     * @param upNumber Represents a student UP number.
     */
    void showAvailableUc(int upNumber) const;
    /**
     * @brief Displays students attending a specific class and UC simultaneously.
     *
     * This function showcases students who are enrolled both in a particular class and a designated UC, sorted by the specified algorithm.
     *
     * @param classId Identifies the class.
     * @param ucId Identifies the UC.
     * @param sortAlgorithm Represents the chosen sorting algorithm for displaying students.
     */
    void showStudentsPerClassPerUc(int classId, short ucId, short sortAlgorithm) const;
    /**
     * @brief Displays students enrolled in at least 'n' UC.
     *
     * This function displays students who are enrolled in a minimum of 'n' UC.
     *
     * @param n Indicates the minimum number of UCs a student must be enrolled in to be displayed.
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
    /**
     * @brief Returns if the student can be add to a new UC.
     * @param upNumber Indicates the UP number of a student.
     * @return Return true the student has less the 7 UC, false otherwise.
     * @complexity O(lon n).
     */
    bool isPossibleAddUc(int upNumber) const;
    /**
     * @brief Check if there is a class that can accept the given student.
     *
     * This function checks if the class capacity is not full, if there are no schedule conflicts and if the classes are balanced.
     * If these 3 condition are verified then it returns the class ID of the class the student will be added.
     *
     * @param ucId Indicates the UC ID.
     * @param upNumber Indicates the student UP number.
     * @return Returns -1 if there is no class available or the class ID if it can be added.
     */
    int classWithVacancy(short ucId, int upNumber);
    /**
     * @brief Checks for schedule conflicts.
     *
     * This function will check for schedules conflicts.
     * A conflict can only happen if the student has 2 classes at the same time. The classes have to be TP and PL or any combination of these 2.
     *
     * @param upNumber Indicates the student UP number.
     * @param s Stores the schedule of given UC.
     * @return Returns true if there is no schedule conflict, false otherwise.
     */
    bool conflict(int upNumber, std::stack<std::pair<Subject, std::string>>& s) const;
    /**
     * @brief Removes a student UC.
     *
     * This function removes a UC from a given student, if possible.
     */
    void removeUcRequest();
    /**
     * @brief Switches a student UC.
     *
     * This function switches a UC from a given student for another, if possible.
     */
    void switchUcRequest();
    /**
     * @brief Displays the UC.
     * @param ucId Indicates the UC ID.
     */
    void showUc(short ucId) const;
    /**
     * @brief Displays the class.
     * @param classId Indicates the class ID.
     */
    void showClass(int classId) const;
    /**
     * @brief Common students in a given class and UC.
     *
     * This function calculates the students that belong both to a class and a UC.
     *
     * @param classId Indicates the class ID.
     * @param ucId Indicates the UC ID.
     * @return Returns a vector of students.
     */
    std::vector<Student> intersectClassUc(int classId, short ucId) const;
    /**
     * @brief Reverts an UC add.
     * @param ptr Pointer to an UC change.
     */
    void revertUcAdd(UcChange* ptr);
    /**
     * @brief Checks if the classes are balanced.
     * @param ucId Indicates the UC ID.
     * @param classId Indicates the class ID.
     * @param add Indicates if the operation is an add if true or a remove if false.
     * @return Returns true if the classes are balanced or if the add does not make the balance worst, false otherwise.
     */
    bool isBalanced(short ucId, int classId, bool add) const;
    /**
     * @brief Reverts an UC remove.
     * @param ptr Pointer to an UC change.
     */
    void revertUcRemove(UcChange* ptr);
    /**
     * @brief Uploads the file 'changes.csv'.
     *
     * This function reads and uploads the 'changes.csv' and changes the current information according to the stored changes.
     */
    void readStoredChanged();
    /**
     * @brief Tries to add a class to a student.
     *
     * This function is going to add all the UC from a given class that the student does have yet, if possible.
     */
    void addClassRequest();
    /**
     * @brief Tries to remove a class from a student.
     *
     * This function is going to remove all UC from the student schedule that belong to the class that is being erased.
     */
    void removeClassRequest();
    /**
     * @brief Tries to switch classes in a student.
     *
     * This function is going to replace all UCs from the student schedule that belong to the class that is being erased
     * for the sames UCs from another class.
     */
    void switchClassRequest();
    /**
     * @brief Reverts a class add.
     * @param ptr Pointer to a class change.
     */
    void revertClassAdd(ClassChange* ptr);
    /**
     * @brief Reverts a class remove.
     * @param ptr Pointer to a class change.
     */
    void revertClassRemove(ClassChange* ptr);
    /**
     * @brief Reverts a class switch.
     * @param ptr Pointer to a class change.
     */
    void revertClassSwitch(ClassChange* ptr);
    /**
     * @brief Uploads a class change.
     *
     * This functions uploads the changes contained in the class change related to a switch without creating a new change.
     *
     * @param change Class change that is being uploaded.
     */
    void uploadClassAdd(ClassChange change);
    /**
     * @brief Uploads a class change.
     *
     * This functions uploads the changes contained in the class change related to a switch without creating a new change.
     *
     * @param change Class change that is being uploaded.
     */
    void uploadClassRemove(ClassChange change);
    /**
     * @brief Uploads a class change.
     *
     * This functions uploads the changes contained in the class change related to a switch without creating a new change.
     *
     * @param change Class change that is being uploaded.
     */
    void uploadClassSwitch(ClassChange change);
};

#endif //AED_PROJECT_APP_H
