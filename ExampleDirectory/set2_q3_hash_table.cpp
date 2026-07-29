// Q3: Implement a hash table using hashing techniques and display the table after insertion.
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

const int TABLE_SIZE = 10;

int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

void insert(Node *table[], int key)
{
    int index = hashFunction(key);
    Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;

    if (table[index] == NULL)
    {
        table[index] = temp;
        return;
    }

    Node *current = table[index];
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = temp;
}

void display(Node *table[])
{
    cout << "Hash Table:\n";
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        cout << i << " -> ";
        Node *current = table[i];
        if (current == NULL)
        {
            cout << "EMPTY";
        }
        while (current != NULL)
        {
            cout << current->data;
            if (current->next != NULL)
            {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << '\n';
    }
}

int main()
{
    Node *table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = NULL;
    }

    int n, key;
    cout << "Enter number of keys: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter key " << i + 1 << ": ";
        cin >> key;
        insert(table, key);
    }

    display(table);
    return 0;
}