#include "../header/Subject.h"

using namespace std;
Subject::Subject(short UcNumber, string& type, float start, float duration)
                : UcNumber(UcNumber), type(type), startHour(start), duration(duration) {}

void Subject::show() const{
    ostringstream name;
    name << (UcNumber > 100 ? "UP" : "L.EIC") << setw(3) << setfill('0') << (UcNumber % 100) << " (" << type << ")";
    cout << right << setw(5) << setfill(' ') << startHour << " | " << left <<setw(13) << setfill(' ') << left << name.str() << " | " << startHour + duration << '\n';
}

short Subject::getUcNumber() const{
    return UcNumber;
}

bool operator<(const Subject &a, const Subject &b){
    if(a.startHour == b.startHour and a.UcNumber == b.UcNumber and a.duration == b.duration and a.type == b.type) return false;
    if(a.startHour < b.startHour) return true;
    else if(a.startHour == b.startHour and (a.type == "TP" or a.type == "PL")) return true;
    return false;
}

std::string Subject::getType() const{
    return type;
}

float Subject::getStartHour() const{
    return startHour;
}

float Subject::getEndHour() const{
    return startHour + duration;
}

