#include "../header/Subject.h"

using namespace std;
Subject::Subject(short UcNumber, string& type, float start, float duration)
                : UcNumber(UcNumber), type(type), startHour(start), duration(duration) {}

void Subject::show(){
    cout << startHour << " | " << UcNumber << '(' << type << ')' << '|' << startHour + duration << '\n';
}

short Subject::getUcNumber(){
    return UcNumber;
}

