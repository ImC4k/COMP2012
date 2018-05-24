#include <iostream>
using namespace std;

class A{
public:
  static int count;
  static void print(){cout<<"A::count: "<<count<<endl;};
  A(){count++; print();}
  ~A(){count--; print();}
};

class B: public A{
public:
  static int count;
  static void print(){cout<<"B::count: "<<count<<endl;}
  B(){count++; print();}
  ~B(){count--; print();}
};

int A::count = 0;
int B::count = 10;

int main(){
  A obj;
  B obj2;
  return 0;
}
