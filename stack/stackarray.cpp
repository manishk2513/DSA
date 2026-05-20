#include <iostream>
using namespace std;

// ─────────────────────────────────────────────
//  Stack class — fixed-size array implementation
// ─────────────────────────────────────────────
const int MAX_SIZE = 5;   // change as needed

class Stack {
private:
    int arr[MAX_SIZE];
    int top;              // index of the topmost element (-1 when empty)

public:
    // Constructor
    Stack() : top(-1) {}

    // ════════════════════════════════════════════
    //  isEmpty() — O(1)
    //  Returns true when no element is in the stack
    // ════════════════════════════════════════════
    bool isEmpty() const {
        return top == -1;
    }

    // ════════════════════════════════════════════
    //  isFull() — O(1)
    //  Returns true when the array is completely used
    // ════════════════════════════════════════════
    bool isFull() const {
        return top == MAX_SIZE - 1;
    }

    // ════════════════════════════════════════════
    //  push(value) — O(1)
    //  Adds value on top; prints error on overflow
    // ════════════════════════════════════════════
    void push(int value) {
        if (isFull()) {
            cout << "  [Stack Overflow]  Cannot push " << value
                 << " — stack is full (MAX = " << MAX_SIZE << ").\n";
            return;
        }
        arr[++top] = value;
        cout << "  push(" << value << ")  →  top = " << top << "\n";
    }

    // ════════════════════════════════════════════
    //  pop() — O(1)
    //  Removes & returns top element; -1 on underflow
    // ════════════════════════════════════════════
    int pop() {
        if (isEmpty()) {
            cout << "  [Stack Underflow]  Cannot pop — stack is empty.\n";
            return -1;          // sentinel for underflow
        }
        int val = arr[top--];
        cout << "  pop()  →  removed " << val << "  |  new top = "
             << (isEmpty() ? -1 : arr[top]) << "\n";
        return val;
    }

    // ════════════════════════════════════════════
    //  peek() / top() — O(1)
    //  Returns top element WITHOUT removing it
    // ════════════════════════════════════════════
    int peek() const {
        if (isEmpty()) {
            cout << "  [Empty Stack]  No element to peek.\n";
            return -1;
        }
        cout << "  peek()  →  top element = " << arr[top] << "\n";
        return arr[top];
    }

    // ── Utility: display current stack state ─────
    void display() const {
        if (isEmpty()) {
            cout << "  Stack: [ empty ]\n";
            return;
        }
        cout << "  Stack (top → bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i];
            if (i > 0) cout << " | ";
        }
        cout << "\n";
    }

    // ── Utility: print size info ──────────────────
    void status() const {
        cout << "  Size: " << top + 1 << " / " << MAX_SIZE
             << "  |  isEmpty: " << (isEmpty() ? "Yes" : "No")
             << "  |  isFull: "  << (isFull()  ? "Yes" : "No") << "\n";
    }
};

// ─────────────────────────────────────────────
//  Main — full demonstration
// ─────────────────────────────────────────────
int main() {
    cout << "==========================================\n";
    cout << "   STACK USING ARRAY  (MAX SIZE = " << MAX_SIZE << ")    \n";
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

    // ── overflow check ────────────────────────────
    cout << "[ Overflow Check ]\n";
    s.push(99);           // should trigger Stack Overflow
    cout << "\n";

    // ── peek ──────────────────────────────────────
    cout << "[ Peek / Top ]\n";
    s.peek();
    s.display();
    cout << "\n";

    // ── pop elements ──────────────────────────────
    cout << "[ Pop Operations ]\n";
    s.pop();
    s.pop();
    s.pop();
    s.display();
    s.status();
    cout << "\n";

    // ── pop remaining ─────────────────────────────
    cout << "[ Drain the Stack ]\n";
    s.pop();
    s.pop();
    s.display();
    s.status();
    cout << "\n";

    // ── underflow check ───────────────────────────
    cout << "[ Underflow Check ]\n";
    s.pop();              // should trigger Stack Underflow
    s.peek();             // should report empty stack
    cout << "\n";

    cout << "==========================================\n";
    cout << "              DEMO COMPLETE               \n";
    cout << "==========================================\n";

    return 0;
}