#include <iostream>

using namespace std;

// An array is always passed by reference:
int* test_func(int input_arr[]){

  int* func_array = new int[5];

  cout<<" Check:"<<endl;

  for (int i =0;i<5;i++){
    cout<<func_array[i] <<endl;
  }

  input_arr[2] =33;

  return func_array;

}

int main(int argc, char const *argv[]) {

  int* test = new int[5];

  int test2[5] = {0,0,0,0,0};


  int* test3 = test_func(test);

  for (int i =0;i<5;i++){
    cout<<++test[i] <<endl;
  }

  for (int i =0;i<5;i++){
    cout<<++test3[i] <<endl;
  }


  return 0;
}
