#ifndef AED_PROJECT_UC_H
#define AED_PROJECT_UC_H

class Class;

#include "Class.h"

/**
 * @class UC
 * @brief Manages all operations associated with UC, such as creating a schedule, get and set information.
 */
class Uc{
private:
    short UcId; ///< Represents the ID of a UC.
    std::set<int> students; ///< Stores all UP numbers of students that belong to this UC.
    std::set<int> classes; ///< Stores all classes ID that are associated with this UC.
    /**
     * @brief Calculates the schedule of this UC and returns it.
     * @param c1 Vector containing the first year classes.
     * @param c2 Vector containing the second year classes.
     * @param c3 Vector containing the third year classes.
     * @return Returns an object of Schedule
     */
    Schedule calculateSchedule(const std::vector<Class> &c1, const std::vector<Class> &c2, const std::vector<Class> &c3) const;

public:
    /**
     * @brief constructor for creating an object of UC.
     * @param id Indicates the ucId.
     */
    Uc(short id);
    /**
     * @brief Adds a new class to this UC.
     * @param classId Indicates the class ID.
     */
    void addClass(int classId);
    /**
     * @brief Adds a new students to this class.
     * @param upNumber Indicates The UP number of the student.
     */
    void addStudent(int upNumber);
    /**
     * @brief Removes a students to this class.
     * @param upNumber Indicates The UP number of the student.
     */
    void removeStudent(int upNumber);
    /**
     * @brief Shows the schedule of this UC.
     * @param c1 Vector containing the first year classes.
     * @param c2 Vector containing the second year classes.
     * @param c3 Vector containing the third year classes.
     */
    void showSchedule(const std::vector<Class> &c1, const std::vector<Class> &c2, const std::vector<Class> &c3) const;
    /**
     * @brief Return all students that belong to this UC.
     * @return Return a set of UP numbers.
     */
    std::set<int> getStudents() const;
    /**
     * @brief Returns the numbers of students enrolled in this UC.
     * @return Returns the number of students.
     */
    int numberStudents() const;
    /**
     * @brief Return the UC ID correspondent to this UC.
     * @return Return the UC ID.
     */
    short getId() const;
    /**
     * @brief Returns a set containing the classes from this UC.
     * @return Returns a set containing the classes.
     */
    std::set<int> getClasses() const;
    /**
     * @brief Compares to objects of Uc.
     * @param a Object of Uc.
     * @param b Object of Uc.
     * @return Returns true if the ID of a is less that the ID of b.
     */
    friend bool operator<(const Uc& a, const Uc& b);
};

#endif //AED_PROJECT_UC_H
