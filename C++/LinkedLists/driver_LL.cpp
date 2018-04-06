#include "LinkedList.h"

LLNode* merge_k_lists(vector<LLNode*> headPtrs){

  // How to approach this: ?
  // 1. Find the list whose first element is the least among all: Get the index of that headPtr:
  //Set that as Base list and get cursor_base to point to that list's first element. Store the headPtr to that list as res:
  LLNode* cursor_base = headPtrs[0];
  vector<LLNode*> cursor_aux = headPtrs;
  int idxBase =0;

  int nLists = headPtrs.size();

  for (int k =0; k < nLists; k++){
    if (headPtrs[k]< cursor_base){
      cursor_base = headPtrs[k];
      idxBase = k;
    }

  }

  // 2 Until cursor base does not reach the end:

      // 2.1 : Loop over the other lists and for each list:
              // 2.1.1 :  if cursor_base-> next > cursor_aux[k]->val:
                  // insert cursor_aux[k]->val ahead of cursor_base->val -- Increment cursor_aux[k]

cout<<" Reached  up to first loop"<<endl;
  // Outer Loop: As long as we havent reached the end of the base list
  while (cursor_base ->next != NULL){

    // Inner loop over the remaining lists:
    for (int k=0; k< nLists; k++){

      cout<<" Made it inside first inner loop"<<endl;

      if (k != idxBase && cursor_aux[k]!= NULL && cursor_base->next->val > cursor_aux[k]->val){

        // Insert cursor_aux[k] after cursor_base and cursor_base->next after cursor_aux[k]: But get a Temp Pointer to cursor_aux[k]->next:
        LLNode* base_next_temp = cursor_base->next;
        cursor_base->next = cursor_aux[k];

        cursor_base->next->next = base_next_temp;

        // Move cursor_aux forward in the kth list:
        cursor_aux[k] = cursor_aux[k]->next;

      }
    }

    // Now move the base cursor forward by one:
    cursor_base = cursor_base->next;
  }

  cout<<" Made it up to second outer loop"<<endl;

  // 3. The case when we have reached the end of the base list:
  bool stopLoop = false;

  while (!stopLoop){

    stopLoop = true;

    for (int k=0; k< nLists; k++){

      cout<<" Value of k is"<<k<<endl;

      if (cursor_aux[k]!= NULL){

        cout<<" Cursor value is "<<cursor_aux[k]->val<<endl;

        cout<<" Made it inside big if "<<endl;

        // Switch the flag to keep the loop going:
        stopLoop = false;

        if (cursor_base->next == NULL){
          cursor_base->next = new LLNode(cursor_aux[k]->val);
          cursor_aux[k] = cursor_aux[k]->next;
          cout<<" Next Cursor value is "<<cursor_aux[k]->next->val<<endl;
          int c = getchar();
        }
        else if (cursor_base->next->val > cursor_aux[k]->val){
          // Insert cursor_aux[k] after cursor_base and cursor_base->next after cursor_aux[k]: But get a Temp Pointer to cursor_aux[k]->next:
          LLNode* base_next_temp = cursor_base->next;
          cursor_base->next = cursor_aux[k];

          cursor_base->next->next = base_next_temp;

          // Move cursor_aux forward in the kth list:
          cursor_aux[k] = cursor_aux[k]->next;
        }
  }


}

  // Now move the base cursor forward by one:
  cursor_base = cursor_base->next;


}

// HeadPtr of the base list
return headPtrs[idxBase];

}




LLNode* merge_2_lists(LLNode* head1, LLNode* head2){
// Your Code Here:
// Create two pointers that will iterate through the two lists:

// TBD: Whether head one will be returned or head two:
bool return1;
LLNode* cursor_base;
LLNode* cursor_aux;

if (head1->val < head2->val){
cursor_base = head1;
cursor_aux  = head2;
return1 = true;
}
else{
     cursor_base = head2;
     cursor_aux  = head1;
    return1 = false;
}

while (cursor_base->next != NULL && cursor_aux!= NULL){

    if (cursor_base->next->val > cursor_aux->val){

        // Insert cursor 2 after cursor 1 and cursor1->next after cursor 2: But get a Temp Pointer to cursor2->next:
        LLNode* base_next_temp = cursor_base->next;
        cursor_base->next = cursor_aux;

        LLNode* aux_next_temp = cursor_aux->next;
        cursor_aux->next = base_next_temp;

        // Move cursor_aux forward in the second list:
        cursor_aux = aux_next_temp;

        // Move cursor_base forward:
        cursor_base = cursor_base->next;

    }

    //Otherwise simply move cursor_base forward by one node:
    else{
        cursor_base = cursor_base->next;
    }
}

while (cursor_aux != NULL){

    cursor_base->next = cursor_aux;

    cursor_base = cursor_base->next;
    cursor_aux = cursor_aux->next;

}

if (return1)
    return head1;
else
    return head2;

}


// Driver function for Main Program:

int main(int argc, char const *argv[]) {

  LinkedList myList;

  LinkedList myList2;

  LinkedList myList3;

  LinkedList myList4;



  // Insert elements into the list:
  myList.insert_head(19);
  myList.insert_head(17);
  myList.insert_head(15);
  myList.insert_head(13);

  myList.remove_node(100);

  //Print the elements in the list:
  myList.print();


  myList4.insert_head(11);
  myList4.insert_head(9);
  myList4.insert_head(7);
  myList4.insert_head(5);
  myList4.insert_head(3);

  myList4.remove_node(100);

  //Print the elements in the list:
  myList4.print();

  // Insert elements into the list:
  myList3.insert_head(18);
  myList3.insert_head(16);
  myList3.insert_head(14);
  myList3.insert_head(12);
  myList3.insert_head(10);

  myList3.remove_node(100);

  //Print the elements in the list:
  myList3.print();

  myList2.insert_head(8);
  myList2.insert_head(6);
  myList2.insert_head(4);
  myList2.insert_head(2);

  myList2.remove_node(100);

  //Print the elements in the list:
  myList2.print();

  // Create a vector of headPtrs:

  vector<LLNode*> inputHeadPtrs = {myList.getHeadPtr(), myList2.getHeadPtr(), myList3.getHeadPtr(), myList4.getHeadPtr()};



  //LLNode* tempList = merge_2_lists(myList->getHeadPtr(), myList2->getHeadPtr());

  LLNode* tempHead = merge_k_lists(inputHeadPtrs);

  cout<<" And the result is ...Wait for it ....."<<endl;
  for (LLNode* cursor = tempHead; cursor != NULL; cursor = cursor->next){

    cout<<cursor->val<<" , ";

  }

  cout<<endl;




  // // Now remove one element from the list:
  // myList.remove_node(100);
  //
  // //Print the elements of the list:
  // myList.print();
  //
  // // Find the middle element of the LinkedList:
  // cout<<" The middle element of the list is:  "<<myList.find_middle_v1()<<endl;
  //
  // // Reverse the LinkedList:
  // myList.reverse_v1();
  //
  // cout<<" After reversal: "<<endl;
  // // Print the reversed linked list:
  // myList.print();
  //
  // // Rotate the elements of the list about a target:
  // myList.rotate(7);
  //
  // // Print the rotated list:
  // cout<<" After rotation: "<<endl;
  // myList.print();

  return 0;

}


// g++ -Wall -std=c++11 -o testLL driver_LL.cpp LinkedList.cpp
