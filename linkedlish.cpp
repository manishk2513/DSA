#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void insert(Node* &head, int value) {
    Node* n = new Node();
    n->data = value;
    n->next = head; 
    head = n;       
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
} 

int main() {
    Node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    display(head);
}