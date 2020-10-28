//Daniel Naryshev
//dnaryshev@chapman.edu
//2327209
#include "GenStack.h"
#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char  **argv) {
        GenStack<char> s;
        ifstream inFile(argv[1]);
        int lineNumber = 0;
        int errorLine = 0;
        string delims = "", line;
        string userPath;
        char x;


        //inFile.open(argv[1]);
        if(!inFile){
            cout << "File not found ... Please enter again" <<endl;
            exit(0);
        }

        while(inFile >> line){
          lineNumber++;
            for (int i = 0; i < line.length(); ++i) {
                if ((line[i] == '(') || (line[i] == '{') || (line[i] == '[') ){
                  s.push(line[i]);
                } else if((s.peek() == '[') && (line[i] == ']')){
                    s.pop();
                }else if((s.peek() == '{') && (line[i] == '}')){
                    s.pop();
                }else if((s.peek() == '(') && (line[i] == ')')){
                    s.pop();
                 }//else if((s.peek() == '(') && (line[i] == '}')){
                //     cout << "Line" << lineNumber << ": ')' expected and found }" << endl;
                //     exit(0);
                // }else if((s.peek() == '(') && (line[i] == ']')){
                //     cout << "Line" << lineNumber << ": ')' expected and found ]" << endl;
                //     exit(0);
                // }else if((s.peek() == '(') && (line[i] == '}')){
                //     cout << "Line" << lineNumber << ": ')' expected and found }" << endl;
                //     exit(0);
                // }
            }
        }
        if (s.isEmpty()){
            cout << "Balanced"<< endl;
        } else {
            cout << "Not Balanced" << endl;
            //cout << errorLine << endl;

        }
        return 0;
}
