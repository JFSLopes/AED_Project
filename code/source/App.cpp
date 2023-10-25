#include "../header/App.h"
#include <fstream>
#include <iostream>
using namespace std;

void App::read_classes_per_uc(const string& fileName){
    ifstream in(fileName);
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
            if((int) vUc.size() < temp) vUc.push_back(Uc(temp));
        }
        else{
            int temp = stoi(str1.substr(2,3));
            if((int) vUp.size() < temp) vUp.push_back(Uc(temp + 100));
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
void App::read_classes(const string& fileName){
    ifstream in(fileName);
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
        // Caso seja UPxxx, é somando 100 para diferenciar da L.EIC001
        short UcNumber = uc[0] == 'L' ? stoi(uc.substr(5,3)) : stoi(uc.substr(2,3)) + 100;
        int classNumber = (classCode[0] - '0') * 100 + stoi(classCode.substr(5,2));
        Subject newSubject(UcNumber, type, stof(start), stof(duration));
        // Adicionar a disciplina ao horário da turma a que pertence
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
        // Guardar as turmas que têm a Uc, para depois ser possível calcular o horário da Uc
        // A condição indica se é UP ou L.EIC
        if(UcNumber / 100 == 0) vUc[UcNumber - 1].addClass(classNumber);
        else vUp[UcNumber%100 - 1].addClass(classNumber);
    }
    in.close();
}
void App::read_students(const string& fileName){
    ifstream in(fileName);
    if(in.is_open()) cout << "Funcionou 3\n";
    string line;
    getline(in, line);
    bool firstIteration = true;
    int prevUP;
    string prevName;
    string yearsEnrolled;
    // guarda a relação entre turma-uc para cada aluno
    list<pair<int,short>> class_uc;
    while(true){
        if(getline(in, line).eof()){
            Student student(prevUP, prevName);
            student.setclass_Uc(class_uc);
            students.insert(student);
            break;
        }
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
            prevName = name;
            firstIteration = false;
        }
        if(prevUP != up){
            Student student(prevUP, prevName);
            // adiciona as relações turma-uc para este estudante
            student.setclass_Uc(class_uc);
            // adiciona o/os anos em que o aluno tem cadeiras
            student.setEnrolledYears(yearsEnrolled);
            yearsEnrolled.clear();
            class_uc.clear();
            students.insert(student);
            prevUP = up;
            prevName = name;
        }
        int numClass = stoi(classCode.substr(5,2));
        // adiciona o aluno à turma
        switch (classCode[0]){
            case '1':
                vClass1[numClass-1].addStudent(prevUP);
                break;
            case '2':
                vClass2[numClass-1].addStudent(prevUP);
                break;
            case '3':
                vClass3[numClass-1].addStudent(prevUP);
                break;
        }
        if(ucCode[0] == 'L'){
            int pos = stoi(ucCode.substr(5,3));
            vUc[pos-1].addStudent(prevUP);
        }
        else if(ucCode[0] == 'U'){
            int pos = stoi(ucCode.substr(2,3));
            vUp[pos-1].addStudent(prevUP);
        }
        if (yearsEnrolled.size() == 0) yearsEnrolled = classCode[0];
        else if(yearsEnrolled.back() != classCode[0]) yearsEnrolled += classCode[0];
        // os valores são xyy onde x é o ano e yy o número da turma
        int classNumber = (classCode[0] - '0') * 100 + stoi(classCode.substr(5,2));
        // As UC's UP vão ser guardadas somando 100 para diferenciar da L.EIC001;
        short UcNumber = ucCode[0] == 'L' ? (short) stoi(ucCode.substr(5,3)) : (short) stoi(ucCode.substr(2,3))  + 100;
        class_uc.push_back(make_pair(classNumber, UcNumber));
    }
    showStudentsIn_n_uc(7);
    /*
    showStudentSchedule(202030247);
    cout << '\n';
    cout << '\n';
    vUp[0].showSchedule(vClass1, vClass2, vClass3);
    cout << '\n';
    cout << '\n';
    vUc[12].showClassesForUc();
    cout << '\n';
    cout << '\n';
    showStudentsPerYearByName('1');
    cout << '\n';
    cout << '\n';
    showStudentsPerClass('2', 10);
    cout << '\n';
    cout << '\n';
    showStudentsPerUc('L', 3);
    in.close();
     */
}

// Permite mostrar o horário de uma aluno
void App::showStudentSchedule(int upNumber){
    set<Student>::iterator itr = students.find(Student(upNumber));
    if(itr == students.end()){
        invalidUpNumber(upNumber);
        return;
    }
    itr->showSchedule(vClass1, vClass2, vClass3);
}

void App::invalidUpNumber(int up) {
    cout << "O número up introduzido, " << up << ", não existe na base de dados.\nIntrouza um up válido.";
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
    // Buscar os números up dos alunos
    if(year == '1') classStudents = vClass1[number-1].getStudents();
    else if(year == '2') classStudents = vClass2[number-1].getStudents();
    else classStudents = vClass3[number-1].getStudents();
    vector<Student> orderedByName;
    for (int x : classStudents){
        Student aux(x);
        aux = *(students.find(Student(x)));
        orderedByName.push_back(aux);
    }
    sortByName(orderedByName);
    for(const Student& x : orderedByName) x.showStudentData();
}

void App::showStudentsPerUc(char type, short number) const{
    cout << (type=='L' ? "L.EIC" : "UP") << setw(3) << setfill('0') << number << '\n';
    set<int> ucStudents;
    // Buscar os números up dos alunos
    if(type == 'L') ucStudents = vUc[number-1].getStudents();
    else ucStudents = vUp[number-1].getStudents();
    vector<Student> orderedByName;
    for (int x : ucStudents){
        Student aux(x);
        aux = *(students.find(Student(x)));
        orderedByName.push_back(aux);
    }
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

