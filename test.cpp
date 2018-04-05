#include <iostream>
#include <string>

using namespace std;


int main(){
  string a = "3.14";
  double b = stod(a);
  b++;
  cout<<b<<endl;
  return 0;
}
