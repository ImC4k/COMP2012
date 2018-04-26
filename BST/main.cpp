#include "bst.h"

int main(){
  BST<int> obj;
  obj.insert(10);
  obj.insert(8);
  obj.insert(12);
  obj.insert(11);
  obj.insert(13);
  obj.insert(13);

  obj.print();

  obj.remove(10);
  cout<<"\n\n\n\n"<<endl;

  obj.print();
}
