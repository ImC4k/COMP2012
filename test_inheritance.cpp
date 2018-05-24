#include <iostream>
using namespace std;

class A{
public:
  int publicMem;
protected:
  int protectedMem;
private:
  int privateMem;

public:
  A(int publicMem = 3, int protectedMem = 4, int privateMem = 5): publicMem(publicMem), protectedMem(protectedMem), privateMem(privateMem){}

  virtual void print(){
    cout<<"publicMem: "<<publicMem<<endl;
    cout<<"protectedMem: "<<protectedMem<<endl;
    cout<<"privateMem: "<<privateMem<<endl;
  }
};

class B: public A{
public:
  void print(){
    cout<<"publicMem: "<<publicMem<<endl;
    cout<<"protectedMem: "<<protectedMem<<endl;
    // cout<<"privateMem: "<<privateMem<<endl; // BUG: cannot access private data member
  }
};

class C: protected A{
public:
  void print(){
    cout<<"publicMem: "<<publicMem<<endl;
    cout<<"protectedMem: "<<protectedMem<<endl;
    // cout<<"privateMem: "<<privateMem<<endl; // BUG: cannot access private data member
  }
};

class D: private A{
public:
  int num;
  D(int num = 1): num(num), A(){}

  void print(){
    cout<<"publicMem: "<<publicMem<<endl;
    cout<<"protectedMem: "<<protectedMem<<endl;
    // cout<<"privateMem: "<<privateMem<<endl;
  }
};

class E: public D{
public:
  void print(){
    // cout<<"publicMem: "<<publicMem<<endl;
    // cout<<"protectedMem: "<<protectedMem<<endl;
    cout<<"num: "<<num<<endl;
    // cout<<"privateMem: "<<privateMem<<endl;
  }
};

int main(){
  D* obj = new E();
  obj->print();
}
