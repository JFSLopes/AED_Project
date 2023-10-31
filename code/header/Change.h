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
    UcChange(short operation, std::pair<int, short> prev, std::pair<int, short> change);
    /**
     * @brief Displays information about the recorded changes.
     *
     * This method provides a simple but detailed information regarding the changes made by the user, displaying the operation and
     * the UCs and classes that were involved.
     */
    void showChange() const override;
};

class ClassChange : public Change{
private:
    short operation; ///< 1 to Add, 2 to Remove and 3 to Switch
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
    ClassChange(short operation, std::list<short> allUc, int prev, int change);
    /**
     * @brief Displays information about the recorded changes.
     *
     * This method provides a simple but detailed information regarding the changes made by the user, displaying the operation,
     * the classes involved as well the UCs that were also involved.
     */
    void showChange() const override;
};

#endif //AED_PROJECT_CHANGE_H
