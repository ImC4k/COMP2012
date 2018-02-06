//Submit this file
#include "product.h"
//You are NOT allowed to include any additional library

Product::Product(string name, ProductType type, float price){
  this->name = name;
  this->type = type;
  this->price = price;
  quantity = 0;
}

string Product::getName(){
  return name;
}

ProductType Product::getType(){
  return type;
}

float Product::getPrice(){
  return price;
}

int Product::getQuantity(){
  return quantity;
}

bool Product::setPrice(float price){
  if(price > 0){
    this->price = price;
    return true;
  }
  return false;
}

bool Product::setQuantity(int quantity){
  if(quantity >= 0){
    this->quantity = quantity;
    return true;
  }
  return false;
}

int Product::compare(Product* other){ // returns 1 if price or name is larger than other
  if(this->price > other->price){
    return 1;
  }
  else if(fabs(this->price - other->price) < 0.01f){
    if(this->name > other->name){
      return 1;
    }
    else return -1; // return -1 if price and name is smaller than other
  }
  else return 0;
}
