//Submit this file
#include "mall.h"
//You are NOT allowed to include any additional library

//NOTE: Mall::duplicateShopLinkedList must NOT be implemented here

Mall::Mall(string name, string address){
  this->name = name;
  this->address = address;
  shopHead = nullptr;
}

Mall::Mall(Mall& another){
  name = another.name;
  address = another.address;
  shopHead = duplicateShopLinkedList(another.shopHead);
}

Mall::~Mall(){ // remove all shops in the linked list
  //NOTE: must prevent memory lost
}

void Mall::setName(string name){
  this->name = name;
}

void Mall::setAddress(string address){
  this->address = address;
}

string Mall::getName(){
  return name;
}

string Mall::getAddress(){
  return address;
}

bool Mall::addShop(string name, int shopNumber){

}

bool Mall::removeShop(int shopNumber){

}

Shop* Mall::getShop(int shopNumber){

}
