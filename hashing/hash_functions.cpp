#include <iostream>
#include <cmath>
using namespace std;

class HashFunctions {
private:
    int tableSize;

public:
    HashFunctions(int m) : tableSize(m) {}

    int divisionMethod(int key) const {
        return key % tableSize;
    }

    int multiplicationMethod(int key) const {
        const double A = 0.6180339887;
        double value = key * A;
        double fraction = value - floor(value);
        return static_cast<int>(tableSize * fraction);
    }

    int midSquareMethod(int key) const {
        long long square = 1LL * key * key;
        string s = to_string(square);

        if (s.size() <= 2) {
            return square % tableSize;
        }

        int mid = static_cast<int>(s.size() / 2);
        int len = static_cast<int>(to_string(tableSize).size());
        int start = mid - len / 2;

        if (start < 0) {
            start = 0;
        }
        if (start + len > static_cast<int>(s.size())) {
            return square % tableSize;
        }

        int middleValue = stoi(s.substr(start, len));
        return middleValue % tableSize;
    }
};

int main() {
    int tableSize;
    cout << "Enter table size (m): ";
    cin >> tableSize;

    HashFunctions hf(tableSize);

    int choice;
    do {
        cout << "\n1. Division / Modular Method\n2. Multiplication Method\n3. Mid-Square Method\n4. Exit\nChoose: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3) {
            int key;
            cout << "Enter key: ";
            cin >> key;

            if (choice == 1) {
                cout << "h(" << key << ") = " << key << " % " << tableSize << " = "
                     << hf.divisionMethod(key) << '\n';
            } else if (choice == 2) {
                cout << "Multiplication hash of " << key << " = "
                     << hf.multiplicationMethod(key) << '\n';
            } else {
                cout << "Mid-square hash of " << key << " = "
                     << hf.midSquareMethod(key) << '\n';
            }
        }
    } while (choice != 4);

    return 0;
}
