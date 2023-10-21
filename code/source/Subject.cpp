#include "../header/Subject.h"

using namespace std;
Subject::Subject(short UcNumber, string& type, float start, float duration)
                : UcNumber(UcNumber), type(type), startHour(start), duration(duration) {}

void Subject::show() const{
    cout << startHour << " | " << UcNumber << '(' << type << ')' << '|' << startHour + duration << '\n';
}

short Subject::getUcNumber() const{
    return UcNumber;
}

bool operator<(const Subject &a, const Subject &b){
    if(a.startHour < b.startHour) return true;
    else if(a.startHour == b.startHour and (a.type == "TP" or a.type == "PL")) return true;
    return false;
}

