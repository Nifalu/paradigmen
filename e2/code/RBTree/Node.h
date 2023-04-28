#ifndef NODE_H
#define NODE_H
#include <string>

using namespace std;

class Node 
{
    public:
        Node(int key, string value);


        int getKey() const;
        void setKey(int k);
        string getValue() const;
        void setValue(string s);
        Node* getParent() const;
        Node* getLeftChild() const;
        Node* getRightChild() const;
        void setParent(Node* n);
        void setLeftChild(Node* n);
        void setRightChild(Node* n);
        bool isRed() const;
        bool isBlack() const;
        void setRed();
        void setBlack();
        string getColor() const;

        ~Node();

    private:
        int key;
        string value;
        int color;
        Node* parent_ptr;
        Node* lchild_ptr;
        Node* rchild_ptr;
};

#endif // NODE_H