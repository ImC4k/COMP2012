#include <iostream>
using namespace std;

template <typename T>

T max_(T a, T b){
  cout<<"------"<<endl;
  return (a> b)? a:b;
}

class A{
  int a;
public:

  A(int a = 0): a(a){cout<<"A conversion constructor"<<endl;}
  A(const A& another): a(another.a){cout<<"A copy constructor"<<endl;}
  bool operator>(A obj){if(this->a > obj.a) return 1; else return 0;}
  int get_a(){return a;}
};

int main(){
  A obj = max_<A>(10, 3);
  cout<<obj.get_a()<<endl;
  cout<<"-----"<<endl;
  A obj2 = 10;
  return 0;
}
