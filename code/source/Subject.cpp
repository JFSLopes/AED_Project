#include "../header/Subject.h"

using namespace std;
Subject::Subject(short UcNumber, string& type, float start, float duration)
                : UcNumber(UcNumber), type(type), startHour(start), duration(duration) {}

void Subject::show() const{
    cout << startHour << setw(3) << setfill(' ') << " | ";
    // formata de acordo com o tipo de Uc
    cout << (UcNumber > 100 ? "UP" : "L.EIC") << setw(3) << setfill('0') << (UcNumber % 100);
    cout << " (" << type << ") " << setw(3) << setfill(' ') <<  "| " << startHour + duration << '\n';
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

