#include <iostream>

using namespace std;

class A{
public:
  static int a;
  void fn(){a++;}
};

int A::a = 10;

int main(){
  cout<<A::a<<endl;
  A obj;
  obj.fn();
  cout<<A::a<<endl;
  return 0;
}
