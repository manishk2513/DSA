// Q6: Implement deletion in a linked list by searching for a value and removing the matching node.
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

public:
    LinkedList() : head(NULL) {}

    void insertEnd(int value)
    {
        Node *temp = new Node;
        temp->data = value;
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

    void deleteValue(int value)
    {
        if (head == NULL)
        {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "Node deleted.\n";
            return;
        }
        Node *current = head;
        while (current->next != NULL && current->next->data != value)
        {
            current = current->next;
        }
        if (current->next == NULL)
        {
            cout << "Value not found.\n";
            return;
        }
        Node *temp = current->next;
        current->next = temp->next;
        delete temp;
        cout << "Node deleted.\n";
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
    LinkedList list;
    int n, value, del;

    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        list.insertEnd(value);
    }

    cout << "Current linked list: ";
    list.display();
    cout << "Enter value to delete: ";
    cin >> del;
    list.deleteValue(del);
    cout << "Updated linked list: ";
    list.display();

    return 0;
}