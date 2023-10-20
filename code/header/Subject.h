#ifndef AED_PROJECT_SUBJECT_H
#define AED_PROJECT_SUBJECT_H

#include <string>
#include <stack>
#include <iostream>

class Subject{
private:
    short UcNumber;
    std::string type;
    float startHour, duration;
    short uc;
public:
    Subject(short UcNumber, std::string& type, float start, float duration);
    void show();
    short getUcNumber();
};

#endif //AED_PROJECT_SUBJECT_H
