#ifndef AED_PROJECT_DISPLAY_H
#define AED_PROJECT_DISPLAY_H

#include <iostream>
#include <list>
#include <string>

class Display{
private:
    const std::vector<std::string> l = {"Ascending UP number", "Descending UP number", "Ascending alphabetic order", "Descending alphabetic order"};
public:
    static short sortAlgorithm; ///< stores a short that indicates the sort method chosen by the user
    void description() const;

    void menu() const;

    void schedule() const;

    void occupation() const;

    void sortOptions() const;



    void classOcc() const;
    void ucOcc() const;
    void class_uc() const;
    void course() const;
    void nUc() const;
    void greaterOcc() const;

    void changes() const;
    void classChange() const;
    void UcChange() const;

    void undo() const;

};

#endif //AED_PROJECT_DISPLAY_H
