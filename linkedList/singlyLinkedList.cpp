#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next;

	Node(int data){
		this->data = data;
		next = NULL;
	}
};

void print(Node *head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}

void insertAtHead(Node* &head, int data){
	Node *nodeToInsert = new Node(data);
	nodeToInsert->next = head;
	head = nodeToInsert;
}

void insertAtTail(Node* &tail, int data){
	Node *nodeToInsert = new Node(data);
	tail->next = nodeToInsert;
	tail = nodeToInsert;
}

void insertAtIndex(Node* &head, int data, int index){
	Node *nodeToInsert = new Node(data);
	Node *temp = head;

	for(int i = 1; i < index - 1; i++){
		head = head->next;
	}
	nodeToInsert->next = head->next;
	head->next = nodeToInsert;
	head = temp;
}

int searchElementByIndex(Node *head, int index){
	if(index < 1){
		cout<<"can't find at index < 1"<<endl;
		return 0;
	}

	for(int i = 0; i < index-1; i++){
		if(head == NULL){
			cout<<"index is out of range!!!"<<endl;
			return 0;
		}
			head = head->next;
	}
		return head->data;
}

// int searchElementByValue(Node *head, int data){
// 	int index = 1;
// 	while(head != NULL){
// 		if(head->data == data){
// 			return index; 
// 		}
// 		index++;
// 	}
// 	return 0;
// }


int main(){

	Node *head = new Node(10);
	Node *tail = head;

	// print(head);

	insertAtHead(head, 19);
	insertAtHead(head, 21);
	insertAtTail(tail, 9);
	insertAtTail(tail, 23);
	insertAtIndex(head, 555, 3);

	cout<<"list: ";
	print(head);
	cout<<endl;
	
	int a = searchElementByIndex(head, 7);
	cout<<a<<endl;


	

	return 0;
}

