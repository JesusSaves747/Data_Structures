// Implementation file to test out the stack class:
#include "Stack.h"
#include <iostream>
#include <string>

using namespace std;
using namespace sav_sep;

int main(int argc, char const *argv[]) {

        // Test App #1: Reverse a string:
        // Get the user's name as an input and then reverse the name using a stack:
        Stack<char>* nameStack = new Stack<char>; // Stack of characters:

        string userName;

        cout<<" App #1 : Reverse the String entered by the user"<<endl;

        cout<<" Enter your name dear user: "<<endl;

        getline(cin, userName);


        for (int i=0; i<userName.length(); i++) {

                nameStack->push(userName[i]);
        }

        // Assign the characters to the Reverse string:
        for (int j=0; j<userName.length(); j++) {
                userName[j] = nameStack->pop();
        }

        cout<<" Your name with the characters reversed is: "<<userName<<endl;



        cout<<" ------------------------------------------------ "<<endl;
        // Test App #2: Check if an expression is balanced:
        // Get the user's input expression:
        Stack<char>* expStack = new Stack<char>; // Stack of characters:

        bool balanced = true;
        string expString;

        cout<<" App #2: Check whether the mathematical expression entered by the user is parenthesis balanced"<<endl;
        cout<<" Enter the mathematical expression with parenthesis : "<<endl;

        getline(cin, expString);

        for (int i=0; i<expString.length(); i++) {

                if (expString[i] == '(' || expString[i] == '[' || expString[i] == '{') {
                        expStack->push(expString[i]);
                }


                // Round parenthesis:
                if (expString[i] == ')') {
                        if (expStack->pop() != '(') {
                                balanced = false;
                                break;
                        }
                }

                // Square parenthesis:
                if (expString[i] == ']') {
                        if (expStack->pop() != '[') {
                                balanced = false;
                                break;
                        }
                }

                // Curly parenthesis:
                if (expString[i] == '}') {
                        if (expStack->pop() != '{') {
                                balanced = false;
                                break;
                        }
                }



              }   // END for


        if (balanced && expStack->is_empty())
        {

                cout<<" Expression is BALANCED!!!"<<endl;

        }

        else
        {
                cout<<" Expression is not balanced!!!"<<endl;
        }





return 0;
}
