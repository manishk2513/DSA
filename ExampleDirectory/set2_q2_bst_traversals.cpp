// Q2: Insert nodes into a Binary Search Tree and display preorder, inorder, and postorder traversals.
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int value)
{
    Node *temp = new Node;
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    Node *root = NULL;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "Preorder: ";
    preorder(root);
    cout << '\n';
    cout << "Inorder: ";
    inorder(root);
    cout << '\n';
    cout << "Postorder: ";
    postorder(root);
    cout << '\n';

    return 0;
}