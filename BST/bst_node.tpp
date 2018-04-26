template <typename T>
BST_node<T>::BST_node(T data, BST left, BST right): data(data), left(left), right(right){}

template <typename T>
BST_node<T>::BST_node(const BST_node<T>& another){
  this->data = another.data;
  this->left = another.left;
  this->right = another.right;
}
template <typename T>
BST_node<T>::~BST_node();
