#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Print forward
void printForward(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Find middle using slow & fast pointer
int findMiddle(Node* head) {
    if(head == NULL) return -1;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int main() {
    Node* head = NULL;

    Node* first  = new Node(10);
    Node* second = new Node(20);
    Node* third  = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth  = new Node(50);

    // Linking nodes (next + prev)
    head = first;

    first->next = second;

    second->prev = first;
    second->next = third;

    third->prev = second;
    third->next = fourth;

    fourth->prev = third;
    fourth->next = fifth;

    fifth->prev = fourth;

    cout << "Doubly Linked List (Forward): ";
    printForward(head);

    cout << "Middle value: " << findMiddle(head) << endl;

    return 0;
}
