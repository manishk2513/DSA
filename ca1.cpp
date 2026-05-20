#include<iostream>
using namespace std;

int st[100];
int top = -1;

void push(int x) {
    st[++top] = x;
}

void pop() {
    top--;
}

void insertAtBottom(int x) {
    if (top == -1) {
        push(x);
        return;
    }
    int temp = st[top];
    pop();
    insertAtBottom(x);
    push(temp);
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);

    insertAtBottom(5);

    // cout << "Stack after inserting at bottom:\n";
    while (top != -1) {
        cout << st[top] << " ";
        pop();
    }
    return 0;
}