#ifndef RBTREE_H
#define RBTREE_H
#include "Node.h"
#include <string>

using namespace std;

class RBTree
{
    public:
        RBTree();
        RBTree(int key, string val);
        RBTree(int* keys, int k_len, string* vals, int v_len);
        ~RBTree();
        
        void insert(int* key, string* val);
        string search(int key) const;
        void printTree();
    
    private:
        Node* root;
};
#endif // RBTREE_H