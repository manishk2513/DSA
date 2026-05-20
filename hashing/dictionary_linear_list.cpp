#include <iostream>
#include <vector>
using namespace std;

class Dictionary {
private:
    vector<pair<int, string>> entries;

public:
    void insert(int key, const string& value) {
        for (auto& entry : entries) {
            if (entry.first == key) {
                entry.second = value;
                cout << "Key " << key << " updated.\n";
                return;
            }
        }

        entries.push_back({key, value});
        cout << "Key " << key << " inserted.\n";
    }

    bool search(int key, string& value) const {
        for (const auto& entry : entries) {
            if (entry.first == key) {
                value = entry.second;
                return true;
            }
        }
        return false;
    }

    bool remove(int key) {
        for (auto it = entries.begin(); it != entries.end(); ++it) {
            if (it->first == key) {
                entries.erase(it);
                cout << "Key " << key << " removed.\n";
                return true;
            }
        }
        return false;
    }

    void display() const {
        cout << "Dictionary entries:\n";
        for (const auto& entry : entries) {
            cout << entry.first << " -> " << entry.second << '\n';
        }
    }
};

int main() {
    Dictionary dict;
    int choice;

    do {
        cout << "\n1. Insert\n2. Search\n3. Remove\n4. Display\n5. Exit\nChoose: ";
        cin >> choice;

        if (choice == 1) {
            int key;
            string value;
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter value: ";
            cin >> value;
            dict.insert(key, value);
        } else if (choice == 2) {
            int key;
            string value;
            cout << "Enter key to search: ";
            cin >> key;
            if (dict.search(key, value)) {
                cout << "Found: " << key << " -> " << value << '\n';
            } else {
                cout << "Key not found.\n";
            }
        } else if (choice == 3) {
            int key;
            cout << "Enter key to remove: ";
            cin >> key;
            if (!dict.remove(key)) {
                cout << "Key not found.\n";
            }
        } else if (choice == 4) {
            dict.display();
        }
    } while (choice != 5);

    return 0;
}
