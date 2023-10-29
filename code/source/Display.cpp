#include "../header/Display.h"

using namespace std;

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
    cout << "\nChoose an option by entering the corresponding number[1..6]:\n"
         << "\t1. See a schedule\n"
         << "\t2. Check occupation\n"
         << "\t3. Process a change\n"
         << "\t4. Undo the most recent change\n"
         << "\t5. See description of API\n"
         << "\t6. Close API\n";
}

void Display::schedule() const{
    cout << "Choose an option by entering the corresponding number:\n"
         << "\t1. View a student schedule\n"
         << "\t2. View UC schedule\n"
         << "\t3. View class schedule\n"
         << "\t4. Return to the previous menu\n";
}
