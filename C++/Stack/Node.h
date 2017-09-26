/*
 * Node.h
 *
 *  Created on: Sep 12, 2017
 *      Author: savio
 */

#ifndef NODE_H_
#define NODE_H_


#include<cstdlib>
#include<iostream>

namespace sav_sep {

template <class Item>
class Node {

private:
	Item data;
	Node* link;

public:
	Node(double
			data = 0.0 , Node* link = NULL) : data(data) , link(link){}
	virtual ~Node();

	// Need to define a copy constructor and an assignment operator:

	// Declare function to get data:
	Item getData();

	// Declare a function to set data:
	void setData(const Item& dataValue){
		data = dataValue;
	}

	// Declare function to get link:
	Node<Item>* getLink();

	// Declare function to set link:
	void setLink(Node* newLink){
		link = newLink;
	}


};


} /* namespace sav_sep */


#include "Node.template"

#endif /* NODE_H_ */
