#include<iostream>
using namespace std;

class Base{
public:
  virtual void print(){
    cout<<"haha"<<endl;
  }
};

class Derived: public Base{
protected:
  void print() override{
    cout<<"derived hehe"<<endl;
  }
};

class Subclass: public Derived{
public:
  void print() override{
    Derived::print();
    cout<<"subclass"<<endl;
  }
};

int main(){
  Base* obj = new Subclass();
  obj->print();
  delete obj;

  return 0;
}
