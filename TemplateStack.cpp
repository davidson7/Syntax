#include <iostream>
#include "TemplateStack.h"

using namespace std;

TemplateStack::TemplateStack()//default constructor
{
//initialize default values, just choose something
myArray= new char[100];
top = -1;
size = 100;
}

TemplateStack::TemplateStack(int maxSize)
{
  myArray= new char[maxSize];
  top = -1;
  size = maxSize;
}

TemplateStack::~TemplateStack()
{
  //who knows? why do i have to deallocate memory
  delete myArray; //todo:check if that works
}

void TemplateStack::push(char d)
{
  //check error/boundary check
  if(top>= size-1){
    //throw exception
  }
  myArray[++top]= d;
}

char TemplateStack::pop()
{
  //error check if empty etc
  if(top==-1){
    //throw exception and exit gracefully . . .
  }
  return myArray[top--];
}

char TemplateStack::peek()
{
  //error check
  if(top==-1){
    //throw exception
  }
  return myArray[top];
}

bool TemplateStack::isFull()
{
  return (top>= size-1);
}

bool TemplateStack::isEmpty()
{
  return (top==-1);
}
