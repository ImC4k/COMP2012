/*
 * ReverseCard.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw
 */

#include "ReverseCard.h"
#include "Player.h"

ReverseCard::ReverseCard(Color color): Card(color, POINT_REVERSECARD){}

bool ReverseCard::operator^(const Card& t) const{
  if(this->Card::operator^(t)) return true;
  if(typeid(*this) == typeid(t)) return true;
  return false;
}

void ReverseCard::serialize(ostream& os) const{
  switch(color){
    case Color::red :
      cout<<'R'; break;
    case Color::blue:
      cout<<'B'; break;
    case Color::green:
      cout<<'G'; break;
    case Color::yellow:
      cout<<'Y'; break;
    default: break;
  }
  cout<<'r'<<endl;
}

void ReverseCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile){
   Player* curr = currentPlayer, *next, *prev = nullptr;
   do{
     next = curr->nextPlayer;
     curr->nextPlayer = prev;
     prev = curr;
     curr = next;
   }while(curr != currentPlayer);
   currentPlayer->nextPlayer = prev;
}

ReverseCard::~ReverseCard(){}
