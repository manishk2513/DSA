#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// =========================================================
//  Generic Stack -- linked list
// =========================================================
template <typename T>
struct SNode {
    T      data;
    SNode* next;
    SNode(T v) : data(v), next(nullptr) {}
};

template <typename T>
class Stack {
public:
    SNode<T>* head;
    int       sz;
    Stack() : head(nullptr), sz(0) {}
    ~Stack() { while (!isEmpty()) pop(); }

    bool isEmpty() const { return head == nullptr; }
    int  size()    const { return sz; }
    T&   peek()          { return head->data; }

    void push(T v) {
        SNode<T>* n = new SNode<T>(v);
        n->next = head;
        head = n;
        sz++;
    }

    T pop() {
        T val = head->data;
        SNode<T>* tmp = head;
        head = head->next;
        delete tmp;
        sz--;
        return val;
    }
};

// =========================================================
//  Frame -- mirrors one pending recursive call
// =========================================================
struct Frame {
    int  n;
    char src, aux, dst;
    int  phase;  // 0=before left sub-call, 1=after left sub-call
};

// =========================================================
//  Peg -- named disk stack
// =========================================================
struct Peg {
    char       name;
    Stack<int> disks;
    Peg(char c) : name(c) {}
};

Peg& getPeg(char c, Peg& A, Peg& B, Peg& C) {
    if (c == A.name) return A;
    if (c == B.name) return B;
    return C;
}

// =========================================================
//  Mirror arrays for visual state
// =========================================================
int mirrorArr[3][64];
int heights[3];

void initMirror(int n) {
    heights[0] = n; heights[1] = 0; heights[2] = 0;
    for (int i = 0; i < n; i++) mirrorArr[0][i] = n - i;
    for (int i = 0; i < n; i++) mirrorArr[1][i] = mirrorArr[2][i] = 0;
}

int pegIdx(char c) { return c=='A'?0:c=='B'?1:2; }

void moveMirror(char from, char to) {
    int fi = pegIdx(from), ti = pegIdx(to);
    int top = mirrorArr[fi][heights[fi]-1];
    heights[fi]--;
    mirrorArr[ti][heights[ti]] = top;
    heights[ti]++;
}

// =========================================================
//  Visual state renderer (ASCII-safe)
// =========================================================
void printState(int n, int moveNum, int disk, char from, char to) {
    int colW = n * 4 + 5;  // wide enough for all disk bars

    if (moveNum == 0)
        cout << "  Initial State\n";
    else
        cout << "  Move " << moveNum << ":  Disk " << disk
             << "   " << from << " --> " << to << "\n";

    for (int row = n - 1; row >= 0; row--) {
        cout << "  ";
        for (int p = 0; p < 3; p++) {
            int d = (row < heights[p]) ? mirrorArr[p][row] : 0;
            string cell;
            if (d == 0) {
                int half = colW / 2;
                cell = string(half, ' ') + "|" + string(colW - half - 1, ' ');
            } else {
                string bar(d * 2, '=');
                string label = bar + "[" + to_string(d) + "]" + bar;
                int pad  = (colW - (int)label.size()) / 2;
                int rpad = colW - pad - (int)label.size();
                if (pad < 0) pad = 0;
                if (rpad < 0) rpad = 0;
                cell = string(pad, ' ') + label + string(rpad, ' ');
            }
            cout << cell;
            if (p < 2) cout << "   ";
        }
        cout << "\n";
    }
    // base
    cout << "  " << string(colW, '-') << "   "
                 << string(colW, '-') << "   "
                 << string(colW, '-') << "\n";
    // labels
    const char* lbl[3] = {"A (Source)", "B (Aux)", "C (Dest)"};
    cout << "  ";
    for (int p = 0; p < 3; p++) {
        string L(lbl[p]);
        int left = (colW - (int)L.size()) / 2;
        if (left < 0) left = 0;
        int right = colW - left - (int)L.size();
        if (right < 0) right = 0;
        cout << string(left, ' ') << L << string(right, ' ');
        if (p < 2) cout << "   ";
    }
    cout << "\n\n";
}

// =========================================================
//  ITERATIVE Tower of Hanoi using explicit call stack
//
//  Simulates:
//    hanoi(n, src, aux, dst):
//      hanoi(n-1, src, dst, aux)   <-- phase 0: push left sub-call
//      move disk n: src --> dst    <-- actual move
//      hanoi(n-1, aux, src, dst)   <-- phase 1: push right sub-call
//
//  Frame.phase:
//    0 --> left sub-call not yet done  --> update to phase 1, push left sub
//    1 --> left sub-call finished      --> do move, pop, push right sub
// =========================================================
void hanoiIterative(int n, Peg& src, Peg& aux, Peg& dst, bool verbose) {
    long long total = ((long long)1 << n) - 1;
    cout << "  Disks : " << n << "   |   Total moves : " << total
         << "  (2^" << n << " - 1)\n";
    cout << "  " << string(48, '-') << "\n\n";

    if (verbose) printState(n, 0, 0, ' ', ' ');

    Stack<Frame> cs;
    cs.push({n, src.name, aux.name, dst.name, 0});
    int moveNum = 0;

    while (!cs.isEmpty()) {
        Frame& f = cs.peek();  // in-place reference

        if (f.n == 0) { cs.pop(); continue; }

        if (f.phase == 0) {
            // Mark current as phase 1, push left sub-call on top
            f.phase = 1;
            cs.push({f.n - 1, f.src, f.dst, f.aux, 0});
        } else {
            // Left sub-call done: perform move, push right sub-call
            char s = f.src, a = f.aux, d = f.dst;
            int  disk = f.n;

            Peg& from = getPeg(s, src, aux, dst);
            Peg& to   = getPeg(d, src, aux, dst);
            to.disks.push(from.disks.pop());
            moveMirror(s, d);
            moveNum++;

            if (verbose)
                printState(n, moveNum, disk, s, d);
            else
                cout << "  Move " << moveNum << ": Disk " << disk
                     << "   " << s << " --> " << d << "\n";

            cs.pop();
            cs.push({disk - 1, a, s, d, 0});
        }
    }
}

// =========================================================
//  Main
// =========================================================
int main() {
    cout << "==========================================\n";
    cout << "  TOWER OF HANOI -- Iterative Stack-Based\n";
    cout << "  No system recursion. Explicit stack.   \n";
    cout << "==========================================\n\n";

    // n=3, full visual
    {
        cout << "+------------------------------------------+\n";
        cout << "|  n = 3  --  Full Step-by-Step Visual     |\n";
        cout << "+------------------------------------------+\n\n";
        int n = 3;
        Peg A('A'), B('B'), C('C');
        for (int i = n; i >= 1; i--) A.disks.push(i);
        initMirror(n);
        hanoiIterative(n, A, B, C, true);
        cout << "  [OK] All " << n << " disks on C!\n\n";
    }

    // n=4, move list
    {
        cout << "+------------------------------------------+\n";
        cout << "|  n = 4  --  Move List Only               |\n";
        cout << "+------------------------------------------+\n\n";
        int n = 4;
        Peg A('A'), B('B'), C('C');
        for (int i = n; i >= 1; i--) A.disks.push(i);
        initMirror(n);
        hanoiIterative(n, A, B, C, false);
        cout << "\n  [OK] All " << n << " disks on C!\n\n";
    }

    // Growth table
    cout << "+------------------------------------------+\n";
    cout << "|  Complexity: O(2^n - 1) moves            |\n";
    cout << "+------------------------------------------+\n";
    cout << "  n (disks)  |  Moves (2^n - 1)\n";
    cout << "  " << string(30, '-') << "\n";
    for (int i = 1; i <= 12; i++) {
        long long moves = ((long long)1 << i) - 1;
        cout << "      " << i;
        for (int s = (int)to_string(i).size(); s < 6; s++) cout << ' ';
        cout << "|  " << moves << "\n";
    }
    cout << "  " << string(30, '-') << "\n";
    return 0;
}
