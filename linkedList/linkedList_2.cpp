#include<iostream>
using namespace std;

class Node {
public:
	int roll;
	string name;
	Node *next;

	Node(int roll, string name){
		this->roll = roll;
		this->name = name;
		next = NULL;
	}
};

void print(Node *head){
	while(head != NULL){
		cout<<head->roll<<" ";
		cout<<head->name<<" "<<endl;
		head = head->next;
	}
}

void insertAtHead(Node* &head, int roll, string name){
	Node *nodeToInsert = new Node(roll, name);
	nodeToInsert->next = head;
	head = nodeToInsert;
}

void deleteList(Node* &head) {
    while (head != nullptr) {
        Node* nextNode = head->next;
        delete head;
        head = nextNode;
    }
}


int main(){

	Node *head = new Node(11, "sohan");

	insertAtHead(head, 19, "suresh");
	insertAtHead(head, 21, "rita");
	insertAtHead(head, 9, "vishal");
	insertAtHead(head, 23, "ramesh");
	insertAtHead(head, 55, "vineeta");

	cout<<"list: \n";
	print(head);
	cout<<endl;	

	deleteList(head);
	return 0;
}
