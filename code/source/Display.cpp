#include "../header/Display.h"

using namespace std;

short Display::sortAlgorithm = 0;

void Display::description() const{
    cout << "Welcome to the API that manages student, class, and schedule information from the LEIC course at FEUP.\n";
    cout << "It also allows changes, whenever possible, to the stored information. The inputs are case insensitive.\n";
    cout << "The API allows to:\n";
            cout << "\t-> see a student, class or uc schedule;\n";
            cout << "\t-> see a class, uc, course, uc in a class and in at least 'n' Uc occupation;\n";
            cout << "\t-> process a change in a student class or uc;\n";
            cout << "\t-> undo the most recent change made;\n";
}

void Display::menu() const{
    cout << "\nChoose an option by entering the corresponding number:\n"
         << "\t1. See a schedule\n"
         << "\t2. Check occupation\n"
         << "\t3. Process a change\n"
         << "\t4. Undo the most recent change\n"
         << "\t5. See description of API\n"
         << "\t6. Close API\n";
    cout << "[1..6]: ";
}

void Display::schedule() const{
    cout << "Choose an option by entering the corresponding number:\n"
         << "\t1. View a student schedule\n"
         << "\t2. View UC schedule\n"
         << "\t3. View class schedule\n"
         << "\t4. Return to the previous menu\n";
    cout << "[1..4]: ";
}

void Display::occupation() const{
    cout << "Current sort algorithm: " << l[sortAlgorithm] << ".\n";
    cout << "Choose an option by entering the corresponding number:\n"
         << "\t1. View occupation on a class\n"
         << "\t2. View occupation on a UC\n"
         << "\t3. View occupation on a UC from a class\n"
         << "\t4. View LEIC occupation\n"
         << "\t5. View occupation of students in at least n UC\n"
         << "\t6. View occupation in a specific year\n"
         << "\t7. Choose the sort algorithm\n"
         << "\t8. Return to the previous menu\n";
    cout << "[1..8]: ";
}

void Display::sortOptions() const{
    cout << "Choose an option by entering the corresponding number, it can be changed at any moment:\n"
         << "\t1. Sort by ascending student UP number\n"
         << "\t2. Sort by descending student UP number\n"
         << "\t3. Sort by ascending alphabetic order\n"
         << "\t4. Sort by descending alphabetic order\n";
    cout << "[1..4]: ";
}

void Display::changes() const {
    cout << "Choose an option by entering the corresponding number:\n"
         << "\t1. Change UC\n"
         << "\t2. Change class\n"
         << "\t3. Return to the previous menu\n";
    cout << "[1..3]: ";
}
