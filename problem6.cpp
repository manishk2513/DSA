#include <iostream>
#include <iomanip>

using namespace std;

class Time {
    public:
    int h;
    int m;

public:
    Time(int hh, int mm) : h(hh), m(mm) {}


    bool isValid() const {
        return h >= 0 && h < 24 && m >= 0 && m < 60;
    }

    bool canDecrement() const {
        return !(h == 0 && m == 0);
    }

    void decrementOneMinute() {
        if (m == 0) {
            m = 59;
            h = (h == 0) ? 23 : h - 1;
        } else {
            --m;
        }
    }

    Time &operator--() {
        decrementOneMinute();
        return *this;
    }

    void print() const {
        cout << setfill('0') << setw(2) << h << ':' << setw(2) << m;
        cout << setfill(' ');
    }
};

int main() {
    cout << "Enter time (HH:MM): ";
    int h = 0;
    int m = 0;
    char colon = '\0';

    if (!(cin >> h >> colon >> m) || colon != ':') {
        cout << "Invalid format. Expected HH:MM." << endl;
        return 1;
    }

    Time t(h, m);
    if (!t.isValid()) {
        cout << "Invalid time. Hours must be 0-23 and minutes 0-59." << endl;
        return 1;
    }

    cout << "Original time: ";
    t.print();
    cout << endl;

    if (!t.canDecrement()) {
        cout << "Time cannot be decremented further." << endl;
        return 0;
    }

    --t;
    cout << "After decrement: ";
    t.print();
    cout << endl;

    return 0;
}
