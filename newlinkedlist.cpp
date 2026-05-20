#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int findMiddle(Node* head) {
    if(head == NULL) {
        cout << "List is empty!" << endl;
        return -1;
    }
    
    // Count total nodes
    int length = 0;
    Node* temp = head;
    while(temp != NULL) {
        length++;
        temp = temp->next;
    }
    
    // Find middle position
    int mid = length / 2;
    
    // Traverse to middle node
    temp = head;
    for(int i = 0; i < mid; i++) {
        temp = temp->next;
    }
    
    return temp->data;
}

int main() {
    Node* head = NULL;

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    
    head = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    cout << "Linked List: ";
    print(head);
    
    cout << "Middle value: " << findMiddle(head) << endl;

    return 0;
}