#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *left;
		Node *right;

		Node(int d) : data{d}, left{nullptr}, right{nullptr} {}
};

void insert(Node* &root){
	int data;
	cout<<"enter data: ";
	cin>>data;

	if(data == -1){
		root = nullptr;
		return;
	}

	root = new Node(data);

	cout<<"enter data for left of: "<<data<<endl;
	insert(root->left);
	cout<<"enter data for right of: "<<data<<endl;
	insert(root->right);

}

int main(){
	Node *root = nullptr;
	insert(root);


return 0;
}