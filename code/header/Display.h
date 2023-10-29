#ifndef AED_PROJECT_DISPLAY_H
#define AED_PROJECT_DISPLAY_H

#include <iostream>

class Display{
public:
    void description() const;

    void menu() const;

    void schedule() const;
    void student() const;
    void classSchedule() const;
    void ucSchedule() const;

    void occupation() const;
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
