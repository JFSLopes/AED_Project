#include <iostream>
#include "code/header/App.h"

using namespace std;
#define PATH /Users/joselopes/Desktop/AED_Project/schedule
int main() {
    string path = "/Users/joselopes/Desktop/AED_Project/schedule/";
    App app(path + "classes_per_uc.csv", path + "classes.csv", " ");
    app.read_classes_per_uc();
    app.read_classes();
    return 0;
}
