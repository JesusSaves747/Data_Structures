// Implementation of the functions of the LinkedList Class:
#include "LinkedList.h"


// 3. Insert a node with the given value at the head of the list:
void LinkedList::insert_head(int usrVal){

  // Strategy: Create a new node with the usrVal. Assign the next pointer of the new node to point to HeadPtr. Make HeadPtr point to the new node:
  LLNode* newNode = new LLNode(usrVal, HeadPtr);

  HeadPtr = newNode;

}

// 5. Remove a node from the list:
bool LinkedList::remove_node(int usrVal){

  // Strategy: Traverse through the Linked List until the node with the value is found.

  // Base case: Node to be removed is at the head of the list:
  if (HeadPtr->val == usrVal){

    remove_head();

    return true;
  }

  else{

  for (LLNode* cursor = HeadPtr; cursor != NULL; cursor = cursor->next){
    if (cursor->next->val == usrVal){

      // Create a temporary pointer to the node to be deleted:
      LLNode* tempPtr = cursor->next;

      // Shift the next pointer of the previous node ahead by 1 node:
      cursor->next = cursor->next->next;

      // Delete the target node:
      delete tempPtr;

      return true;

    }

  }
}

  // Target node does not exist in the list:
  return false;
}

// 6.1 Reverse the elements of a linked list:
void LinkedList::reverse_v1(){

  // Strategy: Loop through the list and reverse the next pointers of the nodes:
  LLNode* cursor = HeadPtr;
  LLNode* nextNodePointer = cursor->next;
  LLNode* tempPtr = nextNodePointer->next;

  while (tempPtr!= NULL){

      if (cursor == HeadPtr){
        cursor->next = NULL;
      }

      // Make the next node point to the current node:
      nextNodePointer->next = cursor;

      // Move the cursor one node forward:
      cursor = nextNodePointer;

      // Make the nextNodePointer now point to tempPtr:
      nextNodePointer = tempPtr;

      // Move the tempPtr one node forward:
      tempPtr = tempPtr->next;

  }

  nextNodePointer->next = cursor;

  // Assign the HeadPtr to the current nextNodePointer:
  HeadPtr = nextNodePointer;

}


// 6. Reverse the elements of the Linked List:
void LinkedList::reverse(){

  queue<int> tempQ;

  // Remove the elements from the head one by one and put the elements in a queue:
  while (HeadPtr != NULL){

    tempQ.push(remove_head());

  }

  // Now pop the elements one by one and insert them at the head of the list:
  while (! tempQ.empty()){

    insert_head(tempQ.front());

    tempQ.pop();

  }

}

// 7. Rotate the elements of a list about a target value:
void LinkedList::rotate(int target){

  stack<int> tempStack;
  bool reachedTarget = false;

  // Loop through the list until we reach the target element: After the target element push all elements on the Stack:
  //for (LLNode* cursor = HeadPtr; cursor != NULL; cursor = cursor->next)
  LLNode* cursor = HeadPtr;

  while (cursor != NULL)
  {
    if (reachedTarget){

      tempStack.push(cursor->val);
      LLNode* tempPtr = cursor;
      cursor = cursor->next;
      delete tempPtr;
      continue;

    }
    else if (cursor->val == target){
      reachedTarget = true;
      LLNode* tempPtr = cursor;
      cursor = cursor->next;
      tempPtr->next = NULL;
    }
    else{
    cursor = cursor->next;
  }

  }

  // Now insert the elements from the stack at the head of the list:
  while (!tempStack.empty()){


    insert_head(tempStack.top());

    tempStack.pop();

  }

}

// 8. Remove element at the head of the list:
int LinkedList::remove_head(){

    // Assign a temporary pointer to the Head node:
    LLNode* tempPtr = HeadPtr;

    // Move the HeadPtr ahead:
    HeadPtr = HeadPtr->next;

    //  Get the value of the head node:
    int val = tempPtr->val;

    // Delete the node pointed to by the tempPtr:
    delete tempPtr;

    return val;
}

// 9. Print the elements in the LinkedList:
void LinkedList::print(){

  cout<<" The linked list elements are: "<<endl;

  for (LLNode* cursor = HeadPtr; cursor != NULL; cursor = cursor->next){

    cout<<cursor->val<<" , ";

  }

  cout<<endl;

}

// 10 . Find the middle element of the list and return its value:
int LinkedList::find_middle(){

  // Strategy: Loop through the list and keep storing the values of the list in a vector of ints.
  // At the end of the list return the middle element of the vector: TO DO: There must be  a way to do this without using auxiliary storage:

  vector<int> tempStore;

  for (LLNode* cursor = HeadPtr; cursor != NULL; cursor = cursor->next){
    tempStore.push_back(cursor->val);
  }

  // Get the index of the middle element:
  int mid_index = floor(tempStore.size()/2);

  return tempStore[mid_index];

}

// 10.1  Find the middle element of the list and return its value: Without extra memory:
int LinkedList::find_middle_v1(){

  // Moeve two cursors along the LinkedList : One at half speed and one at full speed:
  LLNode* cursor = HeadPtr;
  LLNode* mid_cursor = cursor;

  bool moveMidCursor = false;

  while (cursor != NULL){

    cursor = cursor->next;

    if (moveMidCursor){
      mid_cursor = mid_cursor->next;
      moveMidCursor = false;
    }
    else{
      moveMidCursor = true;
    }

  }

  return mid_cursor->val; // Hopefully this is the middle element:


}

// 11.
