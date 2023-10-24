#include "code/header/App.h"

using namespace std;

int main() {
    App app;
    app.read_classes_per_uc("/Users/joselopes/Desktop/AED_Project/schedule/classes_per_uc.csv");
    app.read_classes("/Users/joselopes/Desktop/AED_Project/schedule/classes.csv");
    app.read_students("/Users/joselopes/Desktop/AED_Project/schedule/students_classes.csv");
    return 0;
}
