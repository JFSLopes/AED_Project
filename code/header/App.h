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
    /**
     * @brief stores all uc's of type L.EICxxx
     */
    std::vector<Uc> vUc; ///< stores all uc's of type L.EICxxx
    /**
     * @brief stores UPxxx uc
     */
    std::vector<Uc> vUp; ///< stores UPxxx uc
    /**
     * @brief stores all the classes from the first year
     */
    std::vector<Class> vClass1; ///< stores all the classes from the first year
    /**
     * @brief stores all the classes from the second year
     */
    std::vector<Class> vClass2; ///< stores all the classes from the second year
    /**
     * @brief stores all the classes from the third year
     */
    std::vector<Class> vClass3; ///< stores all the classes from the third year
    /**
     * @brief stores all students
     */
    std::set<Student> students; ///< stores all students

    void sortByName(std::vector<Student>& v) const;

public:
    /**
     * @brief shows a message in case up number is not valid
     * @param up The up number of a student
     */
    static void invalidUpNumber(int up);
    /**
     * @brief treats the information related to classes and uc
     *
     * This method reads the uc and classes from the file and fills the vector that are going to contain those
     * objects. Those object, at first, do not have any information.
     * Because classes are yLEICxxx, the method uses 'y' to decide in which vector (vClass1, vClass2, vClass3)
     * is going to store that class and the 'xxx' indicate the position on the vector.
     * Uc are either UPxxx or L.EICxxx so they are store in vUp and vUc respectively. 'xxx' indicates the position.
     *
     * @param fileName Name of the file where the information is in
     */
    void read_classes_per_uc(const std::string& fileName);
    void read_classes(const std::string& fileName);
    void read_students(const std::string& fileName);

    void showStudentSchedule(int upNumber);
    void showStudentsPerYear(char year) const;
    void showStudentsPerYearByName(char year) const;
    void showStudentsPerClass(char year, int number) const;
    void showStudentsPerUc(char type, short number) const;
};

#endif //AED_PROJECT_APP_H
