// This is created by Calvin

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void readLines(vector<string>& v, string fileName){
  ifstream myFile;
  myFile.open(fileName);
  while(!myFile.eof()){
    string line;
    getline(myFile, line);
    v.push_back(line);
  }
  if(v.size() == 0) cout<<"Error when reading file"<<endl; // BUG
  myFile.close();
}

void printLines(std::vector<string>& v, int num_lines = 5){
  for(int i = 0; i < num_lines; i++){
    cout<<v[i]<<endl;
  }
}

// index 1 should access vector[0] content
string getVectorLine(std::vector<string>& v, int index){
  if(index < 1 || index > v.size()){
    cout<<"Invalid index!"<<endl;
    cerr<<"Invalid index access"<<endl<<"index out of bound"<<endl;
    return "";
  }
  return v[index-1];
}

//copy contents from tar (target) to des (destination) in reverse order
void copyVectorReverse(std::vector<string>& des, std::vector<string>& tar){
  des.clear();
  for(int i = tar.size()-1; i >= 0; i--){
    des.push_back(tar[i]);
  }
}

int main(){
  vector<string> vector_str;
  readLines(vector_str, "haha.txt");
  printLines(vector_str);

  cout<<"enter index that you want to access in vector"<<endl;
  int index;
  cin>>index;
  string line = getVectorLine(vector_str, index);
  cout<<line<<endl;

  std::vector<string> copyReverse;
  copyVectorReverse(copyReverse, vector_str);
  cout<<"size of copyVectorReverse is "<<copyReverse.size()<<endl;
  printLines(copyReverse);
  return 0;
}
