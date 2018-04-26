#include <iostream>
using namespace std;

void haha(int n){
  for(int i = 0; i < n; i++){
    cout<<"haha line"<<endl;
  }
}

int main(){
  void (*test)(int);
  test = haha;
  test(4);

}
