#include <iostream>
#include <string>

using namespace std;

class haha{
  string asdf;
public:
    explicit haha(const char* s){
    asdf = s;
  }

  void print(){
    cout<<asdf<<endl;
  }
};

void print(haha obj){obj.print();}

int main(){
  print(haha("haha"));
  return 0;
}
