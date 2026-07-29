// Q1: Implement a stack using a singly linked list with push, pop, display, and underflow handling.
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack() : top(NULL) {}

    void push(int value)
    {
        Node *temp = new Node;
        temp->data = value;
        temp->next = top;
        top = temp;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack underflow. Stack is empty.\n";
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
        cout << "Element deleted from stack.\n";
    }

    void display()
    {
        if (top == NULL)
        {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack from top to bottom:\n";
        Node *current = top;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << '\n';
    }
};

int main()
{
    Stack stack;
    int choice, value;

    do
    {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            stack.display();
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}