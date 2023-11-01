#include "../header/Change.h"

using namespace std;

void Change::showChange() const {
    cout << "";
}


UcChange::UcChange(short operation, int upNumber, std::pair<int, short> prev, std::pair<int, short> change)
: operation(operation), upNumber(upNumber), prev(prev), change(change) {}

void UcChange::showChange() const{
    cout << "The most recent change has:\n";
    switch (operation){
        case 1: {
            cout << "\tAdded UC " << (change.second > 100 ? "UP" : "L.EIC") << right << setw(3) << setfill('0') << change.second%100
                 << " from class " << change.first/100 << "LEIC" << right << setw(2) << setfill('0') << change.first%100;
            break;
        }
        case 2: {
            cout << "\tRemoved UC " << (change.second > 100 ? "UP" : "L.EIC") << right << setw(3) << setfill('0') << change.second%100
                 << " from class " << change.first/100 << "LEIC" << right << setw(2) << setfill('0') << change.first%100;
            break;
        }
        case 3: {
            cout << "\tSwitch UC (" << (prev.second > 100 ? "UP" : "L.EIC") << right << setw(3) << setfill('0') << prev.second%100
                 << ") from class (" << prev.first/100 << "LEIC" << right << setw(2) << setfill('0') << prev.first%100 << ") to UC ("
                 << (change.second > 100 ? "UP" : "L.EIC") << right << setw(3) << setfill('0') << change.second%100
                 << ") from class (" << change.first/100 << "LEIC" << right << setw(2) << setfill('0') << change.first%100 << ")";
            break;
        }
    }
    cout << " for student " << upNumber << '\n';
}

short UcChange::getOperation() const{
    return operation;
}

std::pair<int, short> UcChange::getChange() const{
    return change;
}

std::pair<int, short> UcChange::getPrev() const{
    return prev;
}

int UcChange::getStudent() const{
    return upNumber;
}

void UcChange::setChange(std::pair<int, short> p){
    change = prev;
}


ClassChange::ClassChange(short operation, int upNumber, std::list<short> allUc, int prev, int change)
: operation(operation), upNumber(upNumber), allUc(allUc), prev(prev), change(change) {}

void ClassChange::showChange() const{
    cout << "The most recent change has:\n";
    switch (operation){
        case 1: {
            cout << "\tAdded UC { ";
            for(int x : allUc) cout << (x > 100 ? "UP" : "L.EIC") << right << setw(3) << setfill('0') << x << " ";
            cout << "} from class " << change/100 << "LEIC" << right << setw(2) << setfill('0') << change%100;
            break;
        }
        case 2: {
            cout << "\tRemoved UC { ";
            for(int x : allUc) cout << (x > 100 ? "UP" : "L.EIC") << right << setw(3) << setfill('0') << x << " ";
            cout << "} from class " << change/100 << "LEIC" << right << setw(2) << setfill('0') << change%100;
            break;
        }
        case 3: {
            cout << "\tSwitched UC { ";
            for(int x : allUc) cout << (x > 100 ? "UP" : "L.EIC") << right << setw(3) << setfill('0') << x << " ";
            cout << "} from class " << prev/100 << "LEIC" << right << setw(2) << setfill('0') << prev%100 << "to class "
                 << change/100 << "LEIC" << right << setw(2) << setfill('0') << change%100;
            break;
        }
    }
    cout << " for student " << upNumber << '\n';
}