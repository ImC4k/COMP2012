#include <iostream>
using namespace std;

class A{
public:
  int num;
  void print() const{cout<<"num is "<<num<<endl;}
  A(int n): num(n){print();}

};

class B: public A{
public:
  int num;
  void print() const{cout<<"num is "<<num<<endl;}
  B(int a, int b): A(a), num(b){print();}

};

int main(){
  B obj(1, 2);
}
