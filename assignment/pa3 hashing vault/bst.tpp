//submit this file
//you do NOT need to include any header in this file
//just write your BST implementation here right away

// copy constructor deep copy
template <typename KeyType, typename ValueType>
BST<KeyType, ValueType>::BST(const BST<KeyType, ValueType>& another){
  if(another.isEmpty()){
    this->root = nullptr;
    return;
  }
  if(this != &another){
    this->~BST();
  }
  this->root = new BSTNode<KeyType, ValueType>(another.root->data.key, another.root->data.value);
  BST<KeyType, ValueType> temp_l(another.root->left);
  this->root->left.root = temp_l.root;
  BST<KeyType, ValueType> temp_r(another.root->right);
  this->root->right.root = temp_r.root;
  temp_l.root = nullptr;
  temp_r.root = nullptr;
}

template <typename KeyType, typename ValueType>
bool BST<KeyType, ValueType>::isEmpty() const{
  return (this->root == nullptr);
}

template <typename KeyType, typename ValueType>
const BST<KeyType, ValueType>* BST<KeyType, ValueType>::findMin() const{
  if(isEmpty()){
    return nullptr;
  }
  else if(this->root->left.isEmpty()){
    return this;
  }
  else{
    return this->root->left.findMin();
  }
}

template <typename KeyType, typename ValueType>
const BST<KeyType, ValueType>& BST<KeyType, ValueType>::rightSubtree() const{
  return this->root->right;
}

template <typename KeyType, typename ValueType>
const BST<KeyType, ValueType>& BST<KeyType, ValueType>::leftSubtree() const{
  return this->root->left;
}

template <typename KeyType, typename ValueType>
bool BST<KeyType, ValueType>::add(KeyType key, ValueType value){
  if(isEmpty()){
    root = new BSTNode<KeyType, ValueType>(key, value);
    return true;
  }
  if(key == this->root->data.key){
    return false;
  }
  else if(key < this->root->data.key){
    return this->root->left.add(key, value);
  }
  else{
    return this->root->right.add(key, value);
  }
}

//BUG
template <typename KeyType, typename ValueType>
bool BST<KeyType, ValueType>::remove(KeyType key){
  if(isEmpty()){
    return false;
  }
  if(key < this->root->data.key){ // go to left tree
    return this->root->left.remove(key);
  }
  else if(key > this->root->data.key){ // go to right tree
    return this->root->right.remove(key);
  }
  else if(this->root->left.root && this->root->right.root){ // remove target has two children
    this->root->data = this->root->right.findMin()->root->data;
    return this->root->right.remove(this->root->data.key);
  }
  else{ // 0 - 1 child
    BSTNode<KeyType, ValueType>* temp = this->root;
    root = (root->left.isEmpty())? root->right.root : root->left.root;
    temp->left.root = temp->right.root = nullptr;
    delete temp;
    return true;
  }
}

template <typename KeyType, typename ValueType>
ValueType BST<KeyType, ValueType>::get(KeyType key) const{
  if(isEmpty()){
    if (typeid(ValueType) == typeid(int))
  		return 0;
  	else
  		return ValueType();
  }
  if(key == this->root->data.key){
    return this->root->data.value;
  }
  else if(key < this->root->data.key){
    return this->root->left.get(key);
  }
  else{
  	return this->root->right.get(key);
  }
}

template <typename KeyType, typename ValueType>
int BST<KeyType, ValueType>::count() const{
  if(isEmpty()){
    return 0;
  }
  return 1 + this->root->left.count() + this->root->right.count();
}

template <typename KeyType, typename ValueType>
int BST<KeyType, ValueType>::height() const{
  if(isEmpty()){
    return 0;
  }
  if(this->root->left.isEmpty() && this->root->right.isEmpty()){
    return 0;
  }
  int l_height = this->leftSubtree().height();
  int r_height = this->rightSubtree().height();
  return 1 + ((l_height > r_height)? l_height : r_height); // 1 + max(l_height, r_height)
}

template <typename KeyType, typename ValueType>
const Pair<KeyType, ValueType>* BST<KeyType, ValueType>::operator[](int n) const{
  if(isEmpty() || n < 0 || n >= count()){
    return nullptr;
  }
  if(n == this->root->left.count()){
    return &this->root->data;
  }
  else if(n < this->root->left.count()){
    return this->root->left[n];
  }
  else{
    return this->root->right[n - this->root->left.count() - 1];
  }
}

template <typename KeyType, typename ValueType>
void BST<KeyType, ValueType>::print(ostream& os) const{
  int size = count();
  for(int i = 0; i < size; i++){
    os<<"("<<this->operator[](i)->key<<","<<this->operator[](i)->value<<")";
  }
}
