#ifndef TEMPLATED_HASHMAP_H
#define TEMPLATED_HASHMAP_H

#include <vector>
#include <cstdlib>

// Templated structure to be used for chaining:
template <class data>
struct H_elem{

  // Data element:
  data H_data;

  // Pointer to the next element:
  H_elem* next;

  // Constructor for the structure:
  H_elem(const data& InData){
    H_data = InData;
    next = NULL;
  }

};

// Created the templated class:
// Template parameters: <data, key>

template <class data, class key>
class T_HMap{

private:

  const size_t MAX_SIZE;
  std::vector<H_elem<data>*> hash_table;



public:

  // // 1. Constructor:
  T_HMap() : MAX_SIZE(100) , hash_table(MAX_SIZE, NULL){};

  // 2. Insert function:
  bool insert(const data& inData, const key& inKey);

  // 3. Retrieve function: TO DO: Overload the index access ('[]') operator:
  bool retrieve(const key& findKey, data& outData);

  // 4. Hash function: Simple hash function:
  size_t hash_func(const key& myKey){
    return (myKey%6  + myKey%7);
  }

};

#include "Templated_Hashmap.cpp"

#endif
