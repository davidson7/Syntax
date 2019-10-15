#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "TemplateStack.h"

using namespace std;

int main(int argc, char** argv){
  bool runAgain=true;

  /*read each char
  if open bracket add to stack
  if closed bracket, check if it matches .top
  if not give line and error, quit exe
  if match, .pop and move on

  at end of file, check if stack is empty
  if not, give error and quit exe

  ask for second file
  */

  //TODO: runAgain is having problems

//use arg as filepath
string filepath="";
if(argc>=2){
  filepath =argv[1];
}

//for mutliple files
while(runAgain==true){
//if no arg, file io
if(argc<2||runAgain==true){
cout<<"What is the path of the file?"<< endl;
cin>>filepath;
}

fstream fin(filepath, fstream::in);

//check if file can be opened
if(fin.fail()){
  cout << "Opening input file failed. Make sure you entered the path correctly\n";
  exit(1);
}

//create stack -- limit 50 open brackets
TemplateStack<char> stack(50);

//read every line, then every char for brackets
string line;
int linecount=0;

//count lines
while(std::getline(fin,line)){
  linecount++;

for(char& ch : line){


//if isFull - automatically allocate more room
if(stack.isFull()){
  cout<<"Stack is full, allocating more space"<<endl;
  TemplateStack<char> stack2(stack.getSize()*2);
  for(int i =0;i<stack.getSize();++i){
    stack2.push(stack.pop());
  }
  stack = stack2;

}

//if open bracket, push to stack
if(ch=='{'||ch=='['||ch=='('){
  stack.push(ch);
}

//if close bracket, check stack
if(ch=='}'||ch==']'||ch==')'){
//if isEmpty - throw line error
  if(stack.isEmpty()){
    cout<<"Line "<<linecount<<": Unexpected closing bracket"<<endl;
    exit(0);
  }
  //else compare to .top bracket, if match, pop top
  if(ch=='}'&& stack.peek()=='{'){
    stack.pop();
  }else if(ch==']'&& stack.peek()=='['){
    stack.pop();
  }else if(ch==')'&& stack.peek()=='('){
    stack.pop();
  }
  //if no match throw line error
  else{
    cout<<"Line "<<linecount<<": Non matching deliminator. ";
    if(stack.peek() == '{'){
      cout<<"Expected "<<'}'<<" found "<< ch<<endl;
    }else if(stack.peek() == '('){
      cout<<"Expected "<<')'<<" found "<< ch<<endl;
    }else if(stack.peek() == '['){
      cout<<"Expected "<<']'<<" found "<< ch<<endl;
    }
    exit(0);
  }
}

}
}
//last check for open brackets, check .isEmpty
if(!stack.isEmpty()){
  cout<<"Reached end of file. Missing: ";
  if(stack.peek() == '{'){
    cout<<'}'<<endl;
  }else if(stack.peek() == '('){
    cout<<')'<<endl;
  }else if(stack.peek() == '['){
    cout<<']'<<endl;
  }
  exit(0);
}

//error free, ask for another file
char response;
cout<<"No errors, try another file? (y/n)"<<endl;
cin>>response;

if(response=='y'||response =='Y'){
  runAgain=true;
}else if(response=='n'||response=='N'){
  runAgain=false;
  break;
}else{
  cout <<"Invalid input. Closing program."<<endl;
  runAgain=false;
  break;

}

}
return 0;
};
