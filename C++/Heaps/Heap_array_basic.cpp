/*
 * Heap_array_basic.cpp
 *
 *  Created on: Sep 16, 2017
 *      Author: savio
 */

#include <iostream>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string>
#include <ctime>

using namespace std;

// A class to implement a max heap using a dynamic array: The entries in the heap structure are integers:
// TO DO: Implement a templated class so that other data types can be used as entries in the heap:
class Heap {

private:

	// Expected size of the heap:
	static const int INITIAL_SIZE = 10;

	// Array to store the heap entries:
	int* heapArray;

	// Current number of entries in the heap:
	int numEntries;

	// Current index of the array:
	int currIndex;

public:
	// 1. Constructor:
	Heap(){
		 heapArray = new int[INITIAL_SIZE];
		 numEntries =0;
		 currIndex =-1;
	}

	// 2. Parameterized constructor:
	Heap(int* inputArray, int length){

		heapArray = new int[INITIAL_SIZE];
		numEntries =0;
		currIndex =-1;

		for (int i=0;i<length;i++){

			heapArray[i]= inputArray[i];
			currIndex++;
		}

	}

	// 3. Using the default destructor of the class itself: ---

	// 4. Method to print the entries in the heap:
	void print(){

		for (int i=0;i<=currIndex;i++){
			cout<<heapArray[i]<<",";
		}

		cout<<endl<<endl;
	}



	// 5. Method to swap entries at two given indices in the array:
	void swap(int index_1 , int index_2){
		 int temp = heapArray[index_1];
		 heapArray[index_1] = heapArray[index_2];
		 heapArray[index_2] = temp;
	}

	// 6. Method to bubble up the last entry in the heap array (Reheapification upwards):
	bool bubble_up(int bubbleIndex){

		// Trivial case: If the entry is already at the root
		if (bubbleIndex ==0){

			return true;
		}


		// Recursive case:
		if (heapArray[bubbleIndex] > heapArray[(int) floor((bubbleIndex- 1)/2)]){

			swap(bubbleIndex , (int) floor((bubbleIndex-1)/2) );

			// Recursively call the bubble up function:
			bubble_up((int) floor((bubbleIndex-1)/2));

		}

		else {
			return true;
		}

	}


	// 7. Method to bubble down the first entry in the heap (Reheapification downwards): Element needs to
	// be swapped with the larger of the two children:
	bool bubble_down(int bubbleIndex){

		// Trivial case: If the entry is already at the leaf nodes
		if (currIndex < 2*bubbleIndex + 1){
			return true;
		}

		else {

			// Case 1: Bubble Index is smaller than its children:
			if (heapArray[bubbleIndex] < heapArray[2*bubbleIndex+1] && heapArray[bubbleIndex] < heapArray[2*bubbleIndex+1] ){

				swap(bubbleIndex, 2*bubbleIndex+1);

				bubble_down(2*bubbleIndex+1);
			}

			if (heapArray[bubbleIndex] < heapArray[2*bubbleIndex+2] && heapArray[bubbleIndex] < heapArray[2*bubbleIndex+2]){

				swap (bubbleIndex, 2*bubbleIndex+2);

				bubble_down(2*bubbleIndex+2);
			}

			return true;
		}
	}

	// 8. Method to add an entry to the heap:
	void add_entry(int entry){

		// First add the entry one after the last index in the heap:
		heapArray[++currIndex] = entry;

		// Now bubble up the last entry in the heap Array:
		bubble_up(currIndex);


	}

	// 9. Method to remove the first  entry from the heap: First remove the head node (first index) entry from
	// the heap. Then replace the first element with the last element. Then bubble down the first
	// element until the heap structure is restored:
	int remove_entry(){

		int res =heapArray[0];

		heapArray[0] = heapArray[currIndex--];

		bubble_down(0);

		return res;
	}


	// 10. Function to construct a heap from a non-heap array:
	void Heapify(){

		for (int i = currIndex; i>=0;i--){
			bubble_down(i);
		}
	}
};




// Main function of the Executable:

int main(int argc, char **argv) {

	// Create an object of a a heap:
	Heap* firstHeap = new Heap();

	// Test out the add entry function:

	// Ask the user for values to enter:
	cout<<" Testing the insert method of the Heap Class ..."<<endl<<endl;
	cout<<" Please input the entries of the Heap . Press 'q' to quit"<<endl;

	string userInput;

	bool stopLoop = false;

	while (!stopLoop){


	getline(cin,userInput);

	try {

		int userNumInput = stoi(userInput);
		firstHeap->add_entry(userNumInput);
	}
	catch (const std::invalid_argument& ia) {


		if (userInput[0] == 'q' || userInput[0]=='Q'){
		stopLoop =true;
	}
	else{
			std::cerr << "Invalid argument: " << ia.what() << '\n';
	}

}

	}


		cout<<" The entries of the heap after insertion are: "<<endl;
		firstHeap->print();

		// Test out the remove entry function:
		int first = firstHeap->remove_entry();

		cout<<" Testing out the Remove method of the Heap Class  for a Priority Queue:"<<endl<<endl;

		cout<<" The First entry removed from the heap is: "<< first<<endl;

		cout<<" The entries in the heap after removing the first entry are"<<endl;
		firstHeap->print();



	// Create a random int array:

	cout<<" Testing out the Heapify method of the Heap class ..."<<endl<<endl;

	int inputArray[11];

	for (int i=0;i<10;i++){
		inputArray[i] = rand() %100 +1;
	}

	//int inputArray[8] = {3,1,4,5,9,2,7,8};

	int length = sizeof(inputArray)/sizeof(inputArray[0]);


	// Second heap: To test the heapify function:
	Heap* secondHeap = new Heap(inputArray, length);


	cout<<" These are elements of a random array of 10 integers between 1 and 100"<<endl;
	secondHeap->print();

	secondHeap->Heapify();

	cout<<" These are the elements of the array after the Heapify operation:"<<endl;
	secondHeap->print();


	return 0;

}
