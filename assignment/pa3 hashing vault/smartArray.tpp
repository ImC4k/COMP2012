//submit this file
//you do NOT need to include any header in this file
//just write your SmartArray implementation here right away

template <typename KeyType, typename ValueType>
SmartArray<KeyType, ValueType>::SmartArray(){
  this->data = nullptr;
  size = 0;
}

template <typename KeyType, typename ValueType>
SmartArray<KeyType, ValueType>::~SmartArray(){
  for(int i = 0; i < size; i++){
    delete data[i];
    data[i] = nullptr;
  }
  delete[] data;
}

template <typename KeyType, typename ValueType>
bool SmartArray<KeyType, ValueType>::add(KeyType key, ValueType value){
  if(size == 0){
    data = new Pair<KeyType, ValueType>*[1];
    data[0] = new Pair<KeyType, ValueType>(key, value);
    ++size;
    return true;
  }
  int insert_index = -1;
  for(int i = 0; i < size; i++){
    if(data[i]->key == key){
      return false;
    }
    if(data[i]->key < key){
      insert_index = i;
    }
  }
  insert_index++;

  int copy_index = 0;
  Pair<KeyType, ValueType>** data_n = new Pair<KeyType, ValueType>*[++size];
  for(int i = 0; i < size; i++){
    if(i == insert_index){
      data_n[i] = new Pair<KeyType, ValueType>(key, value);
      continue;
    }
    data_n[i] = data[copy_index];
    copy_index++;
  }
  delete[] data;
  data = data_n;
  return true;
}

template <typename KeyType, typename ValueType>
bool SmartArray<KeyType, ValueType>::remove(KeyType key){
  if(data == nullptr){
    return false;
  }
  if(size == 1 && data[0]->key == key){
    delete data[0];
    data[0] = nullptr;
    delete[] data;
    data = nullptr;
    size--;
    return true;
  }
  int remove_index = -1;
  for(int i = 0; i < size; i++){ // scan to see is there a key, -1 if false
    if(data[i]->key == key){
      remove_index = i;
      break;
    }
  }
  if(remove_index == -1){ // no such key
    return false;
  }
  else{
    Pair<KeyType, ValueType>** data_n = new Pair<KeyType, ValueType>*[--size];
    // if(remove_index == size){ // remove last element
    //   for(int i = 0; i < size; i++){
    //     data_n[i] = data[i];
    //   }
    //   delete data[remove_index];
    //   data[remove_index] = nullptr;
    //   return true;
    // }
    int copy_index = 0;
    for(int i = 0; i < size + 1; i++){
      if(i == remove_index){
        delete data[i]; // prevent memory leak!!!
        data[i] = nullptr;
        copy_index++;
      }
      if(i == size){
        break;
      }
      data_n[i] = data[copy_index];
      copy_index++;
    }
    delete[] data;
    data = data_n;

  }
  return true;
}

template <typename KeyType, typename ValueType>
ValueType SmartArray<KeyType, ValueType>::get(KeyType key) const{
  for(int i = 0; i < size; i++){
    if(data[i]->key == key){
      return data[i]->value;
    }
  }
  if (typeid(ValueType) == typeid(int))
		return 0;
	else
		 return ValueType();
}

template <typename KeyType, typename ValueType>
int SmartArray<KeyType, ValueType>::count() const{
  return size;
}

template <typename KeyType, typename ValueType>
const Pair<KeyType, ValueType>* SmartArray<KeyType, ValueType>::operator[](int n) const{
  if(n < 0 || n > size){
    return nullptr;
  }
  else return data[n];
}

template <typename KeyType, typename ValueType>
void SmartArray<KeyType, ValueType>::print(ostream& os) const{
  // os<<"("<<obj[i]->key<<","<<obj[i]->value<<")";
  for(int i = 0; i < size; i++){
    os<<"("<<data[i]->key<<","<<data[i]->value<<")";
  }
}

template <typename KeyType, typename ValueType>
bool SmartArray<KeyType, ValueType>::has(KeyType key) const{
  for(int i = 0; i < size; i++){
    if(data[i]->key == key){
      return true;
    }
  }
  return false;
}
