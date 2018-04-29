//submit this file
//you do NOT need to include any header in this file
//just write your HashingVault implementation here right away

template <typename KeyType, typename ValueType>
HashingVault<KeyType, ValueType>::HashingVault(int size, Container<KeyType, ValueType>** table, int(*fun)(KeyType)): size(size), table(table), fun(fun){}

template <typename KeyType, typename ValueType>
HashingVault<KeyType, ValueType>::~HashingVault(){
  for(int i = 0; i < size; i++){
    delete table[i];
  }
  delete[] table;
}

template <typename KeyType, typename ValueType>
bool HashingVault<KeyType, ValueType>::add(KeyType key, ValueType value){
  int numSlot = fun(key);
  // int bst_size = table[numSlot]->count();
  // for(int i = 0; i < bst_size; i++){
  //   if(table[numSlot][i]->key == key){
  //     return false;
  //   }
  // }
  // table[numSlot]->add(key, value);
  // return true;
  return table[numSlot]->add(key, value);
}

template <typename KeyType, typename ValueType>
ValueType HashingVault<KeyType, ValueType>::get(KeyType key) const{
  int numSlot = fun(key);
  return table[numSlot]->get(key);
}

template <typename KeyType, typename ValueType>
bool HashingVault<KeyType, ValueType>::remove(KeyType key){
  int numSlot = fun(key);
  return table[numSlot]->remove(key);
}

// BUG
template <typename KeyType, typename ValueType>
void HashingVault<KeyType, ValueType>::rehash(int size, Container<KeyType, ValueType>** table, int (*fun)(KeyType)){
  Container<KeyType, ValueType>** old_table = this->table;
  this->table = table;
  int old_size = this->size;
  this->size = size;
  int(*old_fun)(KeyType) = this->fun;
  this->fun = fun;

  for(int i = 0; i < old_size; i++){ // loop through old_table
    int old_bst_size = old_table[i]->count(); // get size of binary tree in a slot
    for(int j = 0; j < old_bst_size; j++){ // loop through binary tree, rehash them, put them into new table
      this->add(old_table[i]->operator[](j)->key, old_table[i]->operator[](j)->value);
    }
  }
  for(int i = 0; i < old_size; i++){
    delete old_table[i];
  }
  delete[] old_table;
}
