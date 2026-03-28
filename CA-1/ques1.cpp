#include<iostream>
using namespace std;

class Node{
public:
	string city;
	Node *next;

	Node(string city){
		this->city = city;
		next = NULL;
	}
};


void print(Node *head){
	while(head != NULL){
		cout<<head->city;
		if(head->next != NULL){
			cout<<" -> ";
		}
		head = head->next;
	}
}

void insertAtHead(Node* &head, string city){
	Node *nodeToInsert = new Node(city);
	nodeToInsert->next = head;
	head = nodeToInsert;
}

Node* reverseLinked(Node* head){
	Node *prev = NULL;
	Node *curr = head;
	Node *nextNode = NULL;

	while(curr != NULL){
		nextNode = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextNode;
	}
	return prev;
}

int main(){
	Node *head = new Node("mumbai");
	Node *tail = head;

	insertAtHead(head, "delhi");
	insertAtHead(head, "agra");
	insertAtHead(head, "jalandhar");
	insertAtHead(head, "patna");
	insertAtHead(head, "noida");

	cout<<"original list: ";
	print(head);
	cout<<endl;

	head = reverseLinked(head);
	cout<<"reversed list: ";
	print(head);
	cout<<endl;
}