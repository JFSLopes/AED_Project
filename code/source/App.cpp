#include "../header/App.h"
#include <fstream>
#include <iostream>
using namespace std;

void App::inicialize(){
    openFiles();
    display.description();
    while(true){
        short option;
        display.menu();
        cin >> option;
        switch(option){
            case 1:
                showSchedules();
                break;
            case 2:
                showOccupation();
                break;
            case 3:
                processChange();
                break;
            case 6:
                return;
            default:
                cout << "The typed number id not valid.\n";
        }
    }
}

int App::studentUpRequest() const{
    int upNumber;
    while (true){
        cout << "Enter student up number: ";
        cin >> upNumber;
        if (students.find(upNumber) != students.end()) break;
        else cout << upNumber << " does not exist.\n";
    }
    return upNumber;
}

short App::ucIdRequest() const{
    string sUc;
    short ucId;
    while (true) {
        cout << "Enter the class (L.EICxxx / UPxxx): ";
        cin >> sUc;
        ucId = convertStringToUcId(sUc);
        if (ucId != -1) break;
        else cout << sUc << " does not exist.\n";
    }
    return ucId;
}

int App::classIdRequest() const{
    string sClass;
    int classId;
    while (true) {
        cout << "Enter the class (yLEICxx): ";
        cin >> sClass;
        classId = convertStringToClassId(sClass);
        if (classId != -1) break;
        else cout << sClass << " does not exist.\n";
    }
    return classId;
}

short App::singleNumberRequest(std::string& s) const{
    while(true){
        if(s.size() == 1 and (s[0] >= '0' and s[0] <= '9')) return (s[0] - '0');
        else{
            cout << "Invalid input: Enter a number from 1 to 9: ";
            cin >> s;
        }
    }
}

std::pair<int, short> App::class_ucRequest() const{
    int classId = classIdRequest();
    short ucId = ucIdRequest();
    return make_pair(classId, ucId);
}

bool App::waitingState() const {
    char ch;
    while (true) {
        cout << "Digit 'y' to keep using the API: ";
        cin >> ch;
        if (ch == 'y') return true;
    }
}

void App::showSchedules() const{
    while(true){
        string input;
        display.schedule();
        cin >> input;
        short option = singleNumberRequest(input);
        switch(option){
            case 1: {
                int upNumber = studentUpRequest();
                showStudentSchedule(upNumber);
                break;
            }
            case 2: {
                short ucId = ucIdRequest();
                showUcSchedule(ucId);
                break;
            }
            case 3: {
                int classId = classIdRequest();
                showClassSchedule(classId);
                break;
            }
            case 4:
                return;
            default:
                cout << "The typed number id not valid.\n";
                continue;
        }
        waitingState();
    }
}

void App::showOccupation() const{
    while(true){
        string input;
        display.occupation();
        cin >> input;
        short option = singleNumberRequest(input);
        switch (option){
            case 1: {
                int classId = classIdRequest();
                showStudentsPerClass(classId, Display::sortAlgorithm);
                break;
            }
            case 2: {
                short ucId = ucIdRequest();
                showStudentsPerUc(ucId, Display::sortAlgorithm);
                break;
            }
            case 3: {
                pair<int, short> class_uc = class_ucRequest();
                showStudentsPerClassPerUc(class_uc.first, class_uc.second, Display::sortAlgorithm);
                break;
            }
            case 4: {
                showAllStudents(Display::sortAlgorithm);
                break;
            }
            case 5: {
                short numberOfUc;
                cout << "The maximum UC a student can be simultaneous is 7. Choose the minimum number of UC the student is enrolled: ";
                string input;
                cin >> input;
                numberOfUc = singleNumberRequest(input);
                showStudentsIn_n_uc(numberOfUc, Display::sortAlgorithm);
                break;
            }
            ///< Needs to receive a number between 1 and 3
            case 6: {
                cout << "Choose a year (1<= year <= 3): ";
                string input;
                short year;
                while(true){
                    cin >> input;
                    year = singleNumberRequest(input);
                    if(year >= 1 and year <= 3) break;
                    else cout << "Choose a number from 1 to 3: ";
                }
                showStudentsPerYear(year, Display::sortAlgorithm);
                break;
            }
            ///< Needs to receive a number between 1 and 4
            case 7: {
                display.sortOptions();
                string input;
                while(true){
                    cin >> input;
                    int temp = singleNumberRequest(input);
                    if(temp >= 1 and temp<= 4){
                        Display::sortAlgorithm = temp - 1;
                        break;
                    }
                    else cout << "Invalid number. Enter a new one from 1 to 4: ";
                }
                break;
            }
            case 8: {
                return;
            }
        }
        waitingState();
    }
}

void App::processChange() const{
    // função que pede um up -> studentUpRequest();
    // função para um UC -> ucIdRequest();
    // Class -> classIdRequest();
}

int App::convertStringToClassId(std::string& s) const{
    if(s.size() != 7){
        cout  << s << " is not a valid Class.\n";
    }
    if(s[0] >= '1' and s[0] <= '3' and (s[1] == 'L' or s[1] == 'l') and (s[2] == 'E' or s[2] == 'e') and
      (s[3] == 'I' or s[3] == 'i') and (s[4] == 'C' or s[4] == 'c') and (s[5] >= '0' and s[5] <= '1') and
      (s[6] >= '0' and s[6] <= '9')) return (s[0] - '0') * 100 + (s[5] - '0') * 10 + (s[6] - '0');
    return -1;
}

short App::convertStringToUcId(std::string& s) const{
    if(s.size() == 8){
        if((s[0] == 'L' or s[0] == 'l') and (s[1] == '.') and (s[2] == 'E' or s[2] == 'e') and
           (s[3] == 'I' or s[3] == 'i') and (s[4] == 'C' or s[4] == 'c') and (s[5] == '0') and
           (s[6] >= '0' or s[6] <= '2') and (s[7] >= '0' or s[7] <= '5')) return (s[6] - '0') * 10 + (s[7] - '0');
    }
    if(s.size() == 5){
        if((s[0] == 'U' or s[0] == 'u') and (s[1] == 'P' or s[1] == 'p') and (s[2] == '0') and
           (s[3] == '0') and (s[4] == '1')) return 100 + (s[4] - '0');
    }
    return -1;
}

void App::openFiles(){
    string header;
    std::ifstream file1("/Users/joselopes/Desktop/AED_Project/schedule/classes_per_uc.csv");
    if(!file1.is_open()){
        cout << "Invalid name for file with classes and uc\n";
        return;
    }
    std::getline(file1, header);
    std::ifstream file2("/Users/joselopes/Desktop/AED_Project/schedule/classes.csv");
    if(!file2.is_open()){
        cout << "Invalid name for file with the schedule for a uc in a class\n";
        return;
    }
    std::getline(file2, header);
    std::ifstream file3("/Users/joselopes/Desktop/AED_Project/schedule/students_classes.csv");
    if(!file3.is_open()){
        cout << "Invalid name for file with students' information\n";
        return;
    }
    std::getline(file3, header);

    read_classes_per_uc(file1);
    read_classes(file2);
    read_students(file3);
}

void App::read_classes_per_uc(ifstream& in){
    string line;
    while(getline(in, line)){
        if(line[0] == 'L'){
            int temp = stoi(line.substr(5,3));
            if((int) vUc.size() < temp) vUc.push_back(Uc(temp));
        }
        else if(line[0] == 'U'){
            int temp = stoi(line.substr(2,3));
            ///< Adds a factor of 100 to differentiate L.EIC001 from UP001
            if((int) vUp.size() < temp) vUp.push_back(Uc(temp+100));
        }
        int pos = line.find(',') + 1;
        int classNumber = stoi(line.substr(pos + 5,2));
        ///< Constructs a new Class object if it isn't already there
        switch(line[pos]){
            case '1':
                if(vClass1.size() < classNumber) vClass1.push_back(Class());
                break;
            case '2':
                if(vClass2.size() < classNumber) vClass2.push_back(Class());
                break;
            case '3':
                if(vClass3.size() < classNumber) vClass3.push_back(Class());
                break;
        }
    }
    in.close();
}

void App::read_classes(ifstream& in){
    string line;
    while(getline(in, line)){
        int pos = 1, classId, ucId;
        float start, duration;
        string weekDay, hour, type;
        ///< get the class id
        classId = (line[0] - '0') * 100 + (line[5] - '0') * 10 + (line[6] - '0');
        while(line[pos] != ',') pos++;
        pos++;
        ///< get uc id
        if(line[pos] == 'L') ucId = (line[pos+6] - '0') * 10 + (line[pos+7] - '0');
        else ucId = 100 + (line[pos+3] -'0') * 10 + (line[pos+4] -'0');

        while(line[pos] != ',') pos++;
        pos++;
        while(line[pos] != ','){
            weekDay += line[pos];
            pos++;
        }
        pos++;
        while(line[pos] != ','){
            hour += line[pos];
            pos++;
        }
        start = stof(hour);
        hour.clear();
        pos++;
        while(line[pos] != ','){
            hour += line[pos];
            pos++;
        }
        duration = stof(hour);
        pos++;
        while(line[pos] >= 'A' and line[pos] <= 'Z'){
            type += line[pos];
            pos++;
        }
        Subject newSubject(ucId, type, start, duration);
        ///< Fill the class schedule
        switch (classId / 100){
            case 1:
                vClass1[(classId%100)-1].completeSchedule(newSubject, weekDay);
                break;
            case 2:
                vClass2[(classId%100)-1].completeSchedule(newSubject, weekDay);
                break;
            case 3:
                vClass3[(classId%100)-1].completeSchedule(newSubject, weekDay);
                break;
        }
        ///< store the classes that have the uc in an Uc object
        if(ucId <= 100) vUc[ucId - 1].addClass(classId);
        else vUp[ucId%100 - 1].addClass(classId);
    }
    in.close();
}


void App::read_students(ifstream& in){
    string line, prevName, yearsEnrolled;
    bool firstIteration = true;
    int prevUP;
    ///< Stores the class-uc relation
    list<pair<int,short>> class_uc;
    while(true){
        if(getline(in, line).eof()){
            Student student(prevUP, prevName);
            student.setclass_Uc(class_uc);
            students.insert(student);
            break;
        }
        int up = 0, classId, factor = 100000000, pos = 0;
        short  ucId;
        string name;
        while(line[pos] != ','){
            up += factor * (line[pos] - '0');
            factor/=10;
            pos++;
        }
        pos++;
        while (line[pos] != ',') {
            name += line[pos];
            pos++;
        }
        pos++;
        ///< get uc id
        if(line[pos] == 'L') ucId = (line[pos+6] - '0') * 10 + (line[pos+7] - '0');
        else ucId = 100 + (line[pos+3] -'0') * 10 + (line[pos+4] -'0');
        while (line[pos] != ',') pos++;
        pos++;
        ///< get the class id
        classId = (line[pos] - '0') * 100 + (line[pos+5] - '0') * 10 + (line[pos+6] - '0');

        if(firstIteration){
            prevUP = up;
            prevName = name;
            firstIteration = false;
        }
        if(prevUP != up){
            Student student(prevUP, prevName);
            student.setclass_Uc(class_uc);
            student.setEnrolledYears(yearsEnrolled);
            students.insert(student);
            prevUP = up;
            prevName = name;
            ///< reset variables
            yearsEnrolled.clear();
            class_uc.clear();
        }
        ///< Adds the student up number to the class is in
        switch (classId / 100){
            case 1:
                vClass1[classId%100-1].addStudent(prevUP);
                break;
            case 2:
                vClass2[classId%100-1].addStudent(prevUP);
                break;
            case 3:
                vClass3[classId%100-1].addStudent(prevUP);
                break;
        }
        ///< Adds the student up number to the uc is in
        if(ucId <= 100) vUc[ucId % 100 - 1].addStudent(prevUP);
        else vUp[ucId % 100 - 1].addStudent(prevUP);

        int year = classId/100;
        if (yearsEnrolled.size() == 0) yearsEnrolled = ('0' + year);
        else if(yearsEnrolled.back() != ('0' + year)) yearsEnrolled += ('0' + year);

        class_uc.push_back(make_pair(classId, ucId));
    }
    in.close();
}

void App::copySetOfIntToVector(const std::set<int>& s, std::vector<Student> &v) const{
    for (int x : s){
        v.push_back(*(students.find(x)));
    }
}

void App::copySetOfStudentsToVector(const std::set<Student> &s, std::vector<Student> &v) const{
    for(const Student& x : s) v.push_back(x);
}

void App::showStudentSchedule(int upNumber) const{
    set<Student>::iterator itr = students.find(upNumber);
    if(itr == students.end()){
        cout << "The up number " << upNumber << ", is not valid.\n";
        return;
    }
    itr->showSchedule(vClass1, vClass2, vClass3);
}

void App::showStudentsPerYear(short year, short sortAlgorithm) const{
    vector<Student> vStudents;
    switch(year){
        case 1:
            for(const Student& x : students)
                if(x.belongToYear(year + '0')) vStudents.push_back(x);
            break;
        case 2:
            for(const Student& x : students)
                if(x.belongToYear(year + '0')) vStudents.push_back(x);
            break;
        case 3:
            for(const Student& x : students)
                if(x.belongToYear(year + '0')) vStudents.push_back(x);
            break;
    }
    if(sortAlgorithm == 2 or sortAlgorithm == 3) sortByName(vStudents);

    if(sortAlgorithm == 0 or sortAlgorithm == 2) showStudents(vStudents);
    else reverseShowSudents(vStudents);
}

void App::sortByName(std::vector<Student> &v) const{
    auto comp = [] (const Student& a, const Student& b){
        if(a.getName() < b.getName()) return true;
        else if(a.getName() == b.getName() and a.getUpNumber() < b.getUpNumber()) return true;
        return false;};
    sort(v.begin(), v.end(), comp);
}

void App::showStudentsPerClass(int classId, short sortAlgorithm) const{
    int year = classId/100, number = classId%100;
    cout << "Class: " << year << "LEIC" << setw(2) << setfill('0') << number << '\n';
    set<int> sStudents;
    vector<Student> vStudents;
    if(year == '1') sStudents = vClass1[number-1].getStudents();
    else if(year == '2') sStudents = vClass2[number-1].getStudents();
    else sStudents = vClass3[number-1].getStudents();
    copySetOfIntToVector(sStudents, vStudents);
    if(vStudents.size() == 0){
        cout << "There is no student.\n";
        return;
    }

    if(sortAlgorithm == 2 or sortAlgorithm == 3) sortByName(vStudents);

    if(sortAlgorithm == 0 or sortAlgorithm == 2) showStudents(vStudents);
    else reverseShowSudents(vStudents);
}

void App::showStudentsPerUc(short ucId, short sortAlgorithm) const{
    cout << (ucId < 100 ? "L.EIC" : "UP") << setw(3) << setfill('0') << ucId%100 << '\n';
    set<int> sStudents;

    if(ucId < 100) sStudents = vUc[ucId%100-1].getStudents();
    else sStudents = vUp[ucId%100-1].getStudents();
    vector<Student> vStudents;
    copySetOfIntToVector(sStudents, vStudents);
    if(vStudents.size() == 0){
        cout << "There is no student.\n";
        return;
    }

    if(sortAlgorithm == 2 or sortAlgorithm == 3) sortByName(vStudents);

    if(sortAlgorithm == 0 or sortAlgorithm == 2) showStudents(vStudents);
    else reverseShowSudents(vStudents);
}

void App::showStudentsIn_n_uc(int numberOfUc, short sortAlgorithm) const{
    vector<Student> vStudents;
    for(const Student& x : students){
        if(x.getNumberOfUc() >= numberOfUc) vStudents.push_back(x);
    }
    if(vStudents.size() == 0){
        cout << "There is no student.\n";
        return;
    }
    if(sortAlgorithm == 2 or sortAlgorithm == 3) sortByName(vStudents);

    if(sortAlgorithm == 0 or sortAlgorithm == 2) showStudents(vStudents);
    else reverseShowSudents(vStudents);
}

void App::showClassFromUc(short ucId) const{
    if(ucId > 100) vUp[ucId%100 - 1].showClassesForUc();
    else vUc[ucId%100 - 1].showClassesForUc();
}

void App::showUcFromClass(int classId) const{
    switch (classId / 100){
        case 1:
            vClass1[classId%100 - 1].showAvailableUc();
            break;
        case 2:
            vClass2[classId%100 - 1].showAvailableUc();
            break;
        case 3:
            vClass3[classId%100 - 1].showAvailableUc();
            break;
    }
}

int App::getNumberOfStudentsInClass(int classId) const{
    switch (classId / 100){
        case 1:
            return vClass1[classId%100 - 1].getNumberOfStudents();
        case 2:
            return vClass2[classId%100 - 1].getNumberOfStudents();
        case 3:
            return vClass3[classId%100 - 1].getNumberOfStudents();
    }
    return -1;
}

void App::showStudentsPerClassPerUc(int classId, short ucId, short sortAlgorithm) const{
    set<int> studentsFromClass;
    switch (classId / 100){
        case 1:
            studentsFromClass = vClass1[classId%100 - 1].getStudents();
            break;
        case 2:
            studentsFromClass = vClass2[classId%100 - 1].getStudents();
            break;
        case 3:
            studentsFromClass = vClass3[classId%100 - 1].getStudents();
            break;
    }
    set<int> studentsFromUc;
    if(ucId > 100) studentsFromUc = vUp[ucId%100 - 1].getStudents();
    else studentsFromUc = vUc[ucId%100 - 1].getStudents();
    vector<int> common;
    set_intersection(studentsFromClass.begin(), studentsFromClass.end(),
                     studentsFromUc.begin(), studentsFromUc.end(),
                     std::back_inserter(common));
    vector<Student> vStudents;
    for(int x : common){
        auto itr = students.find(x);
        if((itr->class_uc(classId, ucId))) vStudents.push_back(*itr);
    }
    if(vStudents.size() == 0){
        cout << "There is no student.\n";
        return;
    }
    if(sortAlgorithm == 2 or sortAlgorithm == 3) sortByName(vStudents);

    if(sortAlgorithm == 0 or sortAlgorithm == 2) showStudents(vStudents);
    else reverseShowSudents(vStudents);
}

void App::showClassSchedule(int classId) const{
    switch (classId / 100){
        case 1:
            vClass1[classId%100 - 1].showSchedule();
            break;
        case 2:
            vClass2[classId%100 - 1].showSchedule();
            break;
        case 3:
            vClass3[classId%100 - 1].showSchedule();
            break;
    }
}

void App::showUcSchedule(short ucId) const{
    if(ucId > 100) vUp[ucId%100 - 1].showSchedule(vClass1, vClass2, vClass3);
    else vUc[ucId%100 - 1].showSchedule(vClass1, vClass2, vClass3);
}

void App::showUcWithGreaterOccupation(int n) const{

}

void App::showStudents(const std::vector<Student> &v) const{
    for(const Student& x : v) x.showStudentData();
}

void App::reverseShowSudents(const std::vector<Student> &v) const{
    auto itr = v.end() - 1;
    for(auto itr = v.end() - 1; itr >= v.begin(); itr--){
        itr->showStudentData();
    }
}

void App::showAllStudents(short sortAlgorithm) const{
    vector<Student> vStudents;
    copySetOfStudentsToVector(students, vStudents);
    if(vStudents.size() == 0){
        cout << "There is no student.\n";
        return;
    }

    if(sortAlgorithm == 2 or sortAlgorithm == 3) sortByName(vStudents);

    if(sortAlgorithm == 0 or sortAlgorithm == 2) showStudents(vStudents);
    else reverseShowSudents(vStudents);
}
