#include <iostream>

using namespace std;

class A{
public:
  virtual void haha();
};


class B: public A{
public:
  virtual void hehe() = 0;
};

class C: public B{
public:
  void haha(){cout<<"haha"<<endl;}
  void hehe(){cout<<"hehe"<<endl;}
};


void A::haha(){cout<<"as;dlfkj"<<endl;}

int main(){
  C obj;
  obj.haha();
  obj.hehe();
  A obj1;
  obj1.haha();
}
