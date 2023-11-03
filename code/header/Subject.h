#ifndef AED_PROJECT_SUBJECT_H
#define AED_PROJECT_SUBJECT_H

#include <string>
#include <stack>
#include <iomanip>
#include <sstream>
#include <iostream>

/**
 * @class Subject
 * @brief Stores information related to a UC/class subject
 */
class Subject{
private:
    short UcId; ///< Indicates the UC ID.
    std::string type; ///< Indicates if a subject is (T), (TP), or (PL).
    float startHour, duration; ///< Indicates the starting and duration hour of the subject.
public:
    /**
     * @brief Constructor of Subject objects.
     * @param UcId Indicates the UC ID.
     * @param type Indicates if the subject is (T), (TP), or (PL).
     * @param start Indicates the start hour.
     * @param duration Indicates the duration.
     */
    Subject(short UcId, std::string& type, float start, float duration);
    /**
     * @bried Displays the content of this subject object.
     */
    void show() const;
    /**
     * @brief Returns the UC ID correspondent to this subject UC.
     * @return Returns the UC ID.
     */
    short getUcNumber() const;
    /**
     * @brief Return the type of this subject.
     * @return Returns the type of the subject.
     */
    std::string getType() const;
    /**
     * @brief Returns the start hour of this subject.
     * @return Return the start hour.
     */
    float getStartHour() const;
    /**
     * @brief Returns the suration of this subject.
     * @return Return duration.
     */
    float getEndHour() const;
    /**
     * @brief This function allows to sort schedules that are made of subjects.
     * @param a Object of Subject.
     * @param b Object of Subject.
     * @return Returns true if a is suppose to appear first, false otherwise.
     */
    friend bool operator<(const Subject& a, const Subject& b);
};

#endif //AED_PROJECT_SUBJECT_H
