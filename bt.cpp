#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Node{
  T data;
  Node* left;
  Node* right;

public:
  Node(T data, Node* left = nullptr, Node* right = nullptr): data(data), left(left), right(right){}
  ~Node(){
    delete left;
    delete right;
    cout<<"deleting "<<data<<endl;
  }
  T getData(){return data;}
  Node* getLeft(){return left;}
  Node* getRight(){return right;}

  void setData(T data){this->data = data;}
  void setLeft(Node* node){left = node;}
  void setRight(Node* node){right = node;}
};

template <typename T>
void printInOrder(Node<T>* Tree){
  if(Tree == nullptr){
    return;
  }
  printInOrder(Tree->getLeft());
  cout<<Tree->getData()<<" ";
  printInOrder(Tree->getRight());
}

template <typename T>
void printPreOrder(Node<T>* Tree){
  if(Tree == nullptr){
    return;
  }
  cout<<Tree->getData()<<" ";
  printPreOrder(Tree->getLeft());
  printPreOrder(Tree->getRight());
}

template <typename T>
void printPostOrder(Node<T>* Tree){
  if(Tree == nullptr){
    return;
  }
  printPostOrder(Tree->getLeft());
  printPostOrder(Tree->getRight());
  cout<<Tree->getData()<<" ";
}

template <typename T>
void printLevelOrder(Node<T>* Tree, queue<T>& sequence){
  if(Tree == nullptr){
    return;
  }
  sequence.push(Tree->getData());
}

int main(){
  Node<int>* node1 = new Node<int>(5);
  Node<int>* node2 = new Node<int>(9);
  Node<int>* node3 = new Node<int>(12);
  Node<int>* node4 = new Node<int>(17);
  Node<int>* node5 = new Node<int>(8,node1, node2);
  Node<int>* node6 = new Node<int>(15, node3, node4);
  Node<int>* node7 = new Node<int>(10, node5, node6);

  cout<<"In order:"<<endl;
  printInOrder(node7);
  cout<<endl<<"Pre order:"<<endl;
  printPreOrder(node7);
  cout<<endl<<"Post order:"<<endl;
  printPostOrder(node7);
  cout<<endl<<"Level order:"<<endl;
  queue<int> sequence;
  sequence.push(-1);
  printLevelOrder(node7, sequence);
  cout<<sequence.front()<<endl;


  delete node7;
  return 0;
}
