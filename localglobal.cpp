#include <iostream>
using namespace std;

// Global variable declaration
int number = 100;

class Demo {
    private:
        int number = 200;  // Class member variable
    public:
        void display() {
            int number = 300;  // Local variable
            
            // Printing local variable
            cout << "Local variable number: " << number << endl;
            
            // Printing class member variable using this pointer
            cout << "Class member variable number: " << this->number << endl;
            
            // Printing global variable using scope resolution operator
            cout << "Global variable number: " << ::number << endl;
        }
};

int main() {
    Demo obj;
    obj.display();
    
    // Accessing global variable directly
    cout << "\nAccessing global number from main: " << ::number << endl;
    
    return 0;
}