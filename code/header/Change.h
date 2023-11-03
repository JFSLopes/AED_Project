#ifndef AED_PROJECT_CHANGE_H
#define AED_PROJECT_CHANGE_H

#include <iostream>
#include <iomanip>
#include <list>

/**
 * @class Change
 * @brief Represents changes made by the user.
 *
 * This base class serves as an abstraction for recording changes and as common interface for different types of changes (UcChange and ClassChange).
 * Its primary purpose is to enable storing both UcChange and ClassChange instances within a unified structure.
 */
class Change{
public:
    /**
     * @brief Displays a default message.
     *
     * This function is not supposed to be directly invoked as it does not provide specific information.
     * Its overriding implementations in derived classes offer details about the recorded changes.
     */
     virtual void showChange() const;
};

class UcChange : public Change{
private:
    short operation; ///< 1 to Add, 2 to Remove and 3 to Switch.
    int upNumber; ///< Stores the students Up.
    std::pair<int, short> prev; ///< Only used in switch and records the class and UC that were switched.
    std::pair<int, short> change; ///< Stores the new class and UC.

public:
    /**
     * @brief Constructor of UcChange's object.
     *
     * This constructor initializes all the parameters according to the user operation request.
     *
     * @param operation Initializes parameter operation.
     * @param prev Initializes parameter prev, in case of an Add or Remove it is initialize to {0,0}.
     * @param change Initialize parameter change.
     */
    UcChange(short operation, int upNumber, std::pair<int, short> prev, std::pair<int, short> change);
    /**
     * @brief Displays information about the recorded changes.
     *
     * This method provides a simple but detailed information regarding the changes made by the user, displaying the operation and
     * the UCs and classes that were involved.
     */
    void showChange() const override;
    /**
     * @brief Indicates the operation correspondent to the change.
     * @return Return a short where 1 means add, 2 means remove and 3 mean switch.
     */
    short getOperation() const;
    /**
     * @brief Indicates UP number of the student.
     * @return Returns an integer correspondent to the student UP number.
     */
    int getStudent() const;
    /**
     * @brief Only used for switches and indicates the previous class and UC the student was before the change.
     * @return Return a pair that contains the class and UC.
     */
    std::pair<int, short> getPrev() const;
    /**
     * @brief Indicates the class and UC that were changed.
     * @return Return a pair that contains the class and UC.
     */
    std::pair<int, short> getChange() const;
    /**
     * @brief Changes the current value stored in 'change' to 'p'.
     * @param p Indicates the pair of class and UC that is going to replace the pair stored in 'change'.
     */
    void setChange(std::pair<int, short> p);
};

class ClassChange : public Change{
private:
    short operation; ///< 1 to Add, 2 to Remove and 3 to Switch.
    int upNumber; ///< Stores the students Up.
    std::list<short> allUc; ///< Stores all the UC that were involved in the operation.
    int prev; ///< Only used in switch and stores the class that was switched.
    int change; ///< Stores the new class.

public:
    /**
     * @brief Constructor of ClassChange's object.
     *
     * This constructor initializes all the parameters according to the user operation request.
     *
     * @param operation Initializes parameter operation.
     * @param allUc Initializes parameter allUc.
     * @param change Initializes parameter change.
     * @param prev Initializes parameter prev.
     */
    ClassChange(short operation, int upNumber, std::list<short> allUc, int prev, int change);
    /**
     * @brief Displays information about the recorded changes.
     *
     * This method provides a simple but detailed information regarding the changes made by the user, displaying the operation,
     * the classes involved as well the UCs that were also involved.
     */
    void showChange() const override;
    /**
     * @brief Returns a list with all UC that were part of any of the class changes.
     * @return Returns a list with the UC that were part of the operation.
     */
    std::list<short> getUc() const;
    /**
     * @brief Indicates the UP number of the student associated with the change.
     * @return Returns the UP number of the student.
     */
    int getStudent() const;
    /**
     * @brief Indicates the operation correspondent to the change.
     * @return Return a short where 1 means add, 2 means remove and 3 mean switch.
     */
    short getOperation() const;
    /**
     * @brief Indicates the class associated with the change.
     * @return Returns an integer correspondent to the class.
     */
    int getChange() const;
    /**
     * @brief Only used in switches, indicates the class that was changed.
     * @return Returns an integer correspondent to the new class.
     */
    int getPrev() const;
};

#endif //AED_PROJECT_CHANGE_H
