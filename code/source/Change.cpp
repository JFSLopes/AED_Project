#include "../header/Change.h"

using namespace std;

void Change::showChange() const {
    cout << "ok";
}


UcChange::UcChange(short operation, std::pair<int, short> prev, std::pair<int, short> change)
: operation(operation), prev(prev), change(change) {}

void UcChange::showChange() const{
    cout << "The most recent change has:\n";
    switch (operation){
        case 1: {
            cout << "\tAdded UC " << (change.second > 100 ? "UP" : "L.EIC") << setw(3) << setfill('0') << change.second % 100
                 << "from class " << change.first / 100 << "LEIC" << setw(2) << setfill('0') << change.first %100 << '\n';
            break;
        }
        case 2: {
            cout << "\tRemoved UC " << (change.second > 100 ? "UP" : "L.EIC") << setw(3) << setfill('0') << change.second % 100
                 << "from class " << change.first / 100 << "LEIC" << setw(2) << setfill('0') << change.first %100 << '\n';
            break;
        }
        case 3: {
            cout << "\tSwitch UC (" << (prev.second > 100 ? "UP" : "L.EIC") << setw(3) << setfill('0') << prev.second % 100
                 << ") from class (" << prev.first / 100 << "LEIC" << prev.first %100 << ") to UC ("
                 << (change.second > 100 ? "UP" : "L.EIC") << setw(3) << setfill('0') << change.second % 100
                 << "from class " << change.first / 100 << "LEIC" << setw(2) << setfill('0') << change.first %100 << '\n';
            break;
        }
    }
}


ClassChange::ClassChange(short operation, std::list<short> allUc, int change, int prev)
: operation(operation), allUc(allUc), change(change), prev(prev) {}

void ClassChange::showChange() const{
    cout << "The most recent change has:\n";
    switch (operation){
        case 1: {
            cout << "\tAdded UC { ";
            for(int x : allUc) cout << (x > 100 ? "UP" : "L.EIC") << setw(3) << setfill('0') << x << " ";
            cout << "} from class " << change/100 << "LEIC" << change%100 << '\n';
            break;
        }
        case 2: {
            cout << "\tRemoved UC { ";
            for(int x : allUc) cout << (x > 100 ? "UP" : "L.EIC") << setw(3) << setfill('0') << x << " ";
            cout << "} from class " << change/100 << "LEIC" << change%100 << '\n';
            break;
        }
        case 3: {
            cout << "\tSwitched UC { ";
            for(int x : allUc) cout << (x > 100 ? "UP" : "L.EIC") << setw(3) << setfill('0') << x << " ";
            cout << "} from class " << prev/100 << "LEIC" << prev%100 << "to class " << change/100 << "LEIC" << change%100 << '\n';
            break;
        }
    }
}