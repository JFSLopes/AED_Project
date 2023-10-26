#ifndef AED_PROJECT_APP_H
#define AED_PROJECT_APP_H

#include <string>
#include <vector>
#include <set>
#include <iomanip>
#include "Uc.h"
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
    /**
     * @brief receives a Students vector and orders that same vector by student's name
     *
     * @param v Vector that is going to be ordered
     */
    void sortByName(std::vector<Student>& v) const;
    void copySetOfIntToVector(const std::set<int>& s, std::vector<Student>& v) const;
    void copySetOfStudentsToVector(const std::set<Student>& s, std::vector<Student>& v) const;

public:
    /**
     * @brief treats the information related to classes and uc
     *
     * This method reads line by line the uc and classes from the file and fills the vector that are going to contain those
     * objects. The vectors used are vClass1, vClass2, vClass3 for classes and vUp, vUc for the UC.
     * Because classes are yLEICxxx, the method uses 'y' to decide in which vector (vClass1, vClass2, vClass3)
     * is going to store that class and the 'xxx' indicate the position on the vector.
     * Uc are either UPxxx or L.EICxxx so they are store in vUp and vUc respectively. 'xxx' indicates the position.
     *
     * @param fileName Name of the file where the information is in
     */
    void read_classes_per_uc(std::ifstream& file);
    /**
     * @brief treats the information related to the schedule of UC
     *
     * This method reads line by line the start and end hour of an UC, the weekday of and the corresponding class.
     * It uses this information to create the schedules for each class and completes the classes on the classes'
     * vectors.
     *
     * @param fileName Name of the file where the information is in
     */
    void read_classes(std::ifstream& file);
    /**
     * @brief treats the information related to the schedule of UC
     *
     * This method reads line by line the start and end hour of an UC, the weekday of and the corresponding class.
     * It uses this information to create the schedules for each class and completes the classes on the classes'
     * vectors.
     *
     * @param fileName Name of the file where the information is in
     */
    void read_students(std::ifstream& file);

    void showStudentSchedule(int upNumber);
    void showStudentsPerYear(char year) const;
    void showStudentsPerYearByName(char year) const;
    void showStudentsPerClass(char year, int number) const;
    void showStudentsPerUc(char type, short number) const;
    void showStudentsIn_n_uc(int numberOfUc) const;
    void showClassFromUc(short ucId) const;
};

#endif //AED_PROJECT_APP_H
