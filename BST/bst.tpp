template <typename T>
BST<T>::~BST(){delete root;}

template <typename T>
BST<T>::BST(BST&& bst){
  this->root = bst.root;
  bst.root = nullptr;
}

template <typename T>
BST<T>::BST(const BST& bst){
  if(bst.is_empty()){
    return;
  }
  this->root = new BST_node(*(bst.root));
}

template <typename T>
bool BST<T>::is_empty() const{return root == nullptr;}

template <typename T>
bool BST<T>::contains(const T& data) const{
  if(is_empty()){return false;} // return false if empty
  if(this->root->data == data){return true;}
  else if(data < this->root->data){return this->root->left.contains(data);}
  else return this->root->right.contains(data);
}

template <typename T>
void BST<T>::print(int depth) const{
  if(is_empty())return; // if empty, then go back

  this->root->right.print(depth + 1); // print R

  for(int i = 0; i < depth; i++){ // print spaces
    cout<<'\t';
  }
  cout<<this->root->data<<endl; // print C

  this->root->left.print(depth + 1); // print L
}

template <typename T>
const T& BST<T>::find_max() const{
  if(this->root->right.is_empty()){
    return this->root->data;
  }
  else return this->root->right.find_max();
}

template <typename T>
const T& BST<T>::find_min() const{
  if(this->root->left.is_empty()){
    return this->root->data;
  }
  else return this->root->left.find_min();
}

template <typename T>
void BST<T>::insert(const T& data){
  if(is_empty()){
    this->root = new BST_node(data);
    return;
  }
  else if(this->root->data == data){
    return;
  }
  else if(data < this->root->data){
    this->root->left.insert(data);
    return;
  }
  else this->root->right.insert(data);
}

template <typename T>
void BST<T>::remove(const T& data){
  if(is_empty()) return;
  if(data < this->root->data){
    this->root->left.remove(data);
  }
  else if(data > this->root->data){
    this->root->right.remove(data);
  }
  else{
    if(this->root->left.is_empty() && this->root->right.is_empty()){ // no children
      delete this->root;
      this->root = nullptr;
      return;
    }
    else if(!this->root->left.is_empty() && !this->root->right.is_empty()){ // both triangles have stuff
      T sup_data = this->root->left.find_max();
      this->remove(sup_data);
      this->root->data = sup_data;
      // this->root->data = this->root->left.find_max();
      // this->root->left.remove(this->root->data);
      return;
    }
    else{ // one of the sides has stuff
      if(!this->root->left.is_empty()){ // left has stuff
        BST_node* temp = this->root;
        temp->left.root = nullptr; // stop the connection with anything else
        this->root = this->root->left.root; // this triangle points to the left triangle of BST_node
        delete temp;
        return;
      }
      else{
        BST_node* temp = this->root;
        temp->right.root = nullptr; // stop the connection with anything else
        this->root = this->root->right.root; // this triangle points to the right triangle of BST_node
        delete temp;
        return;
      }
    }
  }
}
