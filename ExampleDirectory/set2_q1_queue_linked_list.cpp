// Q1: Implement a queue using a singly linked list with enqueue, dequeue, display, and empty handling.
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue() : front(NULL), rear(NULL) {}

    void enqueue(int value)
    {
        Node *temp = new Node;
        temp->data = value;
        temp->next = NULL;
        if (rear == NULL)
        {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is empty. Underflow.\n";
            return;
        }
        Node *temp = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete temp;
        cout << "Element deleted from queue.\n";
    }

    void display() const
    {
        if (front == NULL)
        {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue from front to rear:\n";
        Node *current = front;
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
    Queue queue;
    int choice, value;

    do
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            queue.enqueue(value);
            break;
        case 2:
            queue.dequeue();
            break;
        case 3:
            queue.display();
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}