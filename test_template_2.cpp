#include <iostream>
using namespace std;

template <typename T = int>
class A{
  T data;
public:
  A(T d): data(d){}
  void print()const{cout<<"data is "<<data<<endl;}
  void set(T data){this->data = data;}
};

int main(){
  A<> obj(3);
  obj.print();
  return 0;
}
