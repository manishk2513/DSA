#include<iostream>
#include<string>
using namespace std;

class Person{
    private:
        string name;
        int age;

        public:
        void display(){
            cout<<"Name: "<<name<<endl;
            cout<<"Age: "<<age<<endl;
        }

        void setName(string name){
            this->name=name;
        }

        void setAge(int age){
            this->age=age;
        }
};


int main(){
    Person p;

    string name;
    int age;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    p.setName(name);
    p.setAge(age);
    p.display();

    return 0;
};