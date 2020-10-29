//Assignment 3 - Syntax Checker [Main.cpp]
//  Takes in file from command line parsing for delimitors such as {[()]} then checking their balance
//  If unbalanced, program exits and notifies user with error message with line number.
//  Daniel Naryshev
#include "GenStack.h"
#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char  **argv) {
    GenStack<char> s;
    ifstream inFile(argv[1]);
    int lineNumber = 0, errorLine = 0;
    string line = "", userPath;
    char x;

    // Confirm inFile exists, if not exit
    if(!inFile){
        cout << "File not found ... Please try again" <<endl;
        exit(0);
    }

    while(getline(inFile, line)){
       ++lineNumber;
        for (int i = 0; i < line.length(); ++i) {
          if (line[i] == '(' || line[i] == '[' || line[i] == '{'){
            // Push the element in the stack if it is an opening delimitor
            s.push(line[i]);
            continue;
          }

          switch (line[i]) {
          // switch on line[i] checking for closing delimitor, if matching check stack
          case ')':
              //fetch item at top of stack (delimitor before the one we are checking)
              x = s.peek();

              if (x == '('){
                  // if matching opening delimitor found pop stack and continue
                  s.pop();
                  continue;
              }	else if (x == '{'){
                  // else if mismatching delimitor throw errors
                  cout << "Line" << lineNumber << ":  expected '}' and found ')'" << endl;
                  return false;
              } else if( x == '[' ){
                  cout << "Line" << lineNumber << ": expected ']' and found  ')'" << endl;
                  return false;
              }
            break;
          case '}':
              x = s.peek();
              if (x == '{'){
                  s.pop();
                  continue;
              }	else if (x == '('){
                  cout << "Line" << lineNumber << ": expected ')' and found  '}'  " << endl;
                  return false;
              } else if( x == '[' ){
                  cout << "Line " << lineNumber << ": expected ']' and found  '}' " << endl;
                  return false;
              }
            break;
          case ']':
              x = s.peek();
              if (x == '['){
                  s.pop();
                  continue;
              }	else if (x == '{'){
                  cout << "Line" << lineNumber << ": '}' expected and found ']'" << endl;
                  return false;
              } else if( x == '(' ){
                  cout << "Line" << lineNumber << ": ')' expected and found ']'" << endl;
                  return false;
              }
            break;
        }
      }
    }
    // if stack is empty at this point then syntax is error free
    if (s.isEmpty()){
        cout << "All good..."<< endl;
    } else {
        cout << "Errors Found" << endl;

    }
    return 0;
}
