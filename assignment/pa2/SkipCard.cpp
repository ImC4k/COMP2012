/*
 * SkipCard.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw
 */

#include "SkipCard.h"
#include "Player.h"

SkipCard::SkipCard(Color color): Card(color, POINT_SKIPCARD){}
SkipCard::SkipCard(Color color, int point): Card(color, point){}

bool SkipCard::operator^(const Card& t) const{
  if(this->Card::operator^(t) || typeid(t) == typeid(*this)) return true;
  if(typeid(*this) == typeid(t)) return true;
  return false;
}

void SkipCard::serialize(ostream& os) const{
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
  os<<'s';
}

// need to skip next player
void SkipCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile){
  // TODO
  currentPlayer = currentPlayer->getNextPlayer();
}

SkipCard::~SkipCard(){}
