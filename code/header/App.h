#ifndef AED_PROJECT_APP_H
#define AED_PROJECT_APP_H

#include <string>
#include <vector>
#include "../header/Uc.h"
#include "../header/Class.h"

class App{
private:
    std::string file1, file2, file3;
    std::vector<Uc> vUc;
    std::vector<Uc> vUp;
    std::vector<Class> vClass1;
    std::vector<Class> vClass2;
    std::vector<Class> vClass3;
public:
    App(std::string file1, std::string file2, std::string file3);
    void read_classes_per_uc();
    void read_classes();
};

#endif //AED_PROJECT_APP_H
