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
	
	TreeNode(int data, TreeNode *left, TreeNode *right){
		this->data = data;
		this->left = left;
		this->right = right;
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

void preOrder(TreeNode *root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<endl;
	preOrder(root->left);
	preOrder(root->right);
}

int main() {
	TreeNode *root = NULL;
	insert(root);

	cout<<"=== preOrder ==="<<endl;
	preOrder(root);

	return 0;
}