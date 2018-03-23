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
  if(this->Card::operator^(t) || typeid(t) == typeid(*this)) return true;
  if(typeid(*this) == typeid(t)) return true;
  return false;
}

void ReverseCard::serialize(ostream& os) const{
  switch(color){
    case Color::red :
      os<<'R'; break;
    case Color::blue:
      os<<'B'; break;
    case Color::green:
      os<<'G'; break;
    case Color::yellow:
      os<<'Y'; break;
    default: break;
  }
  os<<'r';
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
