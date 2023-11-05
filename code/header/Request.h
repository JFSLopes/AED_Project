#ifndef AED_PROJECT_REQUEST_H
#define AED_PROJECT_REQUEST_H

#include <stack>
#include <iostream>
#include "Change.h"
/**
 * @class Request
 * @brief Manages and stores changes, providing functionality for adding, undoing, and inspecting changes.
 *
 * The Request class manages storing and handling changes made by the user.
 * It enables the addition of new changes, supports the ability to undo previous ones, and it allows to inspect the most recent change.
 */
class Request{
private:
    std::stack<Change*> changes; ///< Stores all the changes that were successfully done by the user.
public:
    /**
     * @brief This function adds a new change to the stack
     * @param change Change to be added to the stack.
     */
    void addStack(Change* change);
    /**
     * @brief Displays a message indicating the most recent change.
     *
     * This method allows the user to retrieve information about the most recent change made.
     * It displays a simple message providing details on the most recent change performed by the user.
     */
    void showMostRecent() const;
    /**
     * @brief Checks if the stack is empty.
     * @return True if stack is empty, False otherwise.
     */
    bool isEmpty() const;
    /**
     * @brief Undoes the most recent change, if available.
     *
     * If the stack of changes is not empty, indicating that there are changes present,
     * this method erases the most recent change. If the stack is empty, no action is taken.
     * It displays a message informing the user about the performed action.
     */
    void pop(bool delete_);
    /**
     * @brief Returns a pointer to the element on the top of the stack in case it exists.
     * @return Returns a pointer to the element on the top of the stack, aka, most recent change
     */
    Change* top() const;
    /**
     * @brief Deallocates all the dynamic memory used to store the changes
     */
    void clean();
};

#endif //AED_PROJECT_REQUEST_H
