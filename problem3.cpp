// create a class Student with attributes name and marks . 
// write a function getTopper(Student s) that compares the marks of the current object with another student s.
// The function should return the this pointer if the current object has higher marks or equal marks, otherwise return the pointer to student s.
// finally, display the details of the topper student.

#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int marks;
    // Student(string n, int m) : name(n), marks(m) {}
    Student* getTopper(Student s) {
        Student* p = &s;
        if (this->marks>= s.marks) {
            return this;
        } else {
            return p;
        }
    }
};

int main(){
    Student s1, s2;
    getline(cin>>ws, s1.name);
    cin >> s1.marks;
    getline(cin>>ws, s2.name);
    cin >> s2.marks;

    Student* s=s1.getTopper(s2);
    cout << "Topper details: " << s->name<<"\t Have higher marks " << s->marks << endl;
    return 0;
}