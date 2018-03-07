#include <iostream>


using namespace std;

int main(){
  const double s1 = 0.1;
  const double s2 = 0.6;
  const double s3 = 0.7;
  const double s4 = 0.8;
  const double s5 = 0.5;
  double result = 0;
  
  // result = -s1*s4 - s2*s5 + s1*s2*s4 + s1*s2*s5 + s1*s3*s4 + s1*s3*s5 + s1*s4*s5 + s2*s3*s4 + s2*s3*s5;
  // result = result - s2*s3*s4*s5 - s1*s3*s4*s5 - s1*s2*s4*s5 - s1*s2*s3*s5 - s1*s2*s3*s4 + s1*s2*s3*s4*s5;

  cout<<result<<endl;
  return 0;
}
