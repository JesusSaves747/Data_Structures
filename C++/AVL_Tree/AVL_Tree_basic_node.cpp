#include <iostream>
#include <cstdlib>
#include <ctype.h>
#include <stdlib.h>
#include <string>
#include <ctime>

using namespace std;


// Template of a structure to hold the data for each node:
struct Node {

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
        node->height = 1; // Node is usually inserted at the leaf:

        return node;
}

// Other functions to go here:

// 1. Function to get the height of a node:
int height(Node* N){
        if (N== NULL) {
                return 0;
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
Node* leftRotate(Node* y) {

        // Placeholders for x and T2:
        Node* x = y->right;
        Node* T2 = x->left;

        //Perform the left rotate here:
        y->right = T2;
        x->left = y;

        // Update the heights of the nodes: x and y only:
        y->height = max(height(y->left), height(y->right))+1;
        x->height = max(height(x->left), height(x->right))+1;

        //Return the new root of the sub-tree:
        return x;

}

// Function to insert a new entry into the AVL tree: Recursive function that inserts a key into the AVL sub-tree:
Node* insert(Node* node, int key){

        // Algorithm: TO BE DONE!!!
        // 1. Insert the key as in a normal binary search tree. Use recursive function:
        if (node == NULL)
                return(newNode(key));

        if (key < node->key)
                node->left  = insert(node->left, key);
        else if (key > node->key)
                node->right = insert(node->right, key);
        else // Equal keys are not allowed in BST
                return node;


        // 2. At each level of the recursive function update the heights of the nodes:
        node->height = 1 + max(height(node->left),
                               height(node->right));

        // 3. Now at each level check the balance of the node. So what do we do if the node is unbalanced??
        int balance = checkBalance(node);

        // 4. Four possible cases exist:
        // 4.a:Left-Left case: Left sub-tree is taller and key is less than left child of node :
        // Action: Perform rightRotate and return node
        if (balance > 1 && key < node->left->key) {
                return rightRotate(node);
        }

        // 4.b Left-Right case: Left sub-tree is taller and key is greater than left child of node:
        // Action: Perform leftRotate on left child of node, then perform rightRotate on node and return the the node
        if (balance > 1 && key > node->left->key) {

                node->left = leftRotate(node->left);
                return rightRotate(node);
        }

        // 4.c:Right-right case: Right sub-tree is taller and key is greater than right child of node
        // Action: Perform leftRotate on node and return the node
        if (balance < -1 && key > node->right->key) {
                return leftRotate(node);
        }

        // 4.d: Right-left case: Right sub-tree is taller and key is less than right child of node:
        // Action: Perform rightRotate on right child of node, then perfrom leftRotate on node and return the node.
        if (balance < -1 && key < node->right->key) {
                node->right = rightRotate(node->right);
                return leftRotate(node);
        }


        // Trivial case: If the node is balanced then return the node as is without any rotations:
        return node;
}


// A utility function to print preorder traversal
// of the tree.  The function also prints height of every node
void preOrder(Node* root)
{
        if(root != NULL)
        {
                cout<<root->key<< "("<<root->height<<")"<< " ' ";
                preOrder(root->left);
                preOrder(root->right);
        }
}



// Main function to test the implementation of AVL trees:
int main(int argc, char const *argv[]) {

        Node* root = NULL;

        /* Constructing tree given in the above figure */

        // Now allow the user to enter in the elements:
        cout<<" Please enter in the keys to be added to the AVL Tree"<<endl;

        cout<<" Please input the entries of the Heap . Press 'q' to quit"<<endl;

        string userInput;

        bool stopLoop = false;

        while (!stopLoop) {


                getline(cin,userInput);

                try {

                        int userNumInput = stoi(userInput);
                        root = insert(root, userNumInput);
                }
                catch (const std::invalid_argument& ia) {


                        if (userInput[0] == 'q' || userInput[0]=='Q') {
                                stopLoop =true;
                        }
                        else{
                                std::cerr << "Invalid argument: " << ia.what() << '\n';
                        }

                }

        }  //END while loop


        cout<<"Preorder traversal of the constructed AVL tree is "<<endl;
        preOrder(root);
        cout<<endl;
        return 0;
}
