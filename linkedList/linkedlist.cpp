#include <iostream>
using namespace std;

// ─────────────────────────────────────────────
//  Node structure
// ─────────────────────────────────────────────
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// ─────────────────────────────────────────────
//  LinkedList class
// ─────────────────────────────────────────────
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // ── Destructor: free all nodes ─────────────
    ~LinkedList() {
        Node* curr = head;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    // ════════════════════════════════════════════
    //  1. TRAVERSAL
    // ════════════════════════════════════════════
    void traverse() const {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        cout << "List: ";
        Node* curr = head;
        while (curr) {
            cout << curr->data;
            if (curr->next) cout << " -> ";
            curr = curr->next;
        }
        cout << " -> NULL\n";
    }

    // ════════════════════════════════════════════
    //  2. INSERTION
    // ════════════════════════════════════════════

    // Insert at the beginning (head)
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << val << " inserted at beginning.\n";
    }

    // Insert at the end (tail)
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            cout << val << " inserted at end (list was empty).\n";
            return;
        }
        Node* curr = head;
        while (curr->next)
            curr = curr->next;
        curr->next = newNode;
        cout << val << " inserted at end.\n";
    }

    // Insert after a given position (0-indexed)
    void insertAtPosition(int val, int pos) {
        if (pos < 0) {
            cout << "Invalid position.\n";
            return;
        }
        if (pos == 0) {
            insertAtBeginning(val);
            return;
        }

        Node* curr = head;
        for (int i = 0; i < pos - 1 && curr; i++)
            curr = curr->next;

        if (!curr) {
            cout << "Position out of range. Inserting at end.\n";
            insertAtEnd(val);
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;
        cout << val << " inserted at position " << pos << ".\n";
    }

    // ════════════════════════════════════════════
    //  3. DELETION
    // ════════════════════════════════════════════

    // Delete from the beginning
    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << temp->data << " deleted from beginning.\n";
        delete temp;
    }

    // Delete from the end
    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        if (!head->next) {
            cout << head->data << " deleted from end.\n";
            delete head;
            head = nullptr;
            return;
        }
        Node* curr = head;
        while (curr->next->next)
            curr = curr->next;
        cout << curr->next->data << " deleted from end.\n";
        delete curr->next;
        curr->next = nullptr;
    }

    // Delete by value (first occurrence)
    void deleteByValue(int val) {
        if (!head) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        if (head->data == val) {
            deleteFromBeginning();
            return;
        }
        Node* curr = head;
        while (curr->next && curr->next->data != val)
            curr = curr->next;

        if (!curr->next) {
            cout << val << " not found in the list.\n";
            return;
        }
        Node* temp = curr->next;
        curr->next = temp->next;
        cout << temp->data << " deleted by value.\n";
        delete temp;
    }

    // Delete at a given position (0-indexed)
    void deleteAtPosition(int pos) {
        if (!head) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }
        if (pos == 0) {
            deleteFromBeginning();
            return;
        }
        Node* curr = head;
        for (int i = 0; i < pos - 1 && curr->next; i++)
            curr = curr->next;

        if (!curr->next) {
            cout << "Position out of range.\n";
            return;
        }
        Node* temp = curr->next;
        curr->next = temp->next;
        cout << temp->data << " deleted from position " << pos << ".\n";
        delete temp;
    }

    // ════════════════════════════════════════════
    //  4. SEARCHING
    // ════════════════════════════════════════════

    // Linear search — returns 0-based index or -1
    int search(int val) const {
        Node* curr = head;
        int index = 0;
        while (curr) {
            if (curr->data == val) {
                cout << val << " found at index " << index << ".\n";
                return index;
            }
            curr = curr->next;
            index++;
        }
        cout << val << " not found in the list.\n";
        return -1;
    }
};

// ─────────────────────────────────────────────
//  Main — demonstration
// ─────────────────────────────────────────────
int main() {
    LinkedList list;

    cout << "========================================\n";
    cout << "       LINKED LIST OPERATIONS DEMO      \n";
    cout << "========================================\n\n";

    // ── Insertion ────────────────────────────────
    cout << "--- Insertion ---\n";
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtBeginning(5);
    list.insertAtPosition(15, 2);   // insert 15 at index 2
    list.traverse();
    cout << "\n";

    // ── Traversal ────────────────────────────────
    cout << "--- Traversal ---\n";
    list.traverse();
    cout << "\n";

    // ── Searching ────────────────────────────────
    cout << "--- Searching ---\n";
    list.search(15);
    list.search(99);
    cout << "\n";

    // ── Deletion ─────────────────────────────────
    cout << "--- Deletion ---\n";
    list.deleteFromBeginning();
    list.traverse();

    list.deleteFromEnd();
    list.traverse();

    list.deleteByValue(15);
    list.traverse();

    list.deleteAtPosition(1);
    list.traverse();
    cout << "\n";

    cout << "========================================\n";
    cout << "              DEMO COMPLETE             \n";
    cout << "========================================\n";

    return 0;
}