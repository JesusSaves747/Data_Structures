#ifndef AVL_NODE_H
#define AVL_NODE_H


#include <iostream>
#include <cstdlib>



template <class Item>
class AVL_node {

private:
  Item key;
  AVL_node* left;
  AVL_node* right;
  int height;

public:

  // Constructor:
  AVL_node(Item key){

    this->key = key;
    left = NULL;
    right = NULL;
    height =1; //Since the node is always inserted at the leaves first:
  }

  // Destructor: Using the default destructor:

  // Method to get left node pointer:

  // Method to get right node pointer:

  // Method to get height of node:


}
