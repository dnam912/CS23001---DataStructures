#include <iostream>
using namespace std;
 

struct Node {
    int data;
    struct Node *left, *right;
};


// Function to check the given key exist or not
bool iterativeSearch(struct Node* root, int key)
{
    // Traverse until root reaches to dead end
    while (root != NULL) {
        // pass right subtree as new tree
        if (key > root->data)
            root = root->right;
 
        // pass left subtree as new tree
        else if (key < root->data)
            root = root->left;
        else
            return true; // if the key is found return 1
    }
    return false;
}
 
// A utility function to create a new BST Node
struct Node* newNode(int item)
{
    struct Node* temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

/* A utility function to insert a new Node with
   given key in BST */
struct Node* insert(struct Node* Node, int data)
{
    /* If the tree is empty, return a new Node */
    if (Node == NULL)
        return newNode(data);
 
    /* Otherwise, recur down the tree */
    if (data < Node->data)
        Node->left = insert(Node->left, data);
    else if (data > Node->data)
        Node->right = insert(Node->right, data);
 
    /* return the (unchanged) Node pointer */
    return Node;
}
 