/*
 * NumberCard.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 */

#include "NumberCard.h"

NumberCard::NumberCard(int number, Color color): Card(color, number), number(number){}

bool NumberCard::operator^(const Card&t) const{
  if(this->Card::operator^(t)) return true;
  if(this->number == t.getPoint()) return true;
  return false;
}

void NumberCard::serialize(ostream& os) const{
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
  os<<number;
}

void NumberCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile){}

NumberCard::~NumberCard(){

}
