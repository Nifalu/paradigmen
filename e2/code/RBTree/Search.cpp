#include "Node.h"


/*
Compares the key of the current root with the given key and decides whether to
go left or right. Then calls itself recusively with the left or right child as new
"sub" root.
*/



Node* searchHelper(Node* root, int key)
{
    if (root == nullptr || (*root).getKey() == key)
    {
        return root;
    }
    else if (key < (*root).getKey())
    {
        return searchHelper(root->getLeftChild(), key);
    }
    else {
        return searchHelper(root->getRightChild(), key);
    }
}