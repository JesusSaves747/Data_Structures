/*
 * Stack.h
 *
 *  Created on: Sep 12, 2017
 *      Author: savio
 */

#ifndef STACK_H_
#define STACK_H_

#include "Node.h"

using namespace std;

namespace sav_sep {

template <class Item>
class Stack {

private:
	Node<Item>* headPtr;
	size_t numNodes;

public:

	// Initializing the stack: All we need is the pointer to the head node in a linked list:
	Stack(Node<Item>* headPtr = NULL ,size_t numNodes = 0) : headPtr(headPtr) , numNodes(numNodes){};

	// Destructor:
	virtual ~Stack();

	// Declare and define copy constructor and assignment operator:


	// Push function:
	// Pre-condition:
	// Post-condition:
	bool push(const Item& entry); // newNode passed by reference to account for size

	// Pop function:
	// Pre-
	// Post -
	Item pop();  // Returns the data value of the node that was popped

	// Get number of nodes in the stack:
	size_t getNum(){ return numNodes;}

	// Print the nodes values in the stack:
	void print();

	// Function to check whether the stack is empty:
	bool is_empty(){
		return (numNodes==0);
	}




};



} /* namespace sav_sep */

#include "Stack.template"

#endif /* STACK_H_ */
