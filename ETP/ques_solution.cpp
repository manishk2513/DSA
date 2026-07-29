#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next;
};

class SinglyLinkedList {
private:
	Node *head;
public:
	SinglyLinkedList() : head(NULL) {}

	void insertAtHead(int value){
		Node *temp = new Node();
		temp->data = value;
		temp->next = head;
		head = temp;
		cout<<value<<" node inserted at head"<<endl;
	}

	void deleteAtHead(){
		Node *temp = new Node();
		temp = head;
		head = head->next;
		delete temp;
		cout<<"node deleted from the head"<<endl;
	}

	void display(){
		Node *curr = head;
		while(curr != NULL){
			cout<<curr->data<<" ";
			curr = curr->next;
		}
		cout<<endl;
	}

};

int main(){
	SinglyLinkedList *list = new SinglyLinkedList();

	list->insertAtHead(10);
	list->insertAtHead(24);
	list->insertAtHead(56);
	list->insertAtHead(99);

	cout<<"all the nodes inserted: \n";
	list->display();

	cout<<"deleting the node from head: \n";

	list->deleteAtHead();

	cout<<"updated list after node deletion from head: \n";
	list->display();


	return 0;
}