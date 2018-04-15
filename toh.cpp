#include <iostream>
using namespace std;

void Toh(char tar, char buf, char des, int level){
  if(level == 1){
    cout<<tar<<" to "<<des<<endl;
  }
  else{
    Toh(tar, des, buf, level-1);
    Toh(tar, buf, des, 1);
    Toh(buf, tar, des, level-1);
  }
}

int main(){
  char a = 'A', b = 'B', c = 'C';
  Toh(a, b, c, 3);
}
