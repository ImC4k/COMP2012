#include <iostream>
using std::cout;
using std::endl;
namespace haha{
  class vector{public: void print(){cout<<"success"<<endl;}};
}

using haha::vector;
using namespace haha;

int main(){
  vector obj;
  obj.print();
  return 0;

}
