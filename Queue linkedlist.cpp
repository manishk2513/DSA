#include <iostream>
#include <string>
using namespace std;

// ─────────────────────────────────────────────
//  Node
// ─────────────────────────────────────────────
struct Node {
    int   data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

// ═════════════════════════════════════════════
//  LinkedQueue — dynamic size, no overflow
//
//  Internal layout:
//
//  front                           rear
//    │                               │
//    ▼                               ▼
//   [10] --> [20] --> [30] --> [40] --> NULL
//
//  enqueue  →  new node appended at rear
//  dequeue  →  node removed from front
//
//  Two pointers kept at all times:
//    front  = head of list (oldest element)
//    rear   = tail of list (newest element)
//
//  Both set to nullptr when queue is empty.
// ═════════════════════════════════════════════
class LinkedQueue {
private:
    Node* front;
    Node* rear;
    int   count;

public:
    // ── Constructor ───────────────────────────
    LinkedQueue() : front(nullptr), rear(nullptr), count(0) {}

    // ── Destructor: free all nodes ────────────
    ~LinkedQueue() {
        while (!isEmpty()) dequeue();
        cout << "  [Destructor]  All nodes freed.\n";
    }

    // ════════════════════════════════════════════
    //  isEmpty() — O(1)
    // ════════════════════════════════════════════
    bool isEmpty() const { return front == nullptr; }

    // ════════════════════════════════════════════
    //  size() — O(1)  (tracked with counter)
    // ════════════════════════════════════════════
    int size() const { return count; }

    // ════════════════════════════════════════════
    //  enqueue(value) — O(1)
    //
    //  Steps:
    //   1. Allocate new node.
    //   2. If queue is empty → new node is BOTH front and rear.
    //      Else             → link current rear to new node,
    //                         advance rear to new node.
    // ════════════════════════════════════════════
    void enqueue(int value) {
        Node* newNode = new (nothrow) Node(value);
        if (!newNode) {
            cout << "  [Heap Exhausted]  Cannot enqueue " << value << ".\n";
            return;
        }
        if (isEmpty()) {
            front = rear = newNode;         // first element
        } else {
            rear->next = newNode;           // link at tail
            rear       = newNode;           // advance rear
        }
        count++;
        cout << "  enqueue(" << value << ")"
             << "  |  front=" << front->data
             << "  rear=" << rear->data
             << "  size=" << count << "\n";
    }

    // ════════════════════════════════════════════
    //  dequeue() — O(1)
    //
    //  Steps:
    //   1. Save front node.
    //   2. Advance front to front->next.
    //   3. If front becomes nullptr → queue is empty,
    //      also set rear = nullptr.
    //   4. Delete saved node, return its data.
    // ════════════════════════════════════════════
    int dequeue() {
        if (isEmpty()) {
            cout << "  [Queue Empty]  Cannot dequeue -- queue is empty.\n";
            return -1;
        }
        Node* temp = front;
        int   val  = temp->data;
        front      = front->next;
        if (front == nullptr) rear = nullptr;   // queue now empty
        delete temp;
        count--;
        cout << "  dequeue()  ->  removed " << val
             << "  |  front=" << (front ? to_string(front->data) : "NULL")
             << "  rear="  << (rear  ? to_string(rear->data)  : "NULL")
             << "  size=" << count << "\n";
        return val;
    }

    // ════════════════════════════════════════════
    //  peek() / frontElement() — O(1)
    // ════════════════════════════════════════════
    int peek() const {
        if (isEmpty()) {
            cout << "  [Empty Queue]  No element to peek.\n";
            return -1;
        }
        cout << "  peek()  ->  front = " << front->data
             << "  rear = " << rear->data << "\n";
        return front->data;
    }

    // ════════════════════════════════════════════
    //  rearElement() — O(1)
    //  View the last inserted element without removal.
    // ════════════════════════════════════════════
    int rearElement() const {
        if (isEmpty()) {
            cout << "  [Empty Queue]  No rear element.\n";
            return -1;
        }
        cout << "  rearElement()  ->  rear = " << rear->data << "\n";
        return rear->data;
    }

    // ── Utility: display the full queue ───────
    void display() const {
        if (isEmpty()) {
            cout << "  Queue: [ empty ]\n\n";
            return;
        }

        // ── linear chain view ─────────────────
        cout << "  Chain : front --> ";
        Node* curr = front;
        while (curr) {
            cout << "[" << curr->data << "]";
            if (curr->next) cout << " --> ";
            curr = curr->next;
        }
        cout << " --> NULL <-- rear\n";

        // ── box view with labels ───────────────
        cout << "  Nodes :  ";
        curr = front;
        int idx = 0;
        while (curr) {
            cout << " " << curr->data << " ";
            if (curr->next) cout << "->";
            curr = curr->next;
            idx++;
        }
        cout << "\n";
        cout << "  Labels:  ";
        curr = front;
        idx  = 0;
        int total = count;
        while (curr) {
            string lbl;
            if      (idx == 0 && total == 1) lbl = "F=R";
            else if (idx == 0)               lbl = " Fr";
            else if (idx == total - 1)       lbl = " Re";
            else                             lbl = "   ";
            cout << lbl;
            if (curr->next) cout << "  ";
            curr = curr->next;
            idx++;
        }
        cout << "\n\n";
    }

    // ── Utility: status line ──────────────────
    void status() const {
        cout << "  Status : size=" << count
             << "  |  isEmpty=" << (isEmpty() ? "Yes" : "No")
             << "  |  Dynamic (no fixed limit)\n";
    }
};

// ─────────────────────────────────────────────
//  Main — full demonstration
// ─────────────────────────────────────────────
int main() {
    cout << "==========================================\n";
    cout << "     QUEUE USING LINKED LIST             \n";
    cout << "     Dynamic size -- no overflow         \n";
    cout << "==========================================\n\n";

    LinkedQueue q;

    // ── Initial state ─────────────────────────
    cout << "[ Initial State ]\n";
    q.status();
    q.display();

    // ── Enqueue ───────────────────────────────
    cout << "[ Enqueue Operations ]\n";
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.status();

    // ── Peek ──────────────────────────────────
    cout << "\n[ Peek Front & Rear ]\n";
    q.peek();
    q.rearElement();
    q.display();

    // ── Dequeue ───────────────────────────────
    cout << "[ Dequeue x3 ]\n";
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    q.status();

    // ── Enqueue after dequeue (dynamic -- always works) ──
    cout << "[ Enqueue After Dequeue -- No wrap-around needed ]\n";
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);
    q.display();
    q.status();

    // ── Drain ─────────────────────────────────
    cout << "[ Drain the Queue ]\n";
    while (!q.isEmpty()) q.dequeue();
    q.display();
    q.status();

    // ── Underflow check ───────────────────────
    cout << "\n[ Underflow & Peek on Empty ]\n";
    q.dequeue();
    q.peek();
    q.rearElement();

    // ── Single-element edge case ──────────────
    cout << "\n[ Single Element Edge Case ]\n";
    q.enqueue(99);
    q.display();
    q.peek();
    q.dequeue();    // front and rear both become nullptr
    q.display();
    q.status();

    // ── Comparison table ──────────────────────
    cout << "[ Destructor runs -- frees any remaining nodes ]\n";
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "\n";

    cout << "==========================================\n";
    cout << "  ARRAY QUEUE vs LINKED LIST QUEUE\n";
    cout << "==========================================\n";
    cout << "  Feature       Array (Circular)  Linked List\n";
    cout << "  " << string(46, '-') << "\n";
    cout << "  Max Size      Fixed (MAX_SIZE)  Dynamic\n";
    cout << "  Overflow      Possible          Never *\n";
    cout << "  Memory        Pre-allocated     Per node\n";
    cout << "  enqueue       O(1) modulo       O(1) pointer\n";
    cout << "  dequeue       O(1) modulo       O(1) pointer\n";
    cout << "  Extra ptr     front + rear      front + rear\n";
    cout << "  " << string(46, '-') << "\n";
    cout << "  * Unless heap is fully exhausted\n\n";

    return 0;
}