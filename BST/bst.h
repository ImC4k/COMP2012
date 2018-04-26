#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;

template <typename T>
class BST{
  private:
    struct BST_node{
      T data;
      BST left;
      BST right;

      BST_node(const T& data): data(data), left(), right(){}
      BST_node(const BST_node& another):data(another.data), left(another.left), right(another.right){}
      ~BST_node(){};
    };
    BST_node* root = nullptr;

  public:
    BST() = default;
    ~BST();
    BST(BST&& bst); // move constructor, set bst.root to nullptr
    BST(const BST& bst); // copy constructor, copy everything
    bool is_empty() const;
    bool contains(const T& data) const;
    void print(int depth = 0) const;
    const T& find_max() const;
    const T& find_min() const;
    void insert(const T& data);
    void remove(const T& data);
};


#include "bst.tpp"
#endif
