#include <iostream>
#include <vector>

using namespace std;

// Class or sturcture for a Binary Tree node: Using a template structure:
template<class Item>
struct BTnode{
  Item key;
  BTnode* left;
  BTnode* right;
};


// Method to insert nodes in the tree: Recursive function:
void insert(BTnode<Item>*& node, Item key){

    // In case the key is less than the key of the node
    if (key < node->key){

    }

}


// Method to delete a node from a tree:

// Method to traverse the tree- Pre-order:
