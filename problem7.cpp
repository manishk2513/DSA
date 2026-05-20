#include <iostream>
using namespace std;

class Distance {
    int meters;
    float centimeters;

public:
    // Conversion constructor from float (total centimeters)
    Distance(float total_cm) {
        meters = static_cast<int>(total_cm / 100);
        centimeters = total_cm - meters * 100;
    }

    void display() const {
        cout << meters << " meters and " << centimeters << " centimeters" << endl;
    }
};

int main() {
    cout << "Enter total distance in centimeters (as float): ";
    float total_cm;
    cin >> total_cm;

    Distance d = total_cm;  // Implicit conversion using constructor
    cout << "Converted distance: ";
    d.display();

    return 0;
}

