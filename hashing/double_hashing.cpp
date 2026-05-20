#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    enum State { EMPTY, OCCUPIED, DELETED };

    struct Slot {
        int key;
        State state;
        Slot() : key(0), state(EMPTY) {}
    };

    vector<Slot> table;
    int size;

public:
    HashTable(int m) : size(m), table(m) {}

    int h1(int key) const {
        return key % size;
    }

    int h2(int key) const {
        return 1 + (key % (size - 1));
    }

    void insert(int key) {
        for (int i = 0; i < size; i++) {
            int index = (h1(key) + i * h2(key)) % size;
            if (table[index].state == EMPTY || table[index].state == DELETED) {
                table[index].key = key;
                table[index].state = OCCUPIED;
                cout << key << " inserted at index " << index << '\n';
                return;
            }
        }
        cout << "Hash table overflow.\n";
    }

    bool search(int key) const {
        for (int i = 0; i < size; i++) {
            int index = (h1(key) + i * h2(key)) % size;
            if (table[index].state == EMPTY) {
                return false;
            }
            if (table[index].state == OCCUPIED && table[index].key == key) {
                return true;
            }
        }
        return false;
    }

    bool remove(int key) {
        for (int i = 0; i < size; i++) {
            int index = (h1(key) + i * h2(key)) % size;
            if (table[index].state == EMPTY) {
                return false;
            }
            if (table[index].state == OCCUPIED && table[index].key == key) {
                table[index].state = DELETED;
                cout << key << " deleted from index " << index << '\n';
                return true;
            }
        }
        return false;
    }

    void display() const {
        cout << "Double Hashing Table:\n";
        for (int i = 0; i < size; i++) {
            cout << i << " : ";
            if (table[i].state == OCCUPIED) {
                cout << table[i].key;
            } else if (table[i].state == DELETED) {
                cout << "Deleted";
            } else {
                cout << "Empty";
            }
            cout << '\n';
        }
    }
};

int main() {
    int size;
    cout << "Enter table size: ";
    cin >> size;

    HashTable table(size);
    int choice;

    do {
        cout << "\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nChoose: ";
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
            cout << (table.search(key) ? "Key found.\n" : "Key not found.\n");
        } else if (choice == 3) {
            int key;
            cout << "Enter key to delete: ";
            cin >> key;
            if (!table.remove(key)) {
                cout << "Key not found.\n";
            }
        } else if (choice == 4) {
            table.display();
        }
    } while (choice != 5);

    return 0;
}
