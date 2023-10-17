#ifndef AED_PROJECT_SUBJECT_H
#define AED_PROJECT_SUBJECT_H

#include <string>
#include <iostream>

class Subject{
private:
    std::string name, type;
    float startHour, duration;
    short uc;
public:
    Subject(std::string& name,std::string& type, float start, float duration);
    void show();
};

#endif //AED_PROJECT_SUBJECT_H
