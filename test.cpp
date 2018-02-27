#include <iostream>
// #include <string>

using namespace std;

class Base{
  int* pa;
public:
  Base():pa(new int){cout<<"Base constructor called"<<endl;}
  ~Base(){delete pa; cout<<"Base destructor called"<<endl;}
};

class Derived : public Base{
  int a;
public:
  Derived(): Base(), a(3){cout<<"Derived constructor called"<<endl;}
  ~Derived(){cout<<"Derived destructor called"<<endl;}
};
int main(){
  Derived* obj = new Derived();
  // Base* obj = new Derived();
  // Base* obj = new Base();
  delete obj;
  cout<<"done"<<endl;
  return 0;
}
