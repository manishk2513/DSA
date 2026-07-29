#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next;

	Node(int val){
		data = val;
		next = nullptr;
	}
};

class Graph {
	int v;
	Node **head;
public:
	Graph(int vertices){
		v = vertices;
		head = new Node *[v];
		for(int i = 0; i < v; i++){
			head[i] = nullptr;
		}
	}

	void insertDirected(int u, int v){
		Node *newNode = new Node(v);
		newNode->next = head[u];
		head[u] = newNode;
	}

	void display(){
		for(int i = 0; i < v; i++){
			cout<<i<<" -> ";

			Node *temp = head[i];
			while(temp != nullptr){
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
	}
};


int main(){
	Graph g(5);

	g.insertDirected(0, 1);
    g.insertDirected(0, 2);
    g.insertDirected(1, 2);
    g.insertDirected(2, 4);
    g.insertDirected(4, 3);

	g.display();

	return 0;
}