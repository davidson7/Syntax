#include <iostream>

using namespace std;

template <class T>
class TemplateStack{
public:
  TemplateStack(); //constructor
  TemplateStack(int maxSize); //overloaded constructor
  ~TemplateStack(); //deconstructor

  void push(T const&);
  T pop();
  T peek(); //aka top

  bool isFull();
  bool isEmpty();

  int getSize();

  //should be private? can be, idk if it matters
  int size;
  int top;
private:
  T *myArray; //memory address for 'dynamic' size

};




template <class T>
TemplateStack<T>::TemplateStack()//default constructor
{
//initialize default values, just choose something
myArray= new char[100];
top = -1;
size = 100;
}

template <class T>
TemplateStack<T>::TemplateStack(int maxSize)
{
  myArray= new char[maxSize];
  top = -1;
  size = maxSize;
}

template <class T>
TemplateStack<T>::~TemplateStack()
{
  //who knows? why do i have to deallocate memory
  delete myArray; //todo:check if that works
}

template <class T>
void TemplateStack<T>::push(T const& elem)
{
  //check error/boundary check
  if(top>= size-1){
    //throw exception
  }
  myArray[++top]= elem;
}

template <class T>
T TemplateStack<T>::pop()
{
  //error check if empty etc
  if(top==-1){
    //throw exception and exit gracefully . . .
  }
  return myArray[top--];
}

template <class T>
T TemplateStack<T>::peek()
{
  //error check
  if(top==-1){
    //throw exception
  }
  return myArray[top];
}

template <class T>
bool TemplateStack<T>::isFull()
{
  return (top>= size-1);
}

template <class T>
bool TemplateStack<T>::isEmpty()
{
  return (top==-1);
}

template <class T>
int TemplateStack<T>::getSize()
{
  return size;
}
