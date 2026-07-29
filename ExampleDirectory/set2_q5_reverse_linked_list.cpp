// Q5: Implement a singly linked list and reverse the entire linked list.
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

    Node *reverseRecursive(Node *current, Node *previous)
    {
        if (current == NULL)
        {
            return previous;
        }
        Node *nextNode = current->next;
        current->next = previous;
        return reverseRecursive(nextNode, current);
    }

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

    void reverseList()
    {
        head = reverseRecursive(head, NULL);
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
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        list.insertEnd(value);
    }

    cout << "Original list: ";
    list.display();
    list.reverseList();
    cout << "Reversed list: ";
    list.display();
    return 0;
}