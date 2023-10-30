#ifndef AED_PROJECT_CHANGE_H
#define AED_PROJECT_CHANGE_H

#include <iostream>
#include <iomanip>
#include <list>

/**
 * @class Change
 * @brief Record the changes that were made by the user.
 */
class Change{
    public:
        virtual void showChange() const;
};

class UcChange : public Change{
    private:
        short operation; ///< 1 to Add, 2 to Remove and 3 to Switch
        std::pair<int, short> prev; ///< only used in switch
        std::pair<int, short> change;
    public:
        UcChange(short operation, std::pair<int, short> prev, std::pair<int, short> change);
        void showChange() const;
};

class ClassChange : public Change{
    private:
        short operation; ///< 1 to Add, 2 to Remove and 3 to Switch
        std::list<short> allUc;
        int change;
        int prev;
public:
        ClassChange(short operation, std::list<short> allUc, int change, int prev);
        void showChange() const;
};

#endif //AED_PROJECT_CHANGE_H
