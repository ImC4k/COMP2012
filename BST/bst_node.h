#ifndef BST_NODE_H
#define BST_NODE_H
using namespace std;

template <typename T>
class BST_node{
  private:
    T data;
    BST left;
    BST right;
  public:
    BST_node(T data, BST left = nullptr, BST right = nullptr);
    BST_node(const BST_node<T>& another);
    ~BST_node();
};

#include "bst_node.tpp"
#endif
