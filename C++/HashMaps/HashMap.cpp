#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

// Create a structure to represent the HashMap Entry:
// Fields: Name, Age, PID:
typedef struct Student{
  string name;
  int age;
  int PID;  // 6 digit number
  Student* next;   // For chain hashing the pointer to the next element

} Student;



// Create a class to implement the HashMap: Main variable is a Vector of students: Vector instead of list since we have
// contiguous memory allocation: Need to check whether this is really helpful
class HashMap{

private:


public:


    int entryCount;
    const size_t TABLE_SIZE = 100;
    vector<Student*> HashTable;

  // 1. Constructor:Ask the user to enter in a few entries:
  HashMap(): entryCount(0) , HashTable(TABLE_SIZE, NULL) {};


  // 2. Destructor:

  // 3. Hash function: Main one:

  // 4. Insert function:
  void insert(string name, int age, int PID){

    // Hash the PID to get the index in the array:
    //size_t index = hash_1(PID); Very simplistic hash function need to imporve this:
    int index = (PID)%6 +(PID)%7;


    // Check to see if there is a collision:
    if (HashTable[index] == NULL){


      // If NO -> // Insert the element at this index:
      HashTable.at(index) = new Student();

      HashTable.at(index)->name = name;
      HashTable.at(index)->age = age;
      HashTable.at(index)->PID = PID;



    }

    else{

      // If YES -> // Move along the chain in a loop to get to the end of the chain:



      Student* currStudent = HashTable.at(index);

      while ( currStudent->next != NULL){
        currStudent = currStudent->next;
      }

      currStudent->next  = new Student();

      currStudent->next->name = name;
      currStudent->next->age = age;
      currStudent->next->PID = PID;


    }


  }  // END insert function:

  // 5. Function to find an entry using the PID:



}; // END class HashMap

int main(int argc, char const *argv[]) {
  // Create an object of the HashMap:
  HashMap* Map1 = new HashMap();


  Map1->insert("Robert", 25, 786543);
  Map1->insert("Amanda" , 23, 987345);

  int test_index = (987345)%6 +(987345)%7;

  cout<<" Test index is:"<<test_index<<endl;

  cout<<" Name at index is: "<<Map1->HashTable[test_index]->name<<endl;

  return 0;
}
