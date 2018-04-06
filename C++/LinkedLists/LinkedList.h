#include <iostream>
#include <cstdlib>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Structure to represent the node of a linked list of integers:
struct LLNode{

  int val;
  LLNode* next;
  LLNode(int usrVal = 0, LLNode* usrNext = NULL ) : val(usrVal) , next(usrNext){};

};



// Class to implement and linked list and all its functions:
class LinkedList{


private:
    LLNode* HeadPtr;

public:

    // 1. Constructor:
    LinkedList(){

      HeadPtr = new LLNode(100);

    }


    // 2. Destructor: Use default:

    // 3. Get the HeadPtr of the Linked List:
    LLNode* getHeadPtr(){
      return HeadPtr;
    }

    // 3. Insert a node with the given value at the head of the list:
    void insert_head(int usrVal);

    // 4. Insert a node with the given value after a certain target node:
    void insert_target(int targetVal, int usrVal);

    // 5. Remove a node from the list:
    bool remove_node(int usrVal);


    // 6. Reverse the elements of a linked list:
    void reverse();

    // 6.1 Reverse the elements of a linked list:
    void reverse_v1();

    // 7. Rotate the elements of a list about a target value:
    void rotate(int target);


    // 8. Remove the element at the Head of the list and return its value:
    int remove_head();

    // 9. Print the elements in the LinkedList:
    void print();

    // 10 . Find the middle element of the list and return its value:
    int find_middle();

    // 10.1  Find the middle element of the list and return its value: Without extra memory:
    int find_middle_v1();

};
