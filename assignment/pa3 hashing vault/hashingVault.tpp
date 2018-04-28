//submit this file
//you do NOT need to include any header in this file
//just write your HashingVault implementation here right away

template <typename KeyType, typename ValueType>
HashingVault<KeyType, ValueType>::HashingVault(int size, Container<KeyType, ValueType>** table, int(*fun)(KeyType)){

}

template <typename KeyType, typename ValueType>
HashingVault<KeyType, ValueType>::~HashingVault(){

}

template <typename KeyType, typename ValueType>
bool HashingVault<KeyType, ValueType>::add(KeyType key, ValueType value){

}

template <typename KeyType, typename ValueType>
ValueType HashingVault<KeyType, ValueType>::get(KeyType key) const{

}

template <typename KeyType, typename ValueType>
bool HashingVault<KeyType, ValueType>::remove(KeyType key){

}

template <typename KeyType, typename ValueType>
void HashingVault<KeyType, ValueType>::rehash(int size, Container<KeyType, ValueType>** table, int (*fun)(KeyType)){

}
