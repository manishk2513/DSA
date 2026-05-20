#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value)
    {
        data = value;
        left = right = NULL;
        height = 1;
    }
};

int getHeight(Node* root)
{
    if(root == NULL)
        return 0;

    return root->height;
}

int getBalance(Node* root)
{
    if(root == NULL)
        return 0;

    return getHeight(root->left)
           - getHeight(root->right);
}

Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height =
        max(getHeight(y->left),
            getHeight(y->right)) + 1;

    x->height =
        max(getHeight(x->left),
            getHeight(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height =
        max(getHeight(x->left),
            getHeight(x->right)) + 1;

    y->height =
        max(getHeight(y->left),
            getHeight(y->right)) + 1;

    return y;
}

Node* insert(Node* root, int value)
{
    // Normal BST insertion
    if(root == NULL)
    {
        return new Node(value);
    }

    if(value < root->data)
    {
        root->left = insert(root->left, value);
    }

    else if(value > root->data)
    {
        root->right = insert(root->right, value);
    }

    else
    {
        return root;
    }

    // Update height
    root->height =
        1 + max(getHeight(root->left),
                getHeight(root->right));

    // Get balance factor
    int balance = getBalance(root);

    // LL Case
    if(balance > 1 &&
       value < root->left->data)
    {
        return rightRotate(root);
    }

    // RR Case
    if(balance < -1 &&
       value > root->right->data)
    {
        return leftRotate(root);
    }

    // LR Case
    if(balance > 1 &&
       value > root->left->data)
    {
        root->left = leftRotate(root->left);

        return rightRotate(root);
    }

    // RL Case
    if(balance < -1 &&
       value < root->right->data)
    {
        root->right = rightRotate(root->right);

        return leftRotate(root);
    }

    return root;
}

void inorder(Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

int main()
{
    Node* root = NULL;

    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);

    cout << "Inorder Traversal:\n";

    inorder(root);

    return 0;
}