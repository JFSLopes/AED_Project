#ifndef AED_PROJECT_DISPLAY_H
#define AED_PROJECT_DISPLAY_H

#include <iostream>
#include <list>
#include <string>
/**
 * @class Display
 * @brief Displays the interface
 *
 * This class displays all the options that the user can choose to manipulate the data
 *
 */
class Display{
private:
    const std::vector<std::string> l = {"Ascending UP number", "Descending UP number", "Ascending alphabetic order", "Descending alphabetic order"}; ///< stores the sorting options
public:
    static short sortAlgorithm; ///< stores a short that indicates the sort method chosen by the user
    /**
     * @brief displays the description of the API
     *
     */
    void description() const;
    /**
     * @brief displays the options of the main menu of the API
     *
     */
    void menu() const;
    /**
     * @brief displays the options that the user has to see schedules
     *
     */
    void schedule() const;
    /**
     * @brief displays the options that the user related to occupation
     *
     */
    void occupation() const;
    /**
     * @brief displays the sorting options that are available
     *
     */
    void sortOptions() const;
    /**
     * @brief displays the changes that the user can do about UC´s and classes
     *
     */
    void changes() const;
    /**
     * @brief displays the change options that the user can do about UC´s and classes
     * That options are add, remove or switch
     *
     * @param type Determines if the changes are related to UC's (type == 0) or to classes (type == 1)
     */
    void showchangeoptions(short type) const;
    /**
     * @brief displays the ways that the user can organize the data related to university year
     *
     */
    void yearDisplayOptions() const;
    /**
     *@brief displays the ways that the user can organize the data related to LEIC course
     *
     */
    void leicDisplayOption() const;
    /**
     *@brief displays the name of the file specifically chosen to store the changes and options about storing the changes made
     *
     */
    void storeDescription() const;
    /**
     * @brief displays the ways of storing changes made by user
     * The changes can be stored either in a specific file for changes or directly in the file used to see the data
     *
     */
    void askFileToStore() const;
};

#endif //AED_PROJECT_DISPLAY_H
