#include <iostream>
#include <fstream>
#include <stack>
using namespace std;


/*
  NOTE: Created by Calvin, summer year 2
  this is just an experiment to allow input when starting a program,
  this program reverse order of a file, each each character is added by 3 when encoding

  this is by no means a crypto-system, but can act as a locking mechanism

  NOTE: HOW TO RUN
  run this program by typing
  ./manipulator [filename with extension] [encode / decode (this word will be concatenated before filetype)]

  eg: to encode haha.txt
      type ./manipulator haha.txt encode
      to generate haha_encode.txt

      to decode haha_encode.txt
      type ./manipulator haha_encode.txt decode
      to generate haha_encode_decode.txt
*/


bool manipulateFile(char* fileName, char* function){
  ifstream text;
  text.open(fileName);
  if(!text.good()){
    cerr<<"unable to operate"<<endl;
    return false;
  }

  stack<char> text_stack;
  char val;

  while(!text.eof()){
    text.get(val);
    text_stack.push(val);
  }
  text.close();

  ofstream output;
  string outFileName, fileNameString = "", type = "";
  bool typeFlag = false;
  for(int i = 0; i < strlen(fileName); i++){
    if(fileName[i] == '.'){
      typeFlag = true;
      continue;
    }
    if(!typeFlag)
      fileNameString += fileName[i];
    else
      type += fileName[i];
  }

  if(!strcmp(function,"encode"))
    outFileName = fileNameString + "_" + "encode." + type;
  else
    outFileName = fileNameString + "_" + "decode." + type;
  output.open(outFileName);
  text_stack.pop();
  while(!text_stack.empty()){
    output<<static_cast<char>((text_stack.top() + ((!strcmp(function, "encode"))? 3: -3)));
    text_stack.pop();
  }
  output.close();
  return true;
}

int main(int argc, char* argv[]){
  if(argc < 3 ){
    cerr<<"Invalid, must have 2 inputs"<<endl;
    return -1;
  }
  if(!manipulateFile(argv[1], argv[2])){
    cerr<<"Program quit unexpectedly"<<endl;
    return -1;
  }
  return 0;
}
