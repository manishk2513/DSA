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
//  Stack class — dynamic linked list implementation
// ─────────────────────────────────────────────
class Stack {
private:
    Node* head;      // always points to the TOP of the stack
    int   size;      // tracks current number of elements

public:
    // ── Constructor ───────────────────────────────
    Stack() : head(nullptr), size(0) {}

    // ── Destructor: free all heap nodes ───────────
    ~Stack() {
        while (!isEmpty())
            pop();
        cout << "  [Destructor]  All nodes freed.\n";
    }

    // ════════════════════════════════════════════
    //  isEmpty() — O(1)
    //  Stack is empty when head == nullptr
    // ════════════════════════════════════════════
    bool isEmpty() const {
        return head == nullptr;
    }

    // ════════════════════════════════════════════
    //  push(value) — O(1)
    //  Allocate new node → point it to current head
    //  → make it the new head (top)
    //
    //   new node  →  old top  →  ...  →  nullptr
    // ════════════════════════════════════════════
    void push(int value) {
        Node* newNode = new (nothrow) Node(value);  // nothrow: no exception on failure
        if (!newNode) {
            cout << "  [Heap Exhausted]  Cannot push " << value
                 << " — no memory available.\n";
            return;
        }
        newNode->next = head;   // link new node to old top
        head = newNode;         // update top to new node
        size++;
        cout << "  push(" << value << ")  →  top = " << head->data
             << "  |  size = " << size << "\n";
    }

    // ════════════════════════════════════════════
    //  pop() — O(1)
    //  Save head → advance head to next
    //  → delete saved node → return its data
    // ════════════════════════════════════════════
    int pop() {
        if (isEmpty()) {
            cout << "  [Stack Underflow]  Cannot pop — stack is empty.\n";
            return -1;          // sentinel for underflow
        }
        Node* temp = head;          // save current top
        int   val  = temp->data;
        head = head->next;          // advance top
        delete temp;                // release memory
        size--;
        cout << "  pop()  →  removed " << val << "  |  new top = "
             << (isEmpty() ? "NULL (empty)" : to_string(head->data))
             << "  |  size = " << size << "\n";
        return val;
    }

    // ════════════════════════════════════════════
    //  peek() — O(1)
    //  Read head->data WITHOUT modifying the list
    // ════════════════════════════════════════════
    int peek() const {
        if (isEmpty()) {
            cout << "  [Empty Stack]  No element to peek.\n";
            return -1;
        }
        cout << "  peek()  →  top element = " << head->data << "\n";
        return head->data;
    }

    // ── Utility: display full stack (top → bottom) ─
    void display() const {
        if (isEmpty()) {
            cout << "  Stack: [ empty ]\n";
            return;
        }
        cout << "  Stack (top → bottom): ";
        Node* curr = head;
        while (curr) {
            cout << curr->data;
            if (curr->next) cout << " -> ";
            curr = curr->next;
        }
        cout << " -> NULL\n";
    }

    // ── Utility: print size and isEmpty status ────
    void status() const {
        cout << "  Elements: " << size
             << "  |  isEmpty: " << (isEmpty() ? "Yes" : "No")
             << "  |  Memory: Dynamic (no fixed limit)\n";
    }
};

// ─────────────────────────────────────────────
//  Main — full demonstration
// ─────────────────────────────────────────────
int main() {
    cout << "==========================================\n";
    cout << "   STACK USING LINKED LIST (Dynamic)     \n";
    cout << "==========================================\n\n";

    Stack s;

    // ── isEmpty on a fresh stack ──────────────────
    cout << "[ Initial State ]\n";
    s.status();
    s.display();
    cout << "\n";

    // ── push elements ─────────────────────────────
    cout << "[ Push Operations ]\n";
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.display();
    s.status();
    cout << "\n";

    // ── peek ──────────────────────────────────────
    cout << "[ Peek / Top ]\n";
    s.peek();
    s.display();          // stack unchanged after peek
    cout << "\n";

    // ── pop some elements ─────────────────────────
    cout << "[ Pop Operations ]\n";
    s.pop();
    s.pop();
    s.pop();
    s.display();
    s.status();
    cout << "\n";

    // ── drain the stack ───────────────────────────
    cout << "[ Drain the Stack ]\n";
    s.pop();
    s.pop();
    s.display();
    s.status();
    cout << "\n";

    // ── underflow check ───────────────────────────
    cout << "[ Underflow Check ]\n";
    s.pop();          // triggers underflow message
    s.peek();         // triggers empty-stack message
    cout << "\n";

    // ── push after full drain (dynamic — always possible) ─
    cout << "[ Push After Full Drain ]\n";
    s.push(99);
    s.push(88);
    s.display();
    cout << "\n";

    // ── destructor runs here, freeing remaining nodes ─
    cout << "[ Stack going out of scope — Destructor ]\n";

    return 0;
}