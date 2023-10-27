#include "../header/App.h"
#include <fstream>
#include <iostream>
using namespace std;

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
    showUcFromClass(310);
    in.close();
}

void App::copySetOfIntToVector(const std::set<int>& s, std::vector<Student> &v) const{
    for (int x : s){
        Student aux(x);
        aux = *(students.find(Student(x)));
        v.push_back(aux);
    }
}

void App::copySetOfStudentsToVector(const std::set<Student> &s, std::vector<Student> &v) const{
    for(const Student& x : s) v.push_back(x);
}

void App::showStudentSchedule(int upNumber){
    set<Student>::iterator itr = students.find(Student(upNumber));
    if(itr == students.end()){
        cout << "O número up introduzido, " << upNumber << ", não existe na base de dados.\nIntrouza um up válido.";
        return;
    }
    itr->showSchedule(vClass1, vClass2, vClass3);
}



void App::showStudentsPerYear(char year) const{
    switch(year){
        case '1':
            for(const Student& x : students)
                if(x.belongToYear(year)) x.showStudentData();
            break;
        case '2':
            for(const Student& x : students)
                if(x.belongToYear(year)) x.showStudentData();
            break;
        case '3':
            for(const Student& x : students)
                if(x.belongToYear(year)) x.showStudentData();
            break;
    }
}

void App::sortByName(std::vector<Student> &v) const{
    auto comp = [] (const Student& a, const Student& b){
        if(a.getName() < b.getName()) return true;
        else if(a.getName() == b.getName() and a.getUpNumber() < b.getUpNumber()) return true;
        return false;};
    sort(v.begin(), v.end(), comp);
}

void App::showStudentsPerYearByName(char year) const{
    vector<Student> orderedByName;
    switch(year){
        case '1':
            for(const Student& x : students)
                if(x.belongToYear(year)) orderedByName.push_back(x);
            break;
        case '2':
            for(const Student& x : students)
                if(x.belongToYear(year)) orderedByName.push_back(x);
            break;
        case '3':
            for(const Student& x : students)
                if(x.belongToYear(year)) orderedByName.push_back(x);
            break;
    }
    sortByName(orderedByName);
    for(const Student& x : orderedByName) x.showStudentData();
}

void App::showStudentsPerClass(char year, int number) const{
    cout << "Class: " << year << "LEIC" << setw(2) << setfill('0') << number << '\n';
    set<int> classStudents;

    if(year == '1') classStudents = vClass1[number-1].getStudents();
    else if(year == '2') classStudents = vClass2[number-1].getStudents();
    else classStudents = vClass3[number-1].getStudents();

    vector<Student> orderedByName;
    copySetOfIntToVector(classStudents, orderedByName);
    sortByName(orderedByName);
    for(const Student& x : orderedByName) x.showStudentData();
}

void App::showStudentsPerUc(char type, short number) const{
    cout << (type=='L' ? "L.EIC" : "UP") << setw(3) << setfill('0') << number << '\n';
    set<int> ucStudents;

    if(type == 'L') ucStudents = vUc[number-1].getStudents();
    else ucStudents = vUp[number-1].getStudents();

    vector<Student> orderedByName;
    copySetOfIntToVector(ucStudents, orderedByName);
    sortByName(orderedByName);
    for(const Student& x : orderedByName) x.showStudentData();
}

void App::showStudentsIn_n_uc(int numberOfUc) const{
    vector<Student> orderedByName;
    for (const Student& x : students){
        orderedByName.push_back(x);
    }
    sortByName(orderedByName);
    for(const Student& x : orderedByName){
        if(x.getNumberOfUc() >= numberOfUc) x.showStudentData();
    }
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