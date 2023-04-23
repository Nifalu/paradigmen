#include "Node.h"
#include "RBTree.h" 
#include "Insert.h"


// some flags that control what rotations need to be done.
bool ll = false;
bool rr = false;
bool lr = false;
bool rl = false;

Node* rotateRight(Node* node) {
    Node* x = (*node).getLeftChild();
    Node* y = (*x).getRightChild();
    (*x).setRightChild(node);
    (*node).setLeftChild(y);
    (*node).setParent(x);
    if (y != nullptr)
    {
        (*y).setParent(node); 
    }
    return(x);
}

Node* rotateLeft(Node* node) {
    Node* x = (*node).getRightChild();
    Node* y = (*x).getLeftChild();
    (*x).setLeftChild(node);
    (*node).setRightChild(y);
    (*node).setParent(x);
    if (y != nullptr)
    {
        (*y).setParent(node);
    }
    return(x);
}

// root points to the current node while groot points to the root of the entire tree
Node* insertHelper(Node* root, int* k, string* v, Node* groot)
{
    // f is true when there is a RED RED conflict
    bool f = false;

    // Recursively find proper position for insertion.
    if ( root == nullptr) 
    {
        return (new Node(*k, *v));
    } 
    else if (*k < (*root).getKey()) 
    {
        (*root).setLeftChild(insertHelper((*root).getLeftChild(), k, v, groot));
        (*(*root).getLeftChild()).setParent(root);
        if (root != groot)
        {
            if ((*root).isRed() && (*(*root).getLeftChild()).isRed()) {
                f = true; // there is a RED RED conflict!
            }
        }
    }
    else
    {
        (*root).setRightChild(insertHelper((*root).getRightChild(), k, v, groot));
        (*(*root).getRightChild()).setParent(root);
         if (root != groot)
        {
            if ((*root).isRed() && (*(*root).getRightChild()).isRed()) {
                f = true; // there is a RED RED conflict!
            }
        }


    // Node is inserted and connected to its parent. RED RED conflict flag is checked and set.
    }
    

    if (ll) // left rotation
    {
        root = rotateLeft(root);
        (*root).setBlack(); // Black
        (*(*root).getLeftChild()).setRed(); // Red
        ll = false;
    }
    else if (rr) // right rotation
    {
        root = rotateRight(root);
        (*root).setBlack(); // Black
        (*(*root).getRightChild()).setRed(); // Red
        rr = false;
    }
    else if (rl) // right left rotation
    {
        (*root).setRightChild(rotateRight((*root).getRightChild()));
        (*(*root).getRightChild()).setParent(root);
        root = rotateLeft(root);
        (*root).setBlack(); // Black
        (*(*root).getLeftChild()).setRed(); // Red
        rl = false;
    }
    else if (lr) // left right rotation
    {
        (*root).setLeftChild(rotateLeft((*root).getLeftChild()));
        (*(*root).getLeftChild()).setParent(root);
        root = rotateRight(root);
        (*root).setBlack(); // Black
        (*(*root).getRightChild()).setRed(); // Red
        lr = false;
    }

    // solve RED RED conflict
    if (f)
    {
        if((*(*root).getParent()).getRightChild() == root)
        {
            if ((*(*root).getParent()).getLeftChild() == nullptr || (*(*(*root).getParent()).getLeftChild()).isBlack()) 
            {
                if((*root).getLeftChild() != nullptr && (*(*root).getLeftChild()).isRed())
                {
                    rl = true;
                }
                else if ((*root).getRightChild() != nullptr && (*(*root).getRightChild()).isRed())
                {
                    ll = true;
                }
            }
            else // case when parents sibling is red 
            {
                (*(*(*root).getParent()).getLeftChild()).setBlack();
                (*root).setBlack();
                if ((*root).getParent() != groot)
                {
                    (*(*root).getParent()).setRed();
                }
            }
        }
        else
        {
            if ((*(*root).getParent()).getRightChild() == nullptr || (*(*(*root).getParent()).getRightChild()).isBlack()) 
            {
                if((*root).getLeftChild() != nullptr && (*(*root).getLeftChild()).isRed())
                {
                    rr = true;
                }
                else if ((*root).getRightChild() != nullptr && (*(*root).getRightChild()).isRed())
                {
                    lr = true;
                }
            }
            else
            {
                (*(*(*root).getParent()).getRightChild()).setBlack();
                (*root).setBlack();
                if ((*root).getParent() != groot)
                {
                    (*(*root).getParent()).setRed();
                }
            } 
        }
        f = false;
    }
    
    return (root);
}