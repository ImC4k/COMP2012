//Submit this file
#include "node.h"
//You are NOT allowed to include any additional library

Node::Node(Shop* shop, Node* next = nullptr){ // NOTE: Personally added default value
  this->shop = shop;
  this->next = next;
}

Node::~Node(){

}

Shop* Node::getShop(){
  return shop;
}

Node* Node::getNext(){
  return next;
}

void Node::setShop(Shop* shop){
  this->shop = shop;
}

void Node::setNext(Node* next){
  this->next = next;
}
