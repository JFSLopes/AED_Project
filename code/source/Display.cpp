#include "../header/Display.h"

using namespace std;

short Display::sortAlgorithm = 0;

void Display::description() const{
    cout << "Welcome to the API that manages student, class, and schedule information from the LEIC course at FEUP.\n";
    cout << "It also allows changes, whenever possible, to the stored information. The inputs are case insensitive.\n";
    cout << "The API allows to:\n";
            cout << "\t-> see a student, class or uc schedule;\n";
            cout << "\t-> see the occupation in a class, UC, course, UC in a class and in at least 'n' UC;\n";
            cout << "\t-> process a change in a student class or uc;\n";
            cout << "\t-> undo the most recent change made;\n";
            cout << "\t-> store the changes in a file that can be uploaded in the future;\n";
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
         << "\t7. View the n UC with greater occupation\n"
         << "\t8. Choose the sort algorithm\n"
         << "\t9. Return to the previous menu\n";
    cout << "[1..9]: ";
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

void Display::showchangeoptions(short type) const {
    if (type == 0){
        cout << "Choose an option by entering the corresponding number:\n"
                << "\t1. Add a new UC\n"
                << "\t2. Remove a current UC\n"
                << "\t3. Switch Uc's\n"
                << "\t4. Return to the previous menu\n";
    }
    else{
        cout << "Choose an option by entering the corresponding number:\n"
             << "\t1. Add a new Class\n"
             << "\t2. Remove a current Class\n"
             << "\t3. Switch Classes\n"
             << "\t4. Return to the previous menu\n";
    }
    cout << "[1..4]: ";
}

void Display::yearDisplayOptions() const{
    cout << "Choose an option by entering the corresponding number:\n"
         << "\t1. Show the students in each UC from the chosen year\n"
         << "\t2. Show the students in each class from the chosen year\n"
         << "\t3. Show the students in each class per UC from the chosen year\n"
         << "\t4. Show the students from the chosen year\n";
    cout << "[1..4]: ";
}

void Display::leicDisplayOption() const{
    cout << "Choose an option by entering the corresponding number:\n"
         << "\t1. Show the students in each year\n"
         << "\t2. Show the students in each class from the LEIC course\n"
         << "\t3. Show the students in each UC from LEIC course\n"
         << "\t4. Show the students in each year organized by classes\n"
         << "\t5. Show the students in each year organized by UC\n"
         << "\t6. Show the students in each year organized by UC from the classes\n"
         << "\t7. Show all students with no formation\n"
         << "\t8. Return to the previous menu\n";
    cout << "[1..8]: ";
}

void Display::storeDescription() const{
    cout << "The changes are going to be stored in a file called 'changes.csv'.\n"
         << "If the file does not exist yet or you only want to store the new changes digit '1'.\n"
         << "If you want keep the previous changes and the new ones digit '2'.\n";
    cout << "[1..2]: ";
}
