#include "../header/Subject.h"

using namespace std;
Subject::Subject(string& name, string& type, float start, float duration)
                : name(name), type(type), startHour(start), duration(duration) {}

void Subject::show(){
    cout << startHour << " | " << name << '(' << type << ')' << '|' << startHour + duration << '\n';
}

