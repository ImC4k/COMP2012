//Submit this file
#include "shop.h"
//You are NOT allowed to include any additional library
Shop::Shop(string name, int shopNumber){
  this->name = name;
  this->shopNumber = shopNumber;
  products = nullptr;
  productCount = 0;
}

Shop::Shop(Shop& another){
  name = another.name;
  shopNumber = another.shopNumber;
  productCount = another.productCount;

  products = new Product*[productCount];
  for(int i = 0; i < productCount; i++){
    Product copyTarget = another.products[i];
    products[i] = new Product(copyTarget->getName(), copyTarget->getType(), copyTarget->getPrice());
  }
}

Shop::~Shop(){
 for(int i = 0; i < productCount; i++){
   delete products[i];
 }
 delete[] products;
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
  // the product already exists
  for(int i = 0; i < productCount; i++){
    if(products[i]->getName() == name){
      int previousQuantity = products[i]->getQuantity();
      products[i]->setQuantity(previousQuantity + quantityToAdd);
      return;
    }
  }


  // NOTE product not yet exist,
  // create dynamic array to store new ProductType
  // also increase productCount by 1
  Product* newProduct  = new Product(name, type, price);
  newProduct->setQuantity(quantity);

  bool addRequired = true;

  Product** newProducts = new Product*[++productCount];
  for(int i = 0, j = 0; i < productCount; i++, j++){ // i for index of newProducts, j for index of products
    if(addRequired && newProduct->compare(products[i]) == -1){
      newProducts[i++] = newProduct;
      addRequired = false;
    }
    else{
      Product* copyProduct = new Product(products[j]->getName(), products[j]->getType(), products[j]->getPrice());
      copyProduct->setQuantity(products[j]->getQuantity());
      newProducts[i] = copyProduct;
    }
  }

  // TODO delete old products[], reassign products[] to point to new array
  for(int i = 0; i < productCount - 1; i++){
    delete products[i]
  }
}

bool Shop::removeProduct(string name, int quantityToRemove){
  // TODO
  // productCount--;
  Product* targetProduct = nullptr;
  for(int i = 0; i < productCount; i++){
    if(products[i]->getName() == name){
      targetProduct = products[i];
    }
  }
  if(quantityToRemove < 0 || targetProduct == nullptr || targetProduct->getQuantity() < quantityToRemove){
    return false;
  }
  else if(targetProduct->getQuantity() > quantityToRemove){
    int previousQuantity = targetProduct->getQuantity();
    targetProduct->setQuantity(previousQuantity - quantityToRemove);
    return true;
  }
  else{ // TODO remove targetProduct from dynamic array

  }
}

Product* Shop::findProduct(string name){
  for(int i = 0; i < productCount; i++){
    if(!name.compare(products[i].name)){
      return products[i];
    }
  }
  return nullptr;
}

bool Shop::updatePrice(string name, float price){
  Product* product = findProduct(name);
  if(product->setPrice(price))
    return true;
  return false;
}
