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
  Node* current = shopHead;
  Node* tempNode = shopHead;
  while(current != nullptr){
    tempNode = current->getNext();
    delete current;
    current = tempNode;
  }
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
  if(shopHead == nullptr){
    Shop* newShop = new Shop(name, shopNumber);
    Node* newNode = new Node(newShop, nullptr);
    shopHead = newNode;
    return true;
  }

  Node* last = shopHead;

  do{ // get the last node in linked list, also see if same shopNumber occurs
    if(last->getShop()->getShopNumber() == shopNumber){
      return false;
    }
    if(last->getNext() != nullptr){
      last = last->getNext();
    }
    else break;
  } while(true);

  Shop* newShop = new Shop(name, shopNumber);
  Node* newNode = new Node(newShop, nullptr);
  last->setNext(newNode);
  return true;
}

bool Mall::removeShop(int shopNumber){
  Node* previous = shopHead;
  Node* next = shopHead;

  if(shopHead->getShop()->getShopNumber() == shopNumber){
    next = shopHead->getNext();
    delete shopHead;
    shopHead = next;
    return true;
  }

  while(previous->getNext() != nullptr){
    if(previous->getNext()->getShop()->getShopNumber() == shopNumber){
      Node* deleteNode = previous->getNext();
      next = deleteNode->getNext();
      previous->setNext(next);
      delete deleteNode;
      return true;
    }
    previous = previous->getNext();
  }
  return false;
}

Shop* Mall::getShop(int shopNumber){
  Node* current = shopHead;
  while(current != nullptr){
    if(current->getShop()->getShopNumber() == shopNumber){
      return current->getShop();
    }
    current = current->getNext();
  }
  return nullptr;
}
