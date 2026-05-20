#include <iostream>
#include <string>
using namespace std;

// ─────────────────────────────────────────────
//  Constants
// ─────────────────────────────────────────────
const int MAX_SIZE = 6;

// ═════════════════════════════════════════════
//  LinearQueue — fixed-size array
//
//  Internal layout:
//
//    index:  0    1    2    3    4    5
//           [ ]  [10] [20] [30] [ ]  [ ]
//                  ^              ^
//                front           rear
//
//  front  = index of the first valid element (-1 when empty)
//  rear   = index of the last  valid element (-1 when empty)
//
//  isEmpty : front == -1
//  isFull  : rear  == MAX_SIZE - 1
//
//  Limitation: once rear reaches MAX_SIZE-1 the queue is
//  considered "full" even if front has advanced (wasted slots).
//  This is the defining trait of a LINEAR queue — solved by
//  Circular Queue in the next implementation.
// ═════════════════════════════════════════════
class LinearQueue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    // ── Constructor ───────────────────────────
    LinearQueue() : front(-1), rear(-1) {}

    // ════════════════════════════════════════════
    //  isEmpty() — O(1)
    // ════════════════════════════════════════════
    bool isEmpty() const {
        return front == -1;
    }

    // ════════════════════════════════════════════
    //  isFull() — O(1)
    //  rear has reached the last physical slot.
    //  Front positions already freed are NOT reused.
    // ════════════════════════════════════════════
    bool isFull() const {
        return rear == MAX_SIZE - 1;
    }

    // ════════════════════════════════════════════
    //  enqueue(value) — O(1)
    //  Insert at rear; handle overflow.
    // ════════════════════════════════════════════
    void enqueue(int value) {
        if (isFull()) {
            cout << "  [Queue Overflow]  Cannot enqueue " << value
                 << " -- rear has reached MAX (" << MAX_SIZE << ").\n"
                 << "  Note: This is the Linear Queue limitation.\n";
            return;
        }
        if (isEmpty()) front = 0;   // first element: initialise front
        arr[++rear] = value;
        cout << "  enqueue(" << value << ")"
             << "  |  front=" << front
             << "  rear=" << rear << "\n";
    }

    // ════════════════════════════════════════════
    //  dequeue() — O(1)
    //  Remove from front; handle underflow.
    //  front advances forward (slots behind are abandoned).
    // ════════════════════════════════════════════
    int dequeue() {
        if (isEmpty()) {
            cout << "  [Queue Underflow]  Cannot dequeue -- queue is empty.\n";
            return -1;
        }
        int val = arr[front];
        if (front == rear) {
            // last element removed -- reset to empty state
            front = rear = -1;
        } else {
            front++;
        }
        cout << "  dequeue()  ->  removed " << val
             << "  |  front=" << front
             << "  rear=" << rear << "\n";
        return val;
    }

    // ════════════════════════════════════════════
    //  peek() / frontElement() — O(1)
    //  View front without removing.
    // ════════════════════════════════════════════
    int peek() const {
        if (isEmpty()) {
            cout << "  [Empty Queue]  No element to peek.\n";
            return -1;
        }
        cout << "  peek()  ->  front element = " << arr[front] << "\n";
        return arr[front];
    }

    // ── Utility: size ─────────────────────────
    int size() const {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }

    // ── Utility: display queue state ──────────
    void display() const {
        cout << "  Array  : [ ";
        for (int i = 0; i < MAX_SIZE; i++) {
            if (i >= front && i <= rear && !isEmpty())
                cout << arr[i];
            else
                cout << " _";
            if (i < MAX_SIZE - 1) cout << " | ";
        }
        cout << " ]\n";

        // index ruler
        cout << "  Index  :   ";
        for (int i = 0; i < MAX_SIZE; i++) {
            cout << i;
            if (i < MAX_SIZE - 1) cout << "   | ";
        }
        cout << "\n";

        // pointer labels
        if (!isEmpty()) {
            cout << "  ";
            for (int i = 0; i < MAX_SIZE; i++) {
                string label = "   ";
                if (i == front && i == rear) label = " F=R";
                else if (i == front)         label = "  Fr";
                else if (i == rear)          label = "  Re";
                else                         label = "    ";
                cout << label;
                if (i < MAX_SIZE - 1) cout << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    // ── Utility: status line ──────────────────
    void status() const {
        cout << "  Status : size=" << size()
             << "/" << MAX_SIZE
             << "  |  isEmpty=" << (isEmpty() ? "Yes" : "No")
             << "  |  isFull=" << (isFull()  ? "Yes" : "No")
             << "  |  front=" << front
             << "  rear=" << rear << "\n";
    }
};

// ─────────────────────────────────────────────
//  Main — full demonstration
// ─────────────────────────────────────────────
int main() {
    cout << "==========================================\n";
    cout << "   LINEAR QUEUE USING ARRAY (MAX = "
         << MAX_SIZE << ")   \n";
    cout << "==========================================\n\n";

    LinearQueue q;

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
    q.display();
    q.status();

    // ── Peek ──────────────────────────────────
    cout << "\n[ Peek / Front Element ]\n";
    q.peek();
    q.display();

    // ── Dequeue two elements ──────────────────
    cout << "[ Dequeue x2 ]\n";
    q.dequeue();
    q.dequeue();
    q.display();
    q.status();

    // ── Enqueue more after partial dequeue ────
    cout << "[ Enqueue After Partial Dequeue ]\n";
    q.enqueue(50);
    q.enqueue(60);
    q.display();
    q.status();

    // ── Demonstrate overflow (Linear Queue limitation) ──
    cout << "[ Overflow Demo -- Linear Queue Limitation ]\n";
    q.enqueue(70);   // rear == MAX_SIZE-1: OVERFLOW even though front>0
    cout << "\n";

    // ── Drain the queue ───────────────────────
    cout << "[ Drain the Queue ]\n";
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    q.status();

    // ── Underflow check ───────────────────────
    cout << "\n[ Underflow Check ]\n";
    q.dequeue();
    q.peek();

    // ── Underflow summary ─────────────────────
    cout << "\n==========================================\n";
    cout << "  KEY LIMITATION OF LINEAR QUEUE:\n";
    cout << "  Once rear reaches MAX_SIZE-1, no more\n";
    cout << "  enqueues are possible EVEN IF slots at\n";
    cout << "  the front have been freed by dequeue.\n";
    cout << "  --> Solved by Circular Queue.\n";
    cout << "==========================================\n";

    return 0;
}
