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
      cout<<'R'; break;
    case Color::blue:
      cout<<'B'; break;
    case Color::green:
      cout<<'G'; break;
    case Color::yellow:
      cout<<'Y'; break;
    default: break;
  }
  cout<<number<<endl;
}

void NumberCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile){}

NumberCard::~NumberCard(){

}
