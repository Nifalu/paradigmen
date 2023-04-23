#ifndef NODE_H
#define NODE_H
#include <string>

using namespace std;

class Node 
{
    public:
        /// @brief 
        /// @param key 
        /// @param value 
        /// @param parent 
        Node(int key, string value);


        int getKey();
        void setKey(int k);
        string getValue();
        void setValue(string s);
        Node* getParent();
        Node* getLeftChild();
        Node* getRightChild();
        void setParent(Node* n);
        void setLeftChild(Node* n);
        void setRightChild(Node* n);
        bool isRed();
        bool isBlack();
        void setRed();
        void setBlack();
        string getColor();


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