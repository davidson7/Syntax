#include <iostream>
#include <fstream>
#include <sstream>
#include "TemplateStack.cpp"

using namespace std;

int main(){

  /*read each char
  if open bracket add to stack
  if closed bracket, check if it matches .top
  if not give line and error, quit exe
  if match, .pop and move on

  at end of file, check if stack is empty
  if not, give error and quit exe

  */

//file io
ifstream inStream;
cout<<"What is the path of the file?"<< endl;
string filepath;
cin>>filepath;
inStream.open(filepath.c_str());

//check if file can be opened
if(inStream.fail()){
  cout << "Opening input file failed. Make sure you entered the path correctly\n";
  exit(1);
}

//create stack
TemplateStack<char> stack(100);

//read every char for brackets
char ch;
fstream fin(filepath, fstream::in);
while(fin>>noskipws>>ch){


//if isFull - automatically allocate more room
if(stack.isFull()){
  cout<<"it's full"<<endl;
  exit(0);

}

//if open bracket, push to stack
if(ch=='{'||ch=='['||ch=='('){
  stack.push(ch);
}

//if close bracket, check stack
if(ch=='}'||ch==']'||ch==')'){
//if isEmpty - throw line error
  if(stack.isEmpty()){
    cout<<"Unexpected closing bracket"<<endl;

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
    cout<<"Non matching deliminator"<<endl;
  }
}

}


return 0;
};
