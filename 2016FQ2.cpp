#include <iostream>
using namespace std;

class Base{
  int base;
  static int count;
public:
  Base(int b = 30): base(b){
    count++;
    cout<<"Base's Ctor, count = "<<cout<<endl;
  }
  Base(const Base& b): base(b.base){
    count++;
    cout<<"Base's Copy Ctor, count = "<<count<<endl;
  }
  virtual ~Base(){
    count--;
    cout<<"Base's Dtor, count = "<<count<<endl;
  }
  virtual void set(int b){base = b;}
  virtual int get() const{return base;}
  void work() const{cout<<"Work in Base!"<<endl;}
  virtual void print() const{cout<<"Value of base: "<<base<<endl;}
};

class Derived: public Base{
  static Base objBase;
  int derived;
public:
  Derived(int d = 40): Base(), derived(d){cout<<"Derived's Ctor"<<endl;}
  ~Derived(){cout<<"Derived's Dror"<<endl;}
  void work() const{
    cout<<"Work in Derived!"<<endl;
    Base::work();
    (Derived::objBase).set(50);
    (Derived::objBase).print();
  }
  void set(int d){derived = d;}
  int get() const{return derived;}
  void print() const{
    Base::print();
    cout<<"Balue of derived: "<<derived<<endl;
  }
  static void printStaticObjValue(){
    cout<<"*** Static object's value: "<<objBase.get()<<" ***"<<endl;
  }
};

Base Derived::objBase;
int Base::count = 0;

int main(){
  // Base's Ctor, count = 1 (objBase value = 30)
  cout<<"--- Begin of main ---"<<endl;
  Derived::printStaticObjValue();
  // *** Static object's value: 30 ***
  cout<<"--- Block 1 ---"<<endl;
  Base obj1(9);
  // Base's Ctor, count = 2 (obj1 value = 9)
  Derived obj2(10);
  // Base's Ctor, count = 3 (obj2 base value = 30; derived value = 10)
  // Derived's Ctor
  {Base obj3 = obj2; obj3.print();}
  // Base's copy Ctor, count = 4 (obj1 value = 30)
  // Value of base: 30
  // Base's Dtor, count = 3 (obj3 destroyed)

  cout<<"--- Block 2 ---"<<endl;
  Base* objPtr = new Derived(18);
  // Base's Ctor, count = 4 (objPtr base value = 30)
  // Derived's Ctor (objPtr derived value = 18)
  Base& objRef = obj2;
  cout<<"--- Block 3 ---"<<endl;
  objPtr->print();
  // Value of base: 30
  // Value of derived: 18
  objPtr->work();
  // Work in Base!
  cout<<"--- Block 4 ---"<<endl;
  ((Derived*)(objPtr))->print();
  // Value of base: 30
  // Value of derived: 18
  ((Derived*)(objPtr))->work();
  // Work in Derived!
  // Work in Base!
  // Value of base: 50 (objBase value = 50)
  cout<<"--- Block 5 ---"<<endl;
  objRef.print();
  // Value of base: 30
  // Value of derived: 10
  objRef.work();
  // Work in Base!
  cout<<"--- Block 6 ---"<<endl;
  delete objPtr;
  // Derived's Dtor
  // Base's Dtor, count = 3
  cout<<"--- Block 7 ---"<<endl;
  Derived::printStaticObjValue();
  // *** Static object's value: 50 ***
  cout<<"--- End of main ---"<<endl;
  // Derived's Dtor
  // Base's Dtor, count = 2
  // Base's Dtor, count = 1
  // Base's Dtor, count = 0
  return 0;
}
