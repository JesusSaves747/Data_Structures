#include <iostream>
#include <cstdlib>

using namespace std;


// Template of a structure to hold the data for each node:
struct Node{

    int key;
    Node* left;
    Node* right;
    int height;

};

// Function to initialize a new Node:
Node* newNode(int key){

  Node* node = new Node();
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node-> height = 1; // Node is usually inserted at the leaf:

  return node;
}

// Other functions to go here:

// 1. Function to get the height of a node:
int getHeight(Node* N){
    if (N== NULL){
      return 0
    }
    else {
      return N->height;
    }

}

// 2. Function to check the balance of a node:
int checkBalance(Node*  N){

  return height(N->left) - height(N->right);

}

// 3. Function to right rotate a node rooted at y:
// Pre-conditions: x is its left child, T2 is the right child of x:
// Post-condition : return the new root of the rotated sub-tree:
// Coding convention: camelCase for variables and underscores for function names??
Node* rightRotate(Node* y){

  // Create place holders for x and T2:
  Node* x = y->left;
  Node* T2 = x->right;

  // Now perform the rotation operations:
  y->left = T2;
  x->right = y;

  // Update the heights of the nodes: x and y: Why not a simple increment here?
  y->height = max(height(y->left), height(y->right))+1;
  x->height = max(height(x->left), height(x->right))+1;

  //Return the new root of the sub-tree:
  return x;

}

// 4. Function to peform left-rotate of a sub-tree rooted at y:
// Pre-condition: x is the right child of y and T2 is the left child of x:
Node* leftRotate(Node) {

  // Placeholders for x and T2:
  Node* x = y->right;
  Node* T2 = x->left;

  //Perform the left rotate here:
  y->right = T2;
  x-> left = y;

  // Update the heights of the nodes: x and y only:
  y->height = max(height(y->left), height(y->right))+1;
  x->height = max(height(x->left), height(x->right))+1;

  //Return the new root of the sub-tree:
  return x;

}

// Function to insert a new entry into the AVL tree: Recursive function that inserts a key into the AVL sub-tree:
Node* insert(Node* root, int key){

  // 

}




int main(int argc, char const *argv[]) {

  Node* firstNode;


  firstNode = newNode(4);


  cout<<" The key of the node is "<<firstNode->key<<endl;
  return 0;
}
