#include <iostream>
using namespace std;

void fn(const int& b){
  cout<<"!"<<endl;
}

void fn(int&& b){
  cout<<"?!"<<endl;
}

void fn(const int&& b){
  cout<<"?"<<endl;
}

int main(){
  fn(const_cast<const int>(3));
  return 0;

}
