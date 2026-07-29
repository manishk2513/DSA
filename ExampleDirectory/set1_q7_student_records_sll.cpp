// Q7: Store student records in a singly linked list and provide insert and display operations.
#include <iostream>
using namespace std;

struct Student
{
    int rollNo;
    char name[50];
};

struct Node
{
    Student data;
    Node *next;
};

class StudentList
{
private:
    Node *head;

public:
    StudentList() : head(NULL) {}

    void insertRecord(int rollNo, const char name[])
    {
        Node *temp = new Node;
        temp->data.rollNo = rollNo;
        int i = 0;
        while (name[i] != '\0' && i < 49)
        {
            temp->data.name[i] = name[i];
            i++;
        }
        temp->data.name[i] = '\0';
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            return;
        }
        Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
    }

    void display() const
    {
        if (head == NULL)
        {
            cout << "No student records available.\n";
            return;
        }
        cout << "Roll Number\tName\n";
        cout << "-----------\t----\n";
        Node *current = head;
        while (current != NULL)
        {
            cout << current->data.rollNo << "\t\t" << current->data.name << '\n';
            current = current->next;
        }
    }
};

int main()
{
    StudentList list;
    int n, rollNo;
    char name[50];

    cout << "Enter number of student records: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter roll number: ";
        cin >> rollNo;
        cout << "Enter name: ";
        cin >> name;
        list.insertRecord(rollNo, name);
    }

    cout << "\nStudent Records:\n";
    list.display();
    return 0;
}