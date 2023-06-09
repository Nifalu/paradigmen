#include "RBTree.h"
#include "Node.h"
#include "Insert.h"
#include "Search.h"
#include "PrintTree.h"
#include <iostream>

Node* root;

using namespace std;

//empty constructor creates an empty tree instance
RBTree::RBTree() {
    this->root = nullptr;
}

//single input constructor creates a tree with one root node
RBTree::RBTree(int k, string v) 
{
    this->root = nullptr;
    this->insert(&k, &v);
}

//array input constructor creates a tree with the given key-value pairs.
RBTree::RBTree(int *keys, int k_len, string *vals, int v_len)
{
    if (k_len != v_len) 
    {
        cout << "Number of Keys is not equal ot Number of Values! " << endl;
    }
    this->root = nullptr;

    for (int i = 0; i < k_len; i++)
    {
        this->insert((keys+i), (vals+i));
    }
}

/* 
Deletes the root of the tree.
This calls the Destructor of "Node" which deletes both children of itself.
Since those children are also Nodes, they again delete both children of them.

So in the end, deleting the root node will recursively delete all Nodes of the tree.
*/
RBTree::~RBTree()
{
    delete this->root;
}




/*
Insert a key-value pair into the tree. When there is no tree yet, it creates root.
Read more in the "Insert.cpp" comment.
*/
void RBTree::insert(int* key, string* val)
{
    if (root == nullptr)
    {
        root = new Node(*key, *val);
        root->setBlack();
    }
    else
    {
        root = insertHelper(root, key, val, root);
    }
}


/*
Recusively searches for the given key in the tree.
*/
string RBTree::search(int key) const
{
    Node* n = searchHelper(this->root, key);
    if (n == nullptr)
    {
        return "";
    }
    else 
    {
        return n->getValue();
    }
}

/*
Prints the tree to console
*/
void RBTree::printTree()
{
    printTreeHelper(root, 0);
}


int main()
{
    
    int zips[14] = {
    1005, 9000, 1204,
    6060, 5034, 8057,
    8805, 2740, 3005, 
    4052, 3920, 4132, 
    6005, 3604
    };
    string names[14] = {
    "Lausanne", "St. Gallen", "Geneve", 
    "Sarnen", "Suhr", "Zurich", 
    "Richterswil", "Moutier", "Bern",
    "Basel", "Zermatt", "Muttenz",
    "Luzern", "Thun"
    };


    // Test all three construcots and the printTree method
    // All trees should look the same and fulfill the RBTree properties
    RBTree* tree1 = new RBTree(zips, 14, names, 14);
    tree1->printTree();
    cout << "----------------------------------------------------------------------------------------------" << endl;
    RBTree* tree2 = new RBTree(zips[0], names[0]);
    for (int i = 1; i < 14; i++) {
        tree2->insert(&zips[i], &names[i]);
    }
    tree2->printTree();
    cout << "----------------------------------------------------------------------------------------------" << endl;
    RBTree* tree3 = new RBTree();
        for (int i = 0; i < 14; i++) {
        tree3->insert(&zips[i], &names[i]);
    }
    tree3->printTree();
    cout << "----------------------------------------------------------------------------------------------" << endl;
    // Test search method. In tree3 the result should be empty
    cout << "search(4052) " << tree1->search(4052) << endl;
    cout << "search(4132) " << tree2->search(4132) << endl;
    cout << "search(5050) " << tree3->search(5050) << endl;

    // "test" the destructors.
    delete tree1;
    delete tree2;
    delete tree3;

    return 0;
}