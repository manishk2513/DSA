#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<vector<int>> buckets;
    int size;

public:
    HashTable(int tableSize) : size(tableSize) {
        buckets.resize(size);
    }

    int hashFunction(int key) const {
        return key % size;
    }

    void insert(int key) {
        int index = hashFunction(key);
        buckets[index].push_back(key);
        cout << key << " inserted at bucket " << index << "\n";
    }

    bool search(int key) const {
        int index = hashFunction(key);
        for (int value : buckets[index]) {
            if (value == key) {
                return true;
            }
        }
        return false;
    }

    void display() const {
        cout << "Hash Table:\n";
        for (int i = 0; i < size; i++) {
            cout << i << " : ";
            for (int value : buckets[i]) {
                cout << value << " -> ";
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    int size;
    cout << "Enter fixed hash table size: ";
    cin >> size;

    HashTable table(size);
    int choice;

    do {
        cout << "\n1. Insert\n2. Search\n3. Display\n4. Exit\nChoose: ";
        cin >> choice;

        if (choice == 1) {
            int key;
            cout << "Enter key: ";
            cin >> key;
            table.insert(key);
        } else if (choice == 2) {
            int key;
            cout << "Enter key to search: ";
            cin >> key;
            if (table.search(key)) {
                cout << "Key found.\n";
            } else {
                cout << "Key not found.\n";
            }
        } else if (choice == 3) {
            table.display();
        }
    } while (choice != 4);

    return 0;
}
