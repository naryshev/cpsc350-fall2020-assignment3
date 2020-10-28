#include "GenStack.h"
#include <iostream>
using namespace std;

bool areParanthesisBalanced(string expr){

        GenStack<char> s;
        char x;

        // Traversing the Expression
        for (int i = 0; i < expr.length(); i++) {
                if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
                        // Push the element in the stack
                        s.push(expr[i]);
                        continue;
                }

                // IF current current character is not opening bracket, then it must be closing.
                // So stack cannot be empty at this point.
                if (s.isEmpty()){
                        return false;
                }
                switch (expr[i]) {
                case ')':
                        // Store the top element in a
                        x = s.peek();
                        s.pop();
                        if (x == '{' || x == '['){
                                return false;
                        }
                        break;

                case '}':
                        // Store the top element in b
                        x = s.peek();
                        s.pop();
                        if (x == '(' || x == '[')
                                return false;
                        break;

                case ']':

                        // Store the top element in c
                        x = s.peek();
                        s.pop();
                        if (x == '(' || x == '{')
                                return false;
                        break;
                }
        }

        // Check Empty Stack
        return (s.isEmpty());
}
int main(int argc, char  **argv) {

        string delims = "{[()]}";

        // Function call
      	if (areParanthesisBalanced(delims))
      		  cout << "Balanced";
      	else
      		  cout << "Not Balanced";

        return 0;
}
