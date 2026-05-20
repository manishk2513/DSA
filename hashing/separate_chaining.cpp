#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key;
    Node* next;

    Node(int value) : key(value), next(nullptr) {}
};

class HashTable {
private:
    vector<Node*> table;
    int size;

public:
    HashTable(int s) : size(s) {
        table.resize(size, nullptr);
    }

    ~HashTable() {
        for (Node* head : table) {
            while (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
    }

    int hashFunction(int key) const {
        return key % size;
    }

    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;
        cout << key << " inserted at bucket " << index << "\n";
    }

    bool search(int key) const {
        int index = hashFunction(key);
        Node* current = table[index];

        while (current != nullptr) {
            if (current->key == key) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool remove(int key) {
        int index = hashFunction(key);
        Node* current = table[index];
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->key == key) {
                if (previous == nullptr) {
                    table[index] = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current;
                cout << key << " deleted from bucket " << index << "\n";
                return true;
            }
            previous = current;
            current = current->next;
        }

        return false;
    }

    void display() const {
        cout << "Hash Table with Separate Chaining:\n";
        for (int i = 0; i < size; i++) {
            cout << i << " : ";
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key << " -> ";
                current = current->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    int size;
    cout << "Enter hash table size: ";
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
            if (table.search(key)) {
                cout << "Key found.\n";
            } else {
                cout << "Key not found.\n";
            }
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
