#include <iostream>
//avoid multiple includes

using namespace std;

template <template T> class TemplateStack{
public:
  TemplateStack(); //constructor
  TemplateStack(int maxSize); //overloaded constructor
  ~TemplateStack(); //deconstructor

  void push(char def);
  char pop(); 
  char peek(); //aka top

  bool isFull();
  bool isEmpty();

  //should be private? can be, idk if it matters
  int size;
  int top;

  char *myArray; //memory address for 'dynamic' size

};
