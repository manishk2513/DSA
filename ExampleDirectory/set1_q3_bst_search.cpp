// Q3: Search for a given element in a Binary Search Tree and report whether it is found or not found.
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

bool search(Node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    if (key < root->data)
    {
        return search(root->left, key);
    }
    return search(root->right, key);
}

int main()
{
    Node *root = NULL;
    int n, value, key;

    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "Enter element to search: ";
    cin >> key;

    if (search(root, key))
    {
        cout << "Element found in BST.\n";
    }
    else
    {
        cout << "Element not found in BST.\n";
    }

    return 0;
}