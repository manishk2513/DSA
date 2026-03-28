#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next;

	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

void print(Node *head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}

void insertAtIndex(Node *head, int data, int index){
	Node *nodeToInsert = new Node(data);
	// Node *temp = head;

	for(int i = 1; i < index - 1; ++i){
		head = head->next;
	}
	nodeToInsert->next = head->next;
	head->next = nodeToInsert;
	// head = temp;
}

int countNode(Node *head){
	int count = 0;
	while(head != NULL){
		count++;
		head = head->next;
	}
	return count;
}

void printMidNode(Node *head, int count){
	for(int i = 0; i < count/2; i++){
		head = head->next;
	}
	cout<<"Mid node: "<<head->data<<endl;
}

void printMidNodeUsingSlowFast(Node *head){
	Node *slow = head;
	Node *fast = head;
	// int count = 0;

	while(fast!= NULL){
		slow = slow->next;
		fast = fast->next->next;
		// count += 2;
	}

	// cout<<endl<<"No of  elements: "<<count<<endl;
	cout<<"Mid element: "<<slow->data;
}

int main(){

	Node *head = new Node(10);
	Node *tail = head;

	print(head);

	insertAtIndex(head, 65, 1);
	insertAtIndex(head, 101, 2);
	insertAtIndex(head, 12, 2);
	insertAtIndex(head, 5, 3);
	// insertAtIndex(head, 25, 2);
	// insertAtIndex(head, 71, 1);
	// insertAtIndex(head, 1, 0);

	cout<<endl;
	print(head);
	cout<<endl;
	// int noOfNodes = countNode(head);
	// cout<<"No of nodes: "<<noOfNodes<<endl;
	// printMidNode(head, noOfNodes);
	cout<<"------------\n";

	printMidNodeUsingSlowFast(head);
	cout<<endl;
	return 0;
}

