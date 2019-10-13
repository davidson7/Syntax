#include <iostream>
#include <fstream>
#include <sstream>
#include "TemplateStack.cpp"

using namespace std;

int main{

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



//read every char for brackets
if('{'||'['||'('){

}
//if isFull - automatically allocate more room
if(){

}

//if isEmpty - throw line error
if(){


}





};
