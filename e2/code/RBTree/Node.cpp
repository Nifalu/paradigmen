#include "Node.h"
#include <string>

using namespace std;

int key;
string value;
int color;

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

int Node::getKey()
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

bool Node::isBlack()
{
    return (this->color == 0);
}

bool Node::isRed()
{
    return (this->color == 1);
}

std::string Node::getColor()
{
    if (this->color == 1) {
        return "R";
    } else {
        return "B";
    }
}

std::string Node::getValue()
{
    return this->value;
}

void Node::setValue(string s)
{
    this->value = s;
}

Node *Node::getParent()
{
    return this->parent_ptr;
}

Node *Node::getLeftChild()
{
    return this->lchild_ptr;
}

Node *Node::getRightChild()
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