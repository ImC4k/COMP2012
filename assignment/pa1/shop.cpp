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

  if(another.products != nullptr){
    products = new Product*[productCount];
    for(int i = 0; i < productCount; i++){
      Product* copyTarget = another.products[i];
      products[i] = new Product(copyTarget->getName(), copyTarget->getType(), copyTarget->getPrice());
      products[i]->setQuantity(copyTarget->getQuantity());
    }
  }
  else{
    products = nullptr;
  }
}

Shop::~Shop(){
 for(int i = 0; i < productCount; i++){
   delete products[i];
   products[i] = nullptr;
 }
 delete[] products;
 products = nullptr;
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
  if(products == nullptr){
    products = new Product*[++productCount];
    Product* newProduct = new Product(name, type, price);
    newProduct->setQuantity(quantityToAdd);
    products[0] = newProduct;
    return;
  }
  // the product already exists, search the product and add quantity
  for(int i = 0; i < productCount; i++){
    if(products[i]->getName() == name){
      int previousQuantity = products[i]->getQuantity();
      products[i]->setQuantity(previousQuantity + quantityToAdd);
      return;
    }
  }

  // for product not yet exist,
  // create dynamic array to store new ProductType
  // also increase productCount by 1
  Product* newProduct  = new Product(name, type, price); // create new object
  newProduct->setQuantity(quantityToAdd);

  bool addRequired = true;
  // BUG
  Product** newProducts = new Product*[++productCount];
  for(int i = 0, j = 0; i < productCount; i++, j++){ // i for index of newProducts, j for index of products
    if(j == productCount - 1){
      newProducts[i] = newProduct;
      break;
    }
    // int compareResult = newProduct->compare(products[j]); // DEBUG
    // cout<<compareResult; // DEBUG
    if(addRequired &&  newProduct->compare(products[j])== -1){
      newProducts[i++] = newProduct;
      addRequired = false;
    }
    Product* copyProduct = new Product(products[j]->getName(), products[j]->getType(), products[j]->getPrice());
    copyProduct->setQuantity(products[j]->getQuantity());
    newProducts[i] = copyProduct;
  }

  // delete old products[], reassign products[] to point to new array
  // delete[] products; BUG
  // products = newProducts;

  // newly added delete
  for(int i = 0; i < productCount - 1; i++){
    delete products[i];
    products[i] = nullptr;
  }
  delete[] products;
  products = newProducts;

}

bool Shop::removeProduct(string name, int quantityToRemove){

  Product* targetProduct = nullptr; // get the pointer to the required product
  for(int i = 0; i < productCount; i++){
    if(products[i]->getName() == name){
      targetProduct = products[i];
      break;
    }
  }
  // if request is negative, or if there is no such product, or if request is larger than there exists, do nothing and return false
  if(quantityToRemove < 0 || targetProduct == nullptr || targetProduct->getQuantity() < quantityToRemove){
    return false;
  }
  else if(targetProduct->getQuantity() > quantityToRemove){
    int previousQuantity = targetProduct->getQuantity();
    targetProduct->setQuantity(previousQuantity - quantityToRemove);
    return true;
  }
  else{ // (quantityToRemove == quantity), remove targetProduct from dynamic array
    // create new dynamic array to store products left
    if(productCount == 1){
      delete products[0];
      delete[] products;
      products = nullptr;
      return;
    }
    Product** newProducts = new Product*[--productCount];
    for(int i = 0, j = 0; i < productCount; i++, j++){ // i is index for newProducts, j is index for products
      if(products[j]->getName() == targetProduct->getName()){
        i--; // skip this copy, rest of product in products[] shifts by 1 place when copy to newProducts[]
        continue;
      }
      Product* copyProduct = new Product(products[j]->getName(), products[j]->getType(), products[j]->getPrice());
      copyProduct->setQuantity(products[j]->getQuantity());
      newProducts[i] = copyProduct;
    }

    // remove original products[], reassign products = newProducts

    // newly added delete
    for(int i = 0; i < productCount + 1; i++){
      delete products[i];
      products[i] = nullptr;
    }
    delete[] products;
    products = newProducts;

    return true;
  }
}

Product* Shop::findProduct(string name){
  for(int i = 0; i < productCount; i++){
    if(products[i]->getName() == name){
      return products[i];
    }
  }
  return nullptr;
}

bool Shop::updatePrice(string name, float price){
  Product* product = findProduct(name);
  if(product->setPrice(price)){
    // sorting
    for(int j = 0; j < productCount; j++){
      for(int i = 0; i < productCount - 1 - j; i++){
        if(products[i]->compare(products[i+1]) == 1){
          Product* swapProduct = products[i];
          products[i] = products[i+1];
          products[i+1] = swapProduct;
        }
      }
    }
    return true;
  }
  return false;
}
