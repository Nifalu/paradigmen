#include "Node.h"

Node* searchHelper(Node* root, int key)
{
    if (root == nullptr || (*root).getKey() == key)
    {
        return root;
    }
    else if (key < (*root).getKey())
    {
        return searchHelper((*root).getLeftChild(), key);
    }
    else {
        return searchHelper((*root).getRightChild(), key);
    }
}