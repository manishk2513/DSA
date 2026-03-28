#include<iostream>
using namespace std;

class Node {
public:
	Node *prev;
	int data;
	Node *next;
	Node(int data){
		prev = NULL;
		this->data = data;
		next = NULL;
	}
};

void print(Node *head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void printWithTail(Node *tail){
	while(tail->prev != NULL){
		tail = tail->prev;
	}
	print(tail);
}

void insertAtHead(Node* &head, int data){
	Node *nodeToInsert = new Node(data);
	nodeToInsert->next = head;
	head->prev = nodeToInsert;
	head = nodeToInsert;
}

void insertAtTail(Node* &tail, int data){
	Node *nodeToInsert = new Node(data);
	tail->next = nodeToInsert;
	nodeToInsert->prev = tail;
	tail = nodeToInsert;
}

void insertAtIndex(Node* head, int data, int index){
	Node *nodeToInsert = new Node(data);
	for(int i = 1; i < index -1; i++){
		head = head->next;
	}
	nodeToInsert->next = head->next;
	nodeToInsert->prev = head;
	head->next = nodeToInsert;
}

int main(){

	Node *head = new Node(10);
	Node *tail = head;

	insertAtHead(head, 23);
	insertAtHead(head, 89);

	insertAtTail(tail, 90);
	insertAtTail(tail, 80);
	
	insertAtIndex(head, 11, 6);
	insertAtIndex(head, 33, 1);
	print(head);

	
	// insertAtIndex(head, 22, 3);
	// insertAtIndex(head, 44, 1);

	// cout<<"print with head: ";
	print(head);
	// cout<<"print with tail: ";
	// printWithTail(tail);


	return 0;
}