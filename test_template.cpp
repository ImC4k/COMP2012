#include <iostream>
using namespace std;

template <typename T>
class A{
  T data;
public:
  A(T data): data(data){}
  void set(T data){ this->data = data;}
  void print() const{ cout<<"data is "<<data<<endl;}
};

int main(){
  void* ptr;

  cout<<"What do you want to store? 1 for int, 2 for char, 0 for bool";
  int in;
  cin>>in;

  switch(in){
    case 1: ptr = new A<int>(0); break;
    case 2: ptr = new A<char>(' '); break;
    default: ptr = new A<bool>(true); break;
  }
  ((A<int>*)ptr)->print();
  delete ptr;
}
