#include "bst.h"

int main(){
  BST<int> obj;

PROMPT:
  char input;
  cout<<"Input i, d, p, e (insert, delete, print, exit):"<<endl<<endl;
  cin>>input;
  switch(input){
    case('i'): goto INSERT;
    case('d'): goto REMOVE;
    case('p'): goto PRINT;
    case('e'): goto EXIT;
  }


INSERT:
  cout<<"Please input value:"<<endl;
  int num_insert;
  cin>>num_insert;
  obj.insert(num_insert);
  goto PROMPT;

REMOVE:
  cout<<"Please input value to delete:"<<endl;
  int num_remove;
  cin>>num_remove;
  obj.remove(num_remove);
  goto PROMPT;

PRINT:
  obj.print();
  cout<<"\n\n";
  goto PROMPT;

EXIT:
  cout<<"BYE"<<endl;
  return 0;
}
