#include "../header/Subject.h"

using namespace std;
Subject::Subject(short UcId, string& type, float start, float duration)
                : UcId(UcId), type(type), startHour(start), duration(duration) {}

void Subject::show() const{
    ostringstream name;
    name << (UcId > 100 ? "UP" : "L.EIC") << right << setw(3) << setfill('0') << (UcId % 100) << " (" << type << ")";
    cout << right << setw(5) << setfill(' ') << startHour << " | " << left <<setw(13) << setfill(' ') << left << name.str() << " | " << startHour + duration << '\n';
}

short Subject::getUcNumber() const{
    return UcId;
}

bool operator<(const Subject &a, const Subject &b){
    if(a.startHour == b.startHour and a.UcId == b.UcId and a.duration == b.duration and a.type == b.type) return false;
    if(a.startHour < b.startHour) return true;
    else if(a.startHour == b.startHour and a.duration < b.duration) return true;
    else if(a.startHour == b.startHour and a.duration == b.duration and (a.UcId < b.UcId)) return true;
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

