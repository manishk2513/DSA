#include<iostream>
using namespace std;

struct TreeNode {
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};


void insert(TreeNode* &root){
	int data;
	cout<<"enter data: ";
	cin>>data;

	if(data == -1){
		root = NULL;
		return;
	}

	root = new TreeNode(data);

	cout<<"enter for left side of: "<<data<<endl;
	insert(root->left);
	cout<<"enter for right side of: "<<data<<endl;
	insert(root->right);
}

void inOrder(TreeNode *root){
	if(root == NULL){
		return;
	}

	inOrder(root->left);
	cout<<root->data<<endl;
	inOrder(root->right);
}

void preOrder(TreeNode *root){
	if(root == NULL){
		return;
	}

	cout<<root->data<<endl;
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(TreeNode *root){
	if(root == NULL){
		return;
	}

	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<endl;
}



int main() {
	TreeNode *root = NULL;
	insert(root);

	cout<<"=== inOrder ==="<<endl;
	inOrder(root);
	cout<<"----------------"<<endl;
	cout<<"=== preOrder ==="<<endl;
	preOrder(root);
	cout<<"----------------"<<endl;
	cout<<"=== postOrder ==="<<endl;
	postOrder(root);

	return 0;
}