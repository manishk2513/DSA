#include <iostream>
using namespace std;

const int M = 4;

class BTreeNode
{
public:

    int keys[M - 1];
    BTreeNode* children[M];

    int numKeys;

    bool leaf;

    BTreeNode(bool isLeaf)
    {
        leaf = isLeaf;
        numKeys = 0;

        for(int i = 0; i < M; i++)
        {
            children[i] = NULL;
        }
    }
};

class BTree
{
    BTreeNode* root;

public:

    BTree()
    {
        root = NULL;
    }

    void traverse(BTreeNode* node)
    {
        if(node == NULL)
            return;

        int i;

        for(i = 0; i < node->numKeys; i++)
        {
            if(!node->leaf)
            {
                traverse(node->children[i]);
            }

            cout << node->keys[i] << " ";
        }

        if(!node->leaf)
        {
            traverse(node->children[i]);
        }
    }

    void splitChild(BTreeNode* parent,
                    int index,
                    BTreeNode* child)
    {
        BTreeNode* newNode =
            new BTreeNode(child->leaf);

        newNode->numKeys = 1;

        // Copy last key
        newNode->keys[0] =
            child->keys[2];

        // Copy children if not leaf
        if(!child->leaf)
        {
            newNode->children[0] =
                child->children[2];

            newNode->children[1] =
                child->children[3];
        }

        child->numKeys = 1;

        for(int i = parent->numKeys;
            i >= index + 1; i--)
        {
            parent->children[i + 1] =
                parent->children[i];
        }

        parent->children[index + 1] =
            newNode;

        for(int i = parent->numKeys - 1;
            i >= index; i--)
        {
            parent->keys[i + 1] =
                parent->keys[i];
        }

        parent->keys[index] =
            child->keys[1];

        parent->numKeys++;
    }

    void insertNonFull(BTreeNode* node,
                       int value)
    {
        int i = node->numKeys - 1;

        if(node->leaf)
        {
            while(i >= 0 &&
                  value < node->keys[i])
            {
                node->keys[i + 1] =
                    node->keys[i];

                i--;
            }

            node->keys[i + 1] = value;

            node->numKeys++;
        }

        else
        {
            while(i >= 0 &&
                  value < node->keys[i])
            {
                i--;
            }

            i++;

            if(node->children[i]->numKeys
               == M - 1)
            {
                splitChild(node,
                           i,
                           node->children[i]);

                if(value > node->keys[i])
                {
                    i++;
                }
            }

            insertNonFull(node->children[i],
                          value);
        }
    }

    void insert(int value)
    {
        if(root == NULL)
        {
            root = new BTreeNode(true);

            root->keys[0] = value;

            root->numKeys = 1;
        }

        else
        {
            if(root->numKeys == M - 1)
            {
                BTreeNode* newRoot =
                    new BTreeNode(false);

                newRoot->children[0] =
                    root;

                splitChild(newRoot,
                           0,
                           root);

                int i = 0;

                if(newRoot->keys[0] < value)
                {
                    i++;
                }

                insertNonFull(
                    newRoot->children[i],
                    value);

                root = newRoot;
            }

            else
            {
                insertNonFull(root,
                              value);
            }
        }
    }

    void display()
    {
        traverse(root);
    }
};

int main()
{
    BTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);

    cout << "B-Tree Traversal:\n";

    tree.display();

    return 0;
}