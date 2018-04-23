#include <iostream>
using namespace std;

void test(void (*fn)(int), int num){
  fn(num);
}

void haha(int n){
  for(int i = 0; i < n; i++){
    cout<<"haha line"<<endl;
  }
}

int main(){
  void (**testy)(void (*test2)(int), int);
  *testy = test(haha(4), 3);
  testy();

}
