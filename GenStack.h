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
      GenStack(int maxSize);//overload
      ~GenStack();//destructor

      void push(T data);
      T pop();
      T peek();

      bool isFull();
      bool isEmpty();
      int size();
      void resize(T* GenStack, int newSize);
      void printStack();

};

template <typename T>
GenStack<T>::GenStack(){
  mStack = new T[256];
  mSize = 256;
  top = -1;
}

template <typename T>
GenStack<T>::GenStack(int size){
  mStack = new T [size];
  mSize = size;
  top = -1;
}

template <typename T>
GenStack<T>::~GenStack(){
  delete mStack;
}

template <typename T>
void GenStack<T>::push(T data){
    if(isFull()){
      resize(mStack, mSize * 2);
    }
    mStack[++top] = data;

}

template <typename T>
T GenStack<T>::pop(){
    if (isEmpty()){
      //throw StackEmpty
      cout << "Stack is empty"<<endl;
    }
      return mStack[top--];

}
template <typename T>
T GenStack<T>::peek(){
    return mStack[top];
}
template <typename T>
bool GenStack<T>::isFull(){
    return (top == mSize-1);
}
template <typename T>
bool GenStack<T>::isEmpty(){
    return (top == -1);
}
template <typename T>
int GenStack<T>::size(){
    return top + 1;

}
template <typename T>
void GenStack<T>::resize(T* stack, int newSize){

    T* stackCopy = new T[newSize];
    stackCopy = mStack;
    mStack = stackCopy;
    mSize = newSize;

}
// template <typename T>
// void GenStack<T>::printStack(){
//     if(!mStack.empty()){
//         int top = mStack.peek();
//         s.pop();
//         cout << top << endl;
//     }
// }
