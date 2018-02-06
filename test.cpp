#include <iostream>

using namespace std;

class Test{
  int* arr;
public:
  Test(){
    arr = new int[3];
  }
  int* getArray(){
    return arr;
  }
  int getArraySize(){
    return sizeof(arr);
  }
};


int main(){
  Test* obj = new Test();
  cout<<obj->getArraySize()<<endl;
  
}
