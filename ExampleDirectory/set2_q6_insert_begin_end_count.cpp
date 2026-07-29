// Q6: Create a singly linked list with insertion at the beginning and end, and display the node count.
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;
    int count;

public:
    LinkedList() : head(NULL), count(0) {}

    void insertBeginning(int value)
    {
        Node *temp = new Node;
        temp->data = value;
        temp->next = head;
        head = temp;
        count++;
    }

    void insertEnd(int value)
    {
        Node *temp = new Node;
        temp->data = value;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            Node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = temp;
        }
        count++;
    }

    void display() const
    {
        if (head == NULL)
        {
            cout << "List is empty.\n";
            return;
        }
        Node *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << '\n';
    }

    int getCount() const
    {
        return count;
    }
};

int main()
{
    LinkedList list;
    int choice, value;

    do
    {
        cout << "\n1. Insert at beginning\n2. Insert at end\n3. Display\n4. Count nodes\n5. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertBeginning(value);
            cout << "List: ";
            list.display();
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertEnd(value);
            cout << "List: ";
            list.display();
            break;
        case 3:
            list.display();
            break;
        case 4:
            cout << "Total number of nodes: " << list.getCount() << '\n';
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}