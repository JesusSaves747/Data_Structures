// Implmenting Heap Data structure in Java: 4th October 2017:

import java.util.Scanner;
import java.util.ArrayList;

// Rules/invariants about a Heap Structure: Implemented using an array:
// 1. If a node has index 'i' , then its left child is '2i + 1' and right child is '2i+2'
// 2. If a node has index 'i', then the index of its parent is

// Equal keys not allowed in this heap:

// Create a class for the Heap Data structure:
class Heap {

private ArrayList<Double> heapArray;
private int curr_index;


public Heap(){

  heapArray = new ArrayList<Double>(1);
  curr_index = -1;

}

// Methods for the Heap Data structure:

// 0. Method to swap two elements of an array:
public void swap(int ind_1, int ind_2){

  double temp = heapArray[ind_1];
  heapArray[ind_1] = heapArray[ind_2];
  heapArray[ind_2] = temp;

}

// 1. Method to bubble up the last element: Reheapification upwards:
// Recursive function:
public void bubble_up(int bubble_index){

  // Trivial case: Element is at the root or it is less than its parent:
  if (heapArray[bubble_index] < heapArray[(int) (bubble_index-1)/2] || bubble_index ==0)  {
    return;
  }

  // Non-trivial case:
  else {
    swap(bubble_index, (int) (bubble_index-1)/2);
    bubble_up((int) (bubble_index-1)/2);
  }

}

// 2. Method to bubble down the root element: Reheapification downwards:
// Recursive function:
public void bubble_down(int bubble_index){

  // Trivial case: Element is in a leaf node:
  if (curr_index < 2*bubble_index + 1)  {
    return;
  }

  // Non -trivial case: But first check to see if the element at bubble index is already greater than its children:
  else{

      if (heapArray[bubble_index] < heapArray[2*bubble_index +1] || heapArray[bubble_index] < heapArray[2*bubble_index +2] ){

        // Check to see which of the two children are greater:
        if (heapArray[2*bubble_index +1] > heapArray[2*bubble_index +2] ){
          swap(bubble_index, 2*bubble_index + 1);
          bubble_down(2*bubble_index + 1);
        }

        else{
          swap(bubble_index, 2*bubble_index + 2);
          bubble_down(2*bubble_index + 2);
        }

      }

      return;
  }

}


// 3. Method to insert a new key into the heap:
public Boolean insert(double key){

    // Add the new key at the end of the HeapArray:
    heapArray[++curr_index] = key;

    // Bubble up the new key until the heap structure is maintained:
    bubble_up(curr_index);

    return true;  // Put exceptions later on:
}

// 4. Method to remove the root key  from the heap: Like in a Priority Queue:
public double remove_root(){

  // Extract the root element:
  double root = heapArray[0];

  // Shift the last element to the zeroth index and decrement size of heap by 1:
  heapArray[0] = heapArray[curr_index--];

  // Bubble down the zeroth index element until the heap structure is maintained:
  bubble_down(0);

  return root;

}


// 5. Method to heapify an unordered heap:

// 6. Method to print the entries in the heap:
public void print(){

  for (int i=0;i<=curr_index;i++){
    System.out.print(heapArray[i] + ",") ;
  }
    System.out.println(" ");

}

// Main function to test the implementation:
public static void main(String[] args) {

    // Create a new Heap:
    Heap myHeap = new Heap();

    String userEntry;

    // Create a scanner object to get user input:
    Scanner myScan = new Scanner(System.in);

    System.out.println("Please enter the elements/keys of the Heap");

    Boolean stopLoop = false;
    double key;

            while (!stopLoop) {
                userEntry = myScan.nextLine();

                try {

                      key = Double.parseDouble(userEntry);
                      myHeap.insert(key);

                } catch (NumberFormatException e) {

                    if (userEntry.equals("q") || userEntry.equals("Q")) {
                        System.out.println("Stopping loop");
                        stopLoop = true;

                    } else {
                        System.out.println("Please enter a valid character");
                    }
                }

            }   // END while loop

      // Check the order of the elments in the heap:
      System.out.println("Elements of the original Heap are: ");
      myHeap.print();

      // Test the removal of an entry in the heap:
      myHeap.remove_root();


      // Now recheck the entries in the heap:
      System.out.println("Elements of the  Heap with root removed are: ");
      myHeap.print();

}




}  // END class Heap:
