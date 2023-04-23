#include "PrintTree.h"
#include <iostream>

using namespace std;

void printTreeHelper(Node *root, int space)
{
    int i;
    if (root != nullptr) {
        space = space + 20;
        printTreeHelper((*root).getRightChild(), space);
        cout << endl;
        for (int i = 10; i < space; i++)
        {
            cout << " ";
        }
        cout << (*root).getKey() << " : "<< (*root).getValue() <<  " : " << (*root).getColor() << endl;
        printTreeHelper((*root).getLeftChild(), space);
    }
}