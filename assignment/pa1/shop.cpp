//Submit this file
#include "shop.h"
//You are NOT allowed to include any additional library
Shop::Shop(string name, int shopNumber){
  this->name = name;
  this->shopNumber = shopNumber;
  products = nullptr;
}

Shop::Shop(Shop& another){
  name = another.name;
  shopNumber = another.shopNumber;
  //TODO: deep copy the dynamic array from another shop
}

Shop::~Shop(){
 // TODO
}

string Shop::getName(){
  return name;
}

int Shop::getShopNumber(){
  return shopNumber;
}

void Shop::setName(string name){
  this->name = name;
}

void Shop::setShopNumber(int shopNumber){
  this->shopNumber = shopNumber;
}

void Shop::addProduct(string name, ProductType type, float price, int quantityToAdd){

}

bool Shop::removeProduct(string name, int quantityToRemove){

}

Product* Shop::findProduct(string name){

}

bool Shop::updatePrice(string name, float price){
  Product* product = findProduct(name);
  if(product->setPrice(price))
    return true;
  return false;
}
