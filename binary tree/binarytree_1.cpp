#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node *left;
	Node *right;

	Node(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

void insert(Node* &root){
	int data;
	cout<<"enter data: ";
	cin>>data;

	if(data == -1){
		root = NULL;
		return;
	}

	root = new Node(data);

	cout<<"enter for left side of: "<<data<<endl;
	insert(root->left);
	cout<<"enter for right side of: "<<data<<endl;
	insert(root->right);
}

void inorder(Node *root){
	if(root == NULL){
		return;
	}

	inorder(root->left);
	cout<<root->data<<endl;
	inorder(root->right);
}

void preorder(Node *root){
	if(root == NULL){
		return;
	}

	cout<<root->data<<endl;
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node *root){
	if(root == NULL){
		return;
	}

	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<endl;
}


int main(){
	Node *root = NULL;
	insert(root);

	inorder(root);
	cout<<"----------------"<<endl;
	preorder(root);
	cout<<"----------------"<<endl;
	postorder(root);

	return 0;
}