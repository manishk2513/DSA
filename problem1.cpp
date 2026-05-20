
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int regNo;
    string name;
    string department;
    float marks[3];

public:
    // Setter functions
    void setRegNo(int reg) {
        regNo = reg;
    }

    void setName(string n) {
        name = n;
    }

    void setMarks(float m1, float m2, float m3) {
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    // Getter functions
    int getRegNo() {
        return regNo;
    }

    string getName() {
        return name;
    }

    string getDepartment() {
        return department;
    }

    float* getMarks() {
        return marks;
    }

    // Calculate total marks
    float calculateTotal() {
        return marks[0] + marks[1] + marks[2];
    }

    // Calculate average marks
    float calculateAverage() {
        return calculateTotal() / 3.0;
    }
};

int main() {
    Student s1;
    
    // Set student details
    s1.setRegNo(1001);
    s1.setName("John Doe");
    s1.setMarks(85.5, 90.0, 88.5);

    // Display student details
    cout << "Registration No: " << s1.getRegNo() << endl;
    cout << "Name: " << s1.getName() << endl;
    cout << "Marks: " << s1.getMarks()[0] << ", " 
         << s1.getMarks()[1] << ", " 
         << s1.getMarks()[2] << endl;
    cout << "Total Marks: " << s1.calculateTotal() << endl;
    cout << "Average Marks: " << s1.calculateAverage() << endl;

    return 0;
}