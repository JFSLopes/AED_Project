#ifndef AED_PROJECT_SCHEDULE_H
#define AED_PROJECT_SCHEDULE_H

class Subject;

#include "Subject.h"
#include <list>
#include <set>
#include <map>
/**
 * @class Schedule
 * @brief stores information about schedules and manipulates it.
 *
 * This class stores the relevant information about schedules.
 * Allows to set, get and Display information.
 */
class Schedule{
private:
    ///< converts a string representing a certain week day to a short value.
    std::map<std::string, short> week{{"Monday", 1},
                                    {"Tuesday",2},
                                    {"Wednesday",3},
                                    {"Thursday",4},
                                    {"Friday",5}};
    std::list<Subject> mon; ///< stores the subjects of monday.
    std::list<Subject> tue; ///< stores the subjects of tuesday.
    std::list<Subject> wed; ///< stores the subjects of wednesday.
    std::list<Subject> thu; ///< stores the subjects of thursday.
    std::list<Subject> fri; ///< stores the subjects of friday.
public:
    /**
     * @brief adds a subject of a week day to a schedule.
     * @param subject The subject that will be added to a schedule.
     * @param day String that identifies which week day the Subject belongs.
     */
    void addSubject(Subject& subject, std::string day);
    /**
     * @brief displays the data related to a schedule.
     */
    void print() const;
    /**
     * @brief gets the schedule for a certain Uc.
     *
     * @param value Identifies an Uc.
     * @param s Stack that stores the Uc schedule.
     */
    void getUcSchedule(short ucId, std::stack<std::pair<Subject, std::string>>& s) const;
    /**
     * @brief fills the given stack with all the Uc's of  a certain schedule.
     * @param s stack that will be filled with the Uc's of a certain schedule.
     */
    void getUc(std::set<short>& s) const;
    /**
     * @brief checks if there is a conflict between schedules.
     * @param s schedule that is gonna be compared to check conflicts.
     * @return returns true if there was conflicts between schedules, false otherwise.
     */
    bool conflict(std::stack<std::pair<Subject, std::string>>& s) const;
    /**
     * @brief gets the Uc's related to a certain schedule.
     * @return returns a stack with the Uc's of a certain schedule.
     */
    std::set<short> getAllUc() const;
};

#endif //AED_PROJECT_SCHEDULE_H
