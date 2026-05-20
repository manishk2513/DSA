#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 6;

class CircularQueue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;
    int count;

public:
    CircularQueue() : front(0), rear(-1), count(0) {}

    bool isEmpty() const { return count == 0; }
    bool isFull()  const { return count == MAX_SIZE; }
    int  size()    const { return count; }

    void enqueue(int value) {
        if (isFull()) {
            cout << "  [Queue Full]  Cannot enqueue " << value
                 << " -- all " << MAX_SIZE << " slots occupied.\n";
            return;
        }
        rear      = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
        count++;
        cout << "  enqueue(" << value << ")"
             << "  |  front=" << front
             << "  rear=" << rear
             << "  count=" << count << "\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "  [Queue Empty]  Cannot dequeue -- queue is empty.\n";
            return -1;
        }
        int val = arr[front];
        front   = (front + 1) % MAX_SIZE;
        count--;
        cout << "  dequeue()  ->  removed " << val
             << "  |  front=" << front
             << "  rear=" << rear
             << "  count=" << count << "\n";
        return val;
    }

    int peek() const {
        if (isEmpty()) { cout << "  [Empty Queue]  No element to peek.\n"; return -1; }
        cout << "  peek()  ->  front element = " << arr[front] << "\n";
        return arr[front];
    }

    // Check if index i holds a valid element
    bool isValid(int i) const {
        if (isEmpty()) return false;
        if (front <= rear) return i >= front && i <= rear;
        return i >= front || i <= rear;
    }

    // Flat array display
    void displayArray() const {
        cout << "  Array  : [ ";
        for (int i = 0; i < MAX_SIZE; i++) {
            if (isValid(i)) cout << arr[i];
            else            cout << " _";
            if (i < MAX_SIZE - 1) cout << " | ";
        }
        cout << " ]\n";

        cout << "  Index  :   ";
        for (int i = 0; i < MAX_SIZE; i++) {
            cout << i;
            if (i < MAX_SIZE - 1) cout << "   | ";
        }
        cout << "\n";

        if (!isEmpty()) {
            cout << "  ";
            for (int i = 0; i < MAX_SIZE; i++) {
                string lbl;
                if      (i == front && i == rear) lbl = " F=R";
                else if (i == front)              lbl = "  Fr";
                else if (i == rear)               lbl = "  Re";
                else                              lbl = "    ";
                cout << lbl;
                if (i < MAX_SIZE - 1) cout << " ";
            }
            cout << "\n";
        }
    }

    // Ring diagram (clock face, 6 slots)
    //
    //  Slot positions on a clock:
    //    0 = 12 o'clock (top)
    //    1 =  2 o'clock (top-right)
    //    2 =  4 o'clock (bottom-right)
    //    3 =  6 o'clock (bottom)
    //    4 =  8 o'clock (bottom-left)
    //    5 = 10 o'clock (top-left)
    //
    //  Grid: 9 rows x 38 cols
    void displayRing() const {
        const int ROWS = 9, COLS = 38;
        char g[ROWS][COLS];
        for (int r = 0; r < ROWS; r++)
            for (int c = 0; c < COLS; c++)
                g[r][c] = ' ';

        // For each slot, build a label like:
        //   [10](Fr)  or  [ _]
        auto slotLabel = [&](int i) -> string {
            string val;
            if (isValid(i)) {
                val = to_string(arr[i]);
                if (arr[i] >= 0 && arr[i] < 10) val = " " + val;
            } else {
                val = " _";
            }
            string box = "[" + val + "]";
            string tag = "";
            if      (!isEmpty() && i == front && i == rear) tag = "<F=R>";
            else if (!isEmpty() && i == front)              tag = "<Fr> ";
            else if (!isEmpty() && i == rear)               tag = "<Re> ";
            return box + tag;
        };

        // Place labels at fixed grid positions
        // Row, Col for the start of each slot label
        // Layout (9 rows, 38 cols):
        //        slot 0 at row 0, col 15
        //  slot 5 at row 2, col 0    slot 1 at row 2, col 26
        //  slot 4 at row 6, col 0    slot 2 at row 6, col 26
        //        slot 3 at row 8, col 15
        int sr[MAX_SIZE] = {0, 2, 6, 8, 6, 2};
        int sc[MAX_SIZE] = {15, 27, 27, 15, 0, 0};

        for (int i = 0; i < MAX_SIZE; i++) {
            string lbl = slotLabel(i);
            // prefix with slot index
            string full = "(" + to_string(i) + ")" + lbl;
            int r = sr[i], c = sc[i];
            for (int k = 0; k < (int)full.size() && c + k < COLS; k++)
                g[r][c + k] = full[k];
        }

        // Draw connecting arc lines
        // top arc: between slot 5 and slot 0, and slot 0 and slot 1
        g[1][8] = '/';  g[1][18] = '-'; g[1][19] = '-'; g[1][25] = '\\';
        // right side: slot 1 to slot 2
        g[4][34] = '|';
        // bottom arc: slot 2 to slot 3, slot 3 to slot 4
        g[7][8] = '\\'; g[7][18] = '-'; g[7][19] = '-'; g[7][25] = '/';
        // left side: slot 4 to slot 5
        g[4][3] = '|';

        cout << "\n  Ring diagram (0=top, 1=top-right, 2=bot-right,\n"
             << "                3=bottom, 4=bot-left, 5=top-left):\n\n";
        for (int r = 0; r < ROWS; r++) {
            cout << "  ";
            // trim trailing spaces
            int last = COLS - 1;
            while (last > 0 && g[r][last] == ' ') last--;
            for (int c = 0; c <= last; c++) cout << g[r][c];
            cout << "\n";
        }
        cout << "\n";
    }

    void display() const {
        displayArray();
        displayRing();
    }

    void status() const {
        cout << "  Status : count=" << count << "/" << MAX_SIZE
             << "  |  isEmpty=" << (isEmpty() ? "Yes" : "No")
             << "  |  isFull="  << (isFull()  ? "Yes" : "No")
             << "  |  front=" << front
             << "  rear=" << rear << "\n";
    }
};

int main() {
    cout << "==========================================\n";
    cout << "  CIRCULAR QUEUE USING ARRAY (MAX = "
         << MAX_SIZE << ")  \n";
    cout << "  Fixes wasted-slot problem via modulo   \n";
    cout << "  wrap-around: (x+1) % MAX_SIZE          \n";
    cout << "==========================================\n\n";

    CircularQueue q;

    cout << "[ Initial State ]\n";
    q.status();
    q.display();

    cout << "[ Enqueue 5 Elements ]\n";
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.status();

    cout << "\n[ Peek ]\n";
    q.peek();
    cout << "\n";

    cout << "[ Dequeue x3  (front advances, slots freed) ]\n";
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    q.status();

    cout << "\n[ Wrap-Around Enqueue -- The Circular Fix! ]\n";
    cout << "  Linear queue would OVERFLOW here. Circular reuses freed slots.\n\n";
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);
    q.display();
    q.status();

    cout << "\n[ Fill Last Slot ]\n";
    q.enqueue(90);
    q.display();
    q.status();

    cout << "\n[ Overflow -- Truly Full ]\n";
    q.enqueue(99);
    cout << "\n";

    cout << "[ Drain the Queue ]\n";
    while (!q.isEmpty()) q.dequeue();
    q.display();
    q.status();

    cout << "\n[ Underflow & Peek on Empty ]\n";
    q.dequeue();
    q.peek();

    cout << "\n==========================================\n";
    cout << "  LINEAR vs CIRCULAR QUEUE\n";
    cout << "==========================================\n";
    cout << "  Feature         Linear Queue   Circular Queue\n";
    cout << "  " << string(48, '-') << "\n";
    cout << "  Slot reuse      No             Yes\n";
    cout << "  Memory waste    Yes            No\n";
    cout << "  isFull check    rear==MAX-1    count==MAX\n";
    cout << "  isEmpty check   front==-1      count==0\n";
    cout << "  enqueue step    rear++         (rear+1)%MAX\n";
    cout << "  dequeue step    front++        (front+1)%MAX\n";
    cout << "  " << string(48, '-') << "\n";

    return 0;
}
