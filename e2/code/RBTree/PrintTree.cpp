#include "PrintTree.h"
#include <iostream>

using namespace std;

/*
recusively visits every Node of the tree and prints it
to the console.
The tree is printed from left to right. So the root node
is in the center-left while the leaves are on the right.
*/

void printTreeHelper(Node *root, int space)
{
    int i;
    if (root != nullptr) {
        space = space + 20;
        printTreeHelper(root->getRightChild(), space);
        cout << endl;
        for (int i = 10; i < space; i++)
        {
            cout << " ";
        }
        cout << root->getKey() << " : "<< root->getValue() <<  " : " << root->getColor() << endl;
        printTreeHelper(root->getLeftChild(), space);
    }
}