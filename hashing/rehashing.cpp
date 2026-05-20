#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<int> table;
    int size;
    int count;
    const double loadFactorThreshold;

    bool isPrime(int n) const {
        if (n < 2) {
            return false;
        }
        if (n == 2) {
            return true;
        }
        if (n % 2 == 0) {
            return false;
        }
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int nextPrime(int n) const {
        while (!isPrime(n)) {
            n++;
        }
        return n;
    }

    int hashFunction(int key) const {
        return key % size;
    }

    void rehash() {
        int newSize = nextPrime(size * 2);
        vector<int> oldTable = table;

        table.clear();
        table.resize(newSize, -1);
        int oldSize = size;
        size = newSize;
        count = 0;

        for (int i = 0; i < oldSize; i++) {
            if (oldTable[i] != -1) {
                insert(oldTable[i]);
            }
        }

        cout << "Table rehashed to new size " << size << '\n';
    }

public:
    HashTable(int initialSize, double threshold = 0.75)
        : size(nextPrime(initialSize)), count(0), loadFactorThreshold(threshold) {
        table.resize(size, -1);
    }

    double loadFactor() const {
        return static_cast<double>(count) / size;
    }

    void insert(int key) {
        if (loadFactor() >= loadFactorThreshold) {
            rehash();
        }

        int index = hashFunction(key);
        while (table[index] != -1 && table[index] != -2) {
            index = (index + 1) % size;
        }

        table[index] = key;
        count++;
        cout << key << " inserted at index " << index << '\n';
    }

    bool search(int key) const {
        int index = hashFunction(key);
        int start = index;

        while (table[index] != -1) {
            if (table[index] == key) {
                return true;
            }
            index = (index + 1) % size;
            if (index == start) {
                break;
            }
        }
        return false;
    }

    void display() const {
        cout << "Hash Table:\n";
        for (int i = 0; i < size; i++) {
            cout << i << " : ";
            if (table[i] == -1) {
                cout << "Empty";
            } else {
                cout << table[i];
            }
            cout << '\n';
        }
        cout << "Load Factor = " << loadFactor() << '\n';
    }
};

int main() {
    int initialSize;
    cout << "Enter initial table size: ";
    cin >> initialSize;

    HashTable table(initialSize);
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
            cout << (table.search(key) ? "Key found.\n" : "Key not found.\n");
        } else if (choice == 3) {
            table.display();
        }
    } while (choice != 4);

    return 0;
}
