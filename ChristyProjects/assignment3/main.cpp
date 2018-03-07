#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class myClass{
  vector<string> haha;

public:
  myClass(){}
  void addToVector(string line);
};

void myClass::addToVector(string line){
  haha.push_back(line);
}


void myLines(){
  myClass foo;
  string line;
  ifstream myFile("example.txt");
  if(myFile.is_open()){
    while(getline(myFile, line)){
      foo.addToVector(line);
    }
  }
  else cout<<"Unable to open file"<<endl;
  myFile.close();
}



int main(){
  myLines();
}
