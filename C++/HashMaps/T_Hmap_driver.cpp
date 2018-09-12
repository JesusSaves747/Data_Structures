#include "Templated_Hashmap.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;

int main(int argc, char const *argv[]) {

  T_HMap<string, int>* myMap = new T_HMap<string, int>();

  int numElem;
  cout<<" Enter the number of elements: \n";
  cin>>numElem;

  cout<<" Enter the Key-Value pairs separated by a space. \n";

  string value;
  int key;

  int k=0;

  // Loop to insert elements:
  while (k<numElem){

    cin>>key;
    cin>>value;

    // Insert the element:
    if (!myMap->insert(value, key)){
      cout<<" Sorry unable to insert element. Check code! \n";
      break;
    }

    k++;

  }



  // Retieve element:
  cout<<" Enter the key of the element to be retrieved \n";

  int findKey;
  cin>>findKey;

  if (!myMap->retrieve(findKey, value)){
    cout<<" Sorry, unable to find the element! \n";
  }
  else{
    cout<<" The value for key:  "<<findKey<<" is:  "<<value<<"\n";
  }


  return 0;
}
