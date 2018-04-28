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
  if(data == nullptr){
    data = new Pair<KeyType, ValueType>[1];
    data[0] = new Pair<KeyType, Value>(key, value);
    return true;
  }
  int insert_index = -1;
  for(int i = 0; i < size; i++){
    if(data[i]->key == key){
      return false;
    }
    if(data[i]->key < key){
      insert_index = data[i]->key + 1;
      /*
        suppose key is 0, such key exists, then return false
        suppose key is 2, key existing: 0, 1; then insert_index = 2
      */
    }
  }
  int copy_index = 0;
  Pair<KeyType, ValueType>** data_n = new Pair<KeyType, ValueType>*[++size];
  for(int i = 0; i < size; i++){
    if(i == insert_index){
      data_n[i] = new Pair<KeyType, ValueType>(key, value);
      copy_index++;
      continue;
    }
    data_n[i] = data[copy_index];
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
  int remove_index = -1;
  for(int i = 0; i < size; i++){ // scan to see is there a key, -1 if false
    if(data[i]->key == key){
      remove_index = i;
      break;
    }
  }
  if(remove_index == -1){
    return false;
  }
  else{
    Pair<KeyType, ValueType>** data_n = new Pair<KeyType, ValueType>*[--size];
    copy_index = 0;
    for(int i = 0; i < size; i++){
      if(i == remove_index){
        delete data[i]; // prevent memory leak!!!
        data[i] = nullptr;
        copy_index++;
        continue;
      }
      data_n[i] = data[copy_index];
    }
    delete data;
    data = data_n;
  }
  return true;
}

template <typename KeyType, typename ValueType>
ValueType SmartArray<KeyType, ValueType>::get(KeyType key) const{
  for(int i = 0; i < data; i++){
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
  for(int i = 0; i < size; i++){
    os<<*data[i];
  }
}

template <typename KeyType, typename ValueType>
bool SmartArray<KeyType, ValueType>::has(KeyType key) const{

}
