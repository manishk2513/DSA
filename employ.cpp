#include <iostream>
using namespace std;

class Employee {
private:
    int empId;
    string name, department;
    static int count;

public:
    Employee(int id, string n, string dept) {
        empId = id;
        name = n;
        department = dept;
        count++;
    }

    static int getCount() {
        return count;
    }

    void displayInfo() {
        cout << "Employee ID: " << empId << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
    }
};

// Initialize static member
int Employee::count = 50;  // Starting with 50 existing employees

int main() {
    int choice;
    
    while(true) {
        cout << "\n1. Add New Employee";
        cout << "\n2. Show Total Employee Count";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                int id;
                string name, dept;
                
                cout << "Enter Employee ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter Department: ";
                getline(cin, dept);

                Employee *emp = new Employee(id, name, dept);
                emp->displayInfo();
                break;
            }
            case 2:
                cout << "\nTotal number of employees: " << Employee::getCount() << endl;
                break;
            case 3:
                return 0;
            default:
                cout << "\nInvalid choice!" << endl;
        }
    }
    return 0;
}