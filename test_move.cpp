#include <iostream>
using namespace std;

class A{
  int a;
  int* ptr;
public:
  A(int a = 4, int* ptr = nullptr): a(a), ptr(ptr){}
  A(const A& a): a(a.a), ptr(new int(*(a.ptr))){}
  A(A&& a):a(a.a), ptr(a.ptr){a.a = 0; a.ptr = nullptr;}
  void print() const{ cout<<"a = "<<a<<endl<<"ptr = "<<ptr<<endl;}
  A& operator=(A&& a){this->a = a.a; this->ptr = a.ptr; a = 0; ptr = nullptr; return *this;}
};

int main(){
  A obj(4, new int(10));
  A obj2 = move(obj);
  obj.print();
  obj2.print();
  return 0;
}
