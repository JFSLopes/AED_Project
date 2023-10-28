#include "code/header/App.h"
#include <fstream>

using namespace std;

int main(){
    App app;
    string header;
    std::ifstream file1("/Users/joselopes/Desktop/AED_Project/schedule/classes_per_uc.csv");
    if(!file1.is_open()){
        cout << "Invalid name for file with classes and uc\n";
        return 1;
    }
    std::getline(file1, header);
    std::ifstream file2("/Users/joselopes/Desktop/AED_Project/schedule/classes.csv");
    if(!file2.is_open()){
        cout << "Invalid name for file with the schedule for a uc in a class\n";
        return 1;
    }
    std::getline(file2, header);
    std::ifstream file3("/Users/joselopes/Desktop/AED_Project/schedule/students_classes.csv");
    if(!file3.is_open()){
        cout << "Invalid name for file with students' information\n";
        return 1;
    }
    std::getline(file3, header);

    app.read_classes_per_uc(file1);
    app.read_classes(file2);
    app.read_students(file3);
    return 0;
}
