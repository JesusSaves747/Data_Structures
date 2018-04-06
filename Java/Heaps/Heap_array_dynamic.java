// Implmenting Heap Data structure in Java: 4th October 2017: Using an ArrayList instead of a fixed size array:
// Seems like an ArrayList in Java is similar to a Vector in C++(maybe)!

import java.util.Scanner;
import java.util.ArrayList;

// Rules/invariants about a Heap Structure: Implemented using an array:
// 1. If a node has index 'i' , then its left child is '2i + 1' and right child is '2i+2'
// 2. If a node has index 'i', then the index of its parent is

// Equal keys not allowed in this heap:

// Create a class for the Heap Data structure:
class Heap{

private ArrayList<Double> heapArray;
private int curr_index;


public Heap(){

  heapArray = new ArrayList<Double>(0); // Initialize an empty ArrayList
  curr_index = -1;

}

//Parmeterized constructor:
public Heap(ArrayList<Double> inputArray){

  heapArray = inputArray;

  curr_index = inputArray.size() - 1;  // Size is the number of elements but indexing starts at zero:

}
// Methods for the Heap Data structure:

// 0. Method to swap two elements of an array:
public void swap(int ind_1, int ind_2){

  double temp = heapArray.get(ind_1);
  heapArray.set(ind_1 , heapArray.get(ind_2));
  heapArray.set(ind_2 , temp);

}

// 1. Method to bubble up the last element: Reheapification upwards:
// Recursive function:
public void bubble_up(int bubble_index){

  // Trivial case: Element is at the root or it is less than its parent:
  if (heapArray.get(bubble_index) < heapArray.get((int) (bubble_index-1)/2) || bubble_index ==0)  {
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

      if (heapArray.get(bubble_index) < heapArray.get(2*bubble_index +1) || heapArray.get(bubble_index) < heapArray.get(2*bubble_index +2) ){

        // Check to see which of the two children are greater: Swap with the greater child:
        if (heapArray.get(2*bubble_index +1) > heapArray.get(2*bubble_index +2) ){
          swap(bubble_index, 2*bubble_index + 1);

          // Recurse downwards:
          bubble_down(2*bubble_index + 1);
        }

        else{
          swap(bubble_index, 2*bubble_index + 2);

          //Recurse downwards:
          bubble_down(2*bubble_index + 2);
        }

      }

      return;
  }

}


// 3. Method to insert a new key into the heap:
public Boolean insert(double key){

    // Increment the curr_index of the ArrayList
    ++curr_index;

    // Add the new key at the end of the HeapArray:
    heapArray.add(key);

    // Bubble up the new key until the heap structure is maintained:
    bubble_up(curr_index);

    return true;  // Put exceptions later on:
}


// 4. Method to remove the root key  from the heap: Like in a Priority Queue:
public double remove_root(){

  // Extract the root element:
  double root = heapArray.get(0);

  // Shift the last element to the zeroth index and decrement size of heap by 1:
  heapArray.set(0, heapArray.get(curr_index));

  // Remove the last element:
  heapArray.remove(curr_index--);


  // Bubble down the zeroth index element until the heap structure is maintained:
  bubble_down(0);

  return root;

}


// 5. Method to heapify an unordered heap:
public void heapify(){

  for (int j=curr_index;j>0;j--){
    bubble_down(j);
  }
}

// 6. Method to print the entries in the heap:
public void print(){


    System.out.println(heapArray) ;

    //System.out.println(" ");

}

// Main function to test the implementation:
public static void main(String[] args) {


// Part 1: Test the insert and remove methods:
    // Create a new Heap:
    Heap myHeap = new Heap();

    String userEntry;

    // Create a scanner object to get user input:
    Scanner myScan = new Scanner(System.in);

    System.out.println("Please enter the elements/keys of the Heap. Press q and hit Enter to Quit");

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


// Part 2: Test the Heapify function:

// Declare an empty array list:
ArrayList<Double> userList = new ArrayList<Double>(0);



// Allow the user to add multiple doubles to this list: Press "q" to quit
System.out.println("Please enter the elements/keys of the Heap. Press q and hit Enter to Quit");

stopLoop = false;


        while (!stopLoop) {
            userEntry = myScan.nextLine();

            try {

                  key = Double.parseDouble(userEntry);
                  userList.add(key);

            } catch (NumberFormatException e) {

                if (userEntry.equals("q") || userEntry.equals("Q")) {
                    System.out.println("Stopping loop");
                    stopLoop = true;

                } else {
                    System.out.println("Please enter a valid character");
                }
            }

        }   // END while loop

// Print the original array list:
System.out.println("The array you entered in is " + userList);

// Now heapify the Array:
Heap secondHeap = new Heap(userList);

secondHeap.heapify();

// Print the original array list:
System.out.println("The Heapfied list is ");
secondHeap.print();

 } // END Main function


}  // END class Heap:
