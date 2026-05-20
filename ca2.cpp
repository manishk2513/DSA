#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Inserting in the BST
void insert(node* &root) {
    int data;
    cin >> data;

    if (data == -1) {
        root = NULL;
        return;
    }

    root = new node(data);

    cout << "  Enter LEFT  child of " << data << " (-1 for none): ";
    insert(root->left);

    cout << "  Enter RIGHT child of " << data << " (-1 for none): ";
    insert(root->right);
}

// INORDER TRAVERSAL
void inorder(node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// PREORDER TRAVERSAL
void preorder(node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// POSTORDER TRAVERSAL
void postorder(node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    node* root = NULL;

    cout << "Enter root node value (-1 for empty tree): ";
    insert(root);

    if (root == NULL) {
        cout << "\nTree is empty. Exiting.\n";
        return 0;
    }

    cout << "\n-----------------------------\n";
    cout << "Inorder   (L -> Root -> R): ";
    inorder(root);

    cout << "\nPreorder  (Root -> L -> R): ";
    preorder(root);

    cout << "\nPostorder (L -> R -> Root): ";
    postorder(root);

    cout << "\n-----------------------------\n";
    return 0;
}