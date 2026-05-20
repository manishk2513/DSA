#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

Node* insert(Node* root, int value)
{
    if(root == NULL)
    {
        return new Node(value);
    }

    if(value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}

bool search(Node* root, int key)
{
    if(root == NULL)
    {
        return false;
    }

    if(root->data == key)
    {
        return true;
    }

    if(key < root->data)
    {
        return search(root->left, key);
    }

    return search(root->right, key);
}

void inorder(Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

void preorder(Node* root)
{
    if(root == NULL)
        return;

    cout << root->data << " ";

    preorder(root->left);

    preorder(root->right);
}

void postorder(Node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);

    postorder(root->right);

    cout << root->data << " ";
}

Node* findMin(Node* root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

Node* deleteNode(Node* root, int key)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }

    else if(key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }

    else
    {
        // No child
        if(root->left == NULL &&
           root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // One child
        else if(root->left == NULL)
        {
            Node* temp = root->right;

            delete root;

            return temp;
        }

        else if(root->right == NULL)
        {
            Node* temp = root->left;

            delete root;

            return temp;
        }

        // Two children
        else
        {
            Node* temp = findMin(root->right);

            root->data = temp->data;

            root->right =
                deleteNode(root->right,
                           temp->data);
        }
    }

    return root;
}

int main()
{
    Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder Traversal:\n";
    inorder(root);

    cout << "\n\nSearching 40:\n";

    if(search(root, 40))
        cout << "Found";
    else
        cout << "Not Found";

    cout << "\n\nDeleting 70...\n";

    root = deleteNode(root, 70);

    cout << "\nInorder After Deletion:\n";
    inorder(root);

    return 0;
}