#ifndef INSERT_H
#define INSERT_H
#include "Node.h"
#include "RBTree.h"

Node* rotateRight(Node* n);
Node* rotateLeft(Node* n);
Node* insertHelper(Node* root, int* k, string* v, Node* groot);
#endif // INSERT_H