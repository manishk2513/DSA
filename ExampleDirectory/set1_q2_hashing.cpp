// Q2: Implement hashing by inserting keys into a hash table using a simple hash function and display the table.
#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;
const int EMPTY = -1;

int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

void displayTable(int table[])
{
    cout << "Hash Table:\n";
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        cout << i << " -> ";
        if (table[i] == EMPTY)
        {
            cout << "EMPTY";
        }
        else
        {
            cout << table[i];
        }
        cout << '\n';
    }
}

int main()
{
    int table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = EMPTY;
    }

    int n, key;
    cout << "Enter number of keys: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter key " << i + 1 << ": ";
        cin >> key;
        int index = hashFunction(key);
        int start = index;
        while (table[index] != EMPTY)
        {
            index = (index + 1) % TABLE_SIZE;
            if (index == start)
            {
                cout << "Hash table is full. Key " << key << " could not be inserted.\n";
                break;
            }
        }
        if (table[index] == EMPTY)
        {
            table[index] = key;
        }
    }

    displayTable(table);
    return 0;
}