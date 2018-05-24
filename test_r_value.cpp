#include <iostream>
using namespace std;

template <typename T>
struct Pair{
  T data1, data2;

  Pair(T data1, T data2): data1(data1), data2(data2){cout<<"Pair default (conversion) constructor"<<endl;}

  Pair<T>& operator=(const Pair<T>& another){
    if(&another != this){
      this->data1 = another.data1;
      this->data2 = another.data2;
    }
    return *this;
  }

  Pair(const Pair<T>& another){
    *this = another;
    cout<<"Pair copy constructor"<<endl;
  }

  ~Pair(){
    cout<<"Pair destructor"<<endl;
  }

  T getData1() const {return data1;}

  T getData2() const {return data2;}

  void setData1(T data){data1 = data;}

  void setData2(T data){data2 = data;}

  void print() const{
    cout<<"Pair print function"<<endl;
    cout<<"("<<data1<<", "<<data2<<")"<<endl;
  }
};

template <typename T>
class Node{
  Pair<T>* data;

public:
  Node(Pair<T>* data = nullptr): data(data){cout<<"Node default constructor"<<endl;}

  Node(const Pair<T>& data): data(new Pair<T>(data)){cout<<"Node conversion constructor 1"<<endl;}

  Node(T data1, T data2): data(new Pair<T>(data1, data2)){cout<<"Node conversion constructor 2"<<endl;}

  const Node<T>& operator=(const Node<T>& another){
    if(&another != this){
      this->data = new Pair<T>(another.data->getData1(), another.data->getData2());
    }
    return *this;
  }

  const Node<T>& operator=(Node<T>&& another){
    if(&another != this){
      this->data = another.data;
      another.data = nullptr;
    }
    return *this;
  }

  Node(const Node<T>& another){
    *this = another;
    cout<<"Node copy constructor"<<endl;
  }

  Node(Node<T>&& another){
    *this = another;
    cout<<"Node move constructor"<<endl;
  }

  ~Node(){
    delete data;
    cout<<"Node destructor"<<endl;
  }

  T* getData(){return data;}

  void setData(T* data){
    delete this->data;
    this->data = data;
  }

  void print(){
    cout<<"Node print function"<<endl;
    data->print();
  }
};


int main(){
  cout<<"Case 1"<<endl;
  Pair<double> vector(1, 3.14); // default (conversion) constructor
  vector.print(); // pair print function
  Node<double> node(vector); // conversion constructor 1
  node.print();

  cout<<endl;
  cout<<"Case 2"<<endl;
  Pair<double>* haha = new Pair<double>(0, 0); // default (conversion) constructor
  haha->print(); // pair print
  Node<double> node2(haha); // default constructor
  node2.print(); // node print pair print

  cout<<endl;
  cout<<"Case 3"<<endl;
  Node<double> node3(node2); // copy constructor
  node3.print();

  cout<<endl;
  cout<<"Case 4"<<endl;
  Node<double> node4(Node<double>(3.3, 4.4)); // move constructor
  node4.print();

  cout<<endl;
  cout<<"Case 5"<<endl;
  Node<double> node5(0, 300); // dummy object
  Node<double> node6 = move(node5);
  node5.print();
  node6.print();

  cout<<endl;



  cout<<"end of main"<<endl;

  return 0;
}
