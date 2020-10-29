//Template class GenStack
// Operates on FILO, has functions, push, pop, peek, isFull, isEmpty, size(), resize,
// Daniel Naryshev
#include <iostream>
using namespace std;
template <typename T>
class GenStack{

  private:
      T* mStack;
      int top;
      int mSize;


  public:
      GenStack(); //default
      GenStack(int size);//overloaded
      ~GenStack();//destructor

      void push(T data); //
      T pop();
      T peek();

      bool isFull();
      bool isEmpty();
      int size();
      void resize(T* GenStack, int newSize);
};
//Default Stack of type T, default array based stack of size 256
template <typename T>
GenStack<T>::GenStack(){
  mStack = new T[256];
  mSize = 256;
  top = -1;
}
//Overloaded Stack of type T and size S
template <typename T>
GenStack<T>::GenStack(int s){
  mStack = new T [s];
  mSize = s;
  top = -1;
}
// Deletes the stack
template <typename T>
GenStack<T>::~GenStack(){
  delete mStack;
}
//Checks if stack is full, if full it doubles the stack's size and adds data to the top
//preincrement top because it is defaulted to -1
template <typename T>
void GenStack<T>::push(T data){
    if(isFull()){
      resize(mStack, mSize * 2);
    }
    mStack[++top] = data;

}
//Checks if stack is empty before returning the top element and removing
//postdecrement top to remove after returning
template <typename T>
T GenStack<T>::pop(){
    if (isEmpty()){
      cout << "Stack is empty"<<endl;
    }
    return mStack[top--];
}
//Return the top element of stack
template <typename T>
T GenStack<T>::peek(){
    return mStack[top];
}
//check if the stack is full by checking if top is the same as the size of the stack
template <typename T>
bool GenStack<T>::isFull(){
    //mSize-1 because arrays start at 0
    return (top == mSize-1);
}
template <typename T>

bool GenStack<T>::isEmpty(){
    return (top == -1);
}
//Return size of the array
template <typename T>
int GenStack<T>::size(){
    return top + 1;

}
////Resize method incase the stack fills up.
// Creates a new stackCopy of size newSize
// Copy's full stack to stackCopy
// Update the stack size
// Update new stack with old stack data
template <typename T>
void GenStack<T>::resize(T* stack, int newSize){
    T* stackCopy = new T[newSize];
    stackCopy = mStack;
    mSize = newSize;
    mStack = stackCopy;
}
