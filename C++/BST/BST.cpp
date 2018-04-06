// TO DO: Implement a Binary Search Tree(BST) using a linked implementation.
// The Data structure should support insertion, deletion and search operations:
#include <iostream>
#include <cstdlib>

using namespace std;

// Step 1: Create a class for the nodes of the binary tree: Or should I use a structure here. I think I'll use a stucture:
template<class Item>
struct BSTnode {

        // Data in the node:
        Item data;

        //Link to left child:
        BSTnode* left;

        // Link to right child:
        BSTnode* right;

        BSTnode(Item data, BSTnode<Item>* left = NULL, BSTnode<Item>* right = NULL){
                this->data = data;
                this->left = left;
                this->right = right;
        }

};   // https://stackoverflow.com/questions/2448242/struct-with-template-variables-in-c : This page says that typedef is not needed for stucts and classes. Need to verify this:


// Now create the class for the Binary Search Tree:
template <class Item>
class BST {


public:
// Pointer to the root node of the tree:
BSTnode<Item>* root;

// Counter for the number of elements in the tree:
size_t count;




// 1. Constructor: Basic one: Initialize the root node pointer with NULL:
BST() : root(NULL), count(0){
};

// 2. Method to insert a node into the tree: Recrusive function:
void insert(BSTnode<Item>*& node, Item key){

        // Extremely trivial case: Inserting the first node:
        if (node ==NULL) {
                node = new BSTnode<Item>(key);
                return;
        }

        // Trivial case:
        // #1:
        if (key<node->data ) {

                if (node->left ==NULL) {
                        node->left = new BSTnode<Item>(key);
                        return;
                }
                else{
                        insert(node->left, key);
                }

        }

        // #2:
        else if  (key > node->data) {

                if (node->right == NULL) {
                        node->right = new BSTnode<Item>(key);
                        return;
                }
                else{
                        insert(node->right, key);
                }

        }

}

// 3. Method to search for a node in the sub-tree:

// 4. Method to find the minimum among the nodes of a sub-tree:
BSTnode<Item>* findMin(BSTnode<Item>* node){

        // Trivial case: If the left child is NULL , then this is the minimum node: By property of BST:
        if (node->left == NULL) {
                return node;
        }

        // Otherwise recurse with the left child:
        else{
                findMin(node->left);
        }


}

// 5. Method to delete a node from the sub-tree:
bool deleteNode(BSTnode<Item>*& node, Item key){

        // If the node is a NULL node:
        if (node == NULL){
          return false;
        }

        // Leaf node case:
        if (node->left ==NULL && node->right ==NULL){
          return false;
        }

        // Termination case: If the key is equal to the root:
        if (key == node->data) {

                // Find the node with the minimum key in the right sub-tree:
                BSTnode<Item>* minNode = findMin(node->left->right);

                // Replace the data in current node's left child with the data in the minNode:
                node->left->data = minNode->data;

                // Delete the node pointed to by minNode:
                delete minNode;

                return true;

        }



        // Check whether key is greater than or less than the node's data value:
        if (key< node->data && node->left != NULL) {

                // Check whether key is equal to left child data:
                if (key == node->left->data) {
                        // If yes then: 3 cases:
                        // If left child has no children:
                        if (node->left->left ==NULL && node->left->right ==NULL) {

                                delete node->left;
                                node->left =NULL;
                                return true;
                        }

                        // If left child has only a right child:
                        else if (node->left->left ==NULL) {
                                BSTnode<Item>* tempNodePtr = node->left;
                                node->left = node->left->right;
                                delete tempNodePtr;
                                //tempNodePtr =NULL;
                                return true;
                        }

                        // If left child has only a left child:
                        else if (node->left->right ==NULL) {
                                BSTnode<Item>* tempNodePtr = node->left;
                                node->left = node->left->left;
                                delete tempNodePtr;
                                //tempNodePtr =NULL;
                                return true;
                        }

                        // If left child has two children:
                        else {

                                // Find the node with the minimum key in the right sub-tree:
                                BSTnode<Item>* minNode = findMin(node->left->right);

                                // Replace the data in current node's left child with the data in the minNode:
                                node->left->data = minNode->data;

                                // Delete the node pointed to by minNode:
                                delete minNode;

                                //minNode =NULL;

                                return true;

                        }
                }
                else{
                        // If no then:
                        // Execute delete node with left child:
                        deleteNode(node->left, key);
                }

        }

        // If key is greater than current node's data:
        else if (node->right != NULL){

                // Check whether key is equal to right child data:
                if (key == node->right->data) {


                        // If yes then: 3 cases:
                        // If right child has no children:
                        if (node->right->left ==NULL && node->right->right ==NULL) {

                                delete node->right;
                                node->right = NULL;
                                return true;
                        }

                        // If right child has only a right child:
                        else if (node->right->left ==NULL) {
                                BSTnode<Item>* tempNodePtr = node->right;
                                node->right = node->right->right;
                                delete tempNodePtr;
                                //tempNodePtr = NULL;
                                return true;
                        }

                        // If right child has only a left child:
                        else if (node->right->right ==NULL) {
                                BSTnode<Item>* tempNodePtr = node->right;
                                node->right = node->right->left;
                                delete tempNodePtr;
                                //tempNodePtr =NULL;
                                return true;
                        }

                        // If left child has two children:
                        else {

                                // Find the node with the minimum key in the right sub-tree:
                                BSTnode<Item>* minNode = findMin(node->right->right);

                                // Replace the data in current node's left child with the data in the minNode:
                                node->right->data = minNode->data;

                                // Delete the node pointed to by minNode:
                                delete minNode;

                                //minNode = NULL;

                                return true;

                        }

                }

                // If no then:
                else{
                        // Execute delete node with right child:
                        deleteNode(node->right,key);
                }




        } // END IF (key < node->data)

}

// 5. Print nodes of tree in pre-order traversal:
// A utility function to print preorder traversal
// of the tree.
void preOrder(BSTnode<Item>* root)
{
        if(root != NULL)
        {
                cout<<root->data<<" , ";
                preOrder(root->left);
                preOrder(root->right);
        }
}

// 6. Print nodes of tree in in-order traversal:
// A utility function to print inorder traversal
// of the tree.  e
void inOrder(BSTnode<Item>* root)
{
        if(root != NULL)
        {

                inOrder(root->left);
                cout<<root->data<<" , ";
                inOrder(root->right);
        }
}

};


// Main function to test out the implementation:
int main(int argc, char const *argv[]) {

        BST<double>* myTree = new BST<double>();

        /* Constructing tree given in the above figure */

        // Now allow the user to enter in the elements:
        cout<<" Please enter in the keys to be added to the BST"<<endl;

        cout<<" Please input the entries of the BST . Press 'q' to quit"<<endl;

        string userInput;

        bool stopLoop = false;

        while (!stopLoop) {


                getline(cin,userInput);

                try {

                        int userNumInput = stoi(userInput);
                        myTree->insert(myTree->root, userNumInput);

                }
                catch (const std::invalid_argument& ia) {


                        if (userInput[0] == 'q' || userInput[0]=='Q') {
                                stopLoop =true;
                        }
                        else{
                                std::cerr << "Invalid argument: " << ia.what() << '\n';
                        }

                }

        } //END while loop


        cout<<"Inorder traversal of the constructed BST is "<<endl;
        myTree->inOrder(myTree->root);
        cout<<endl;


      //   // Delete a particular node:
      //   int userNumInput;
      //   cout<<"Enter the key to delete"<<endl;
      //   cin>>userNumInput;
      //
      //   if (myTree->deleteNode(myTree->root,userNumInput)){
      //
      //   cout<<" Key successfully deleted"<<endl;
      //   cout<<"Inorder traversal of the BST after deletion is "<<endl;
      //   myTree->inOrder(myTree->root);
      //   cout<<endl;
      //
      // }
      // else {
      //   cout<<" Requested key does not exist in the Tree. Sorry!"<<endl;
      // }


        return 0;
}
