#include "../header/App.h"
#include <fstream>
#include <iostream>
using namespace std;
App::App(string file1, string file2, string file3) : file1(file1), file2(file2), file3(file3) {}

/*
 * Reads and stores the classes and uc's
 */
void App::read_classes_per_uc(){
    ifstream in(file1);
    if(in.is_open()) cout << "Funcionou\n";
    string line;
    // Skip the header
    getline(in, line);
    while(getline(in, line)){
        string str1, str2;
        int pos = 0;
        // get the UC
        while(line[pos] != ','){
            str1 += line[pos];
            pos++;
        }
        pos++;
        // get the class
        while(pos < (int) line.size()-1){
            str2 += line[pos];
            pos++;
        }
        if(str1[0] == 'L'){
            int temp = stoi(str1.substr(5,3));
            if((int) vUc.size() < temp) vUc.push_back(Uc());
        }
        else{
            int temp = stoi(str1.substr(2,3));
            if((int) vUp.size() < temp) vUp.push_back(Uc());
        }

        int temp = stoi(str2.substr(5,2));
        // adds to the vector depending on the class year
        switch(str2[0]){
            case '1':
                if(vClass1.size() < temp) vClass1.push_back(Class());
                break;
            case '2':
                if(vClass2.size() < temp) vClass2.push_back(Class());
                break;
            case '3':
                if(vClass3.size() < temp) vClass3.push_back(Class());
                break;
        }
    }
    cout << vClass1.size() << endl;
    cout << vClass2.size() << endl;
    cout << vClass3.size() << endl;
    cout << vUp.size() << endl;
    in.close();
}

/*
 * Reads and stores the schedules for the classes
 */
void App::read_classes(){
    ifstream in(file2);
    if(in.is_open()) cout << "Funcionou 2\n";
    string line;
    getline(in, line);
    while(getline(in, line)){
        int pos = 0;
        string classCode, uc, weekDay, start, duration, type;
        while(line[pos] != ','){
            classCode += line[pos];
            pos++;
        }
        pos++;
        while(line[pos] != ','){
            uc += line[pos];
            pos++;
        }
        pos++;
        while(line[pos] != ','){
            weekDay += line[pos];
            pos++;
        }
        pos++;
        while(line[pos] != ','){
            start += line[pos];
            pos++;
        }
        pos++;
        while(line[pos] != ','){
            duration+= line[pos];
            pos++;
        }
        pos++;
        while(pos < (int)line.size() - 1){
            type+=line[pos];
            pos++;
        }
        char year = classCode[0];
        pos = stoi(classCode.substr(5,2));
        short UcNumber = uc[0] == 'L' ? stoi(uc.substr(5,3)) : stoi(uc.substr(2,3));
        Subject newSubject(UcNumber, type, stof(start), stof(duration));
        switch (year){
            case '1':
                vClass1[pos-1].completeSchedule(newSubject, weekDay);
                break;
            case '2':
                vClass2[pos-1].completeSchedule(newSubject, weekDay);
                break;
            case '3':
                vClass3[pos-1].completeSchedule(newSubject, weekDay);
                break;
        }
    }
}
void App::read_students(){
    ifstream in(file3);
    if(in.is_open()) cout << "Funcionou 3\n";
    string line;
    getline(in, line);
    int count = 1;
    bool firstIteration = true;
    int prevUP = 0;
    string prevName;
    list<pair<int,short>> class_uc;
    while(true){
        if(getline(in, line).eof()){
            Student student(prevUP, prevName);
            student.setclass_Uc(class_uc);
            students.insert(student);
            break;
        }
        count++;
        int pos = 0;
        string UPnumber, name, ucCode, classCode;
        while (line[pos] != ',') {
            UPnumber += line[pos];
            pos++;
        }
        pos++;
        while (line[pos] != ',') {
            name += line[pos];
            pos++;
        }
        pos++;
        while (line[pos] != ',') {
            ucCode += line[pos];
            pos++;
        }
        pos++;
        while (pos < (int)line.size() - 1) {
            classCode += line[pos];
            pos++;
        }
        int up = stoi(UPnumber);
        if(firstIteration){
            prevUP = up;
            firstIteration = false;
        }
        if(prevUP != up){
            Student student(prevUP, prevName);
            student.setclass_Uc(class_uc);
            class_uc.clear();
            students.insert(student);
            prevUP = up;
            prevName = name;
        }
        int classNumber = (classCode[0] - '0') * 100 + stoi(classCode.substr(5,2));
        short UcNumber = ucCode[0] == 'L' ? (short) stoi(ucCode.substr(5,3)) : (short) stoi(ucCode.substr(2,3));
        class_uc.push_back(make_pair(classNumber, UcNumber));
    }

    Schedule schedule;
    stack<pair<Subject,string>> temp;
    list<pair<int,short>> aux = students.begin()->getList();
    for(auto x : aux){
        vClass1[x.first-101].getUcScheduleFromSchedule(x.second, temp);
    }
    cout << "a\n";
    while(!temp.empty()){
        auto top = temp.top();
        schedule.addSubject(top.first, top.second);
        temp.pop();
    }
    schedule.print();
}

