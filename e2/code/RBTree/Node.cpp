#include "Node.h"
#include <string>

using namespace std;

/*
The Node holds the given information (key, value and color) 
and stores pointers to children and parent nodes.

It has getters and setters to access and manage its data.
*/


// Data stored in the node
int key;
string value;
int color;

// Node neighbors 
Node* parent_ptr;
Node* lchild_ptr;
Node* rchild_ptr;

// Constructor
Node::Node(int k, string v)
{
    this->key = k;
    this->value = v;
    this->color = 1; // RED

    this->parent_ptr = nullptr;
    this->lchild_ptr = nullptr;
    this->rchild_ptr = nullptr;
}

// Destructor
Node::~Node()
{
    delete this->lchild_ptr;
    delete this->rchild_ptr;
}



// GETTERS AND SETTERS -----------

int Node::getKey() const
{
    return this->key;
}

void Node::setKey(int k)
{
    this->key = k;
}

void Node::setRed()
{
    this->color = 1;
}

void Node::setBlack()
{
    this->color = 0;
}

bool Node::isBlack() const
{
    return (this->color == 0);
}

bool Node::isRed() const
{
    return (this->color == 1);
}

std::string Node::getColor() const
{
    if (this->color == 1) {
        return "R";
    } else {
        return "B";
    }
}

std::string Node::getValue() const
{
    return this->value;
}

void Node::setValue(string s)
{
    this->value = s;
}

Node *Node::getParent() const
{
    return this->parent_ptr;
}

Node *Node::getLeftChild() const
{
    return this->lchild_ptr;
}

Node *Node::getRightChild() const
{
    return this->rchild_ptr;
}

void Node::setParent(Node *n)
{
    this->parent_ptr = n;
}

void Node::setLeftChild(Node *n)
{
    this->lchild_ptr = n;
}

void Node::setRightChild(Node *n)
{
    this->rchild_ptr = n;
}