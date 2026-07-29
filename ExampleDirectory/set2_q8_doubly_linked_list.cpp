// Q8: Create a doubly linked list by inserting elements at the end and displaying the list.
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList() : head(NULL) {}

    void insertEnd(int value)
    {
        Node *temp = new Node;
        temp->data = value;
        temp->prev = NULL;
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
        temp->prev = current;
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
};

int main()
{
    DoublyLinkedList list;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        list.insertEnd(value);
    }

    cout << "Doubly linked list: ";
    list.display();
    return 0;
}