/*
 * WildCard.cpp
 *
 *  Created on: Feb 6, 2018
 *      Author: kevinw
 */

#include "WildCard.h"
#include "Player.h"

WildCard::WildCard(): Card(Color::meta, POINT_WILDCARD){}
WildCard::WildCard(int point): Card(Color::meta, point){}

bool WildCard::operator^(const Card& t) const{
  return this->Card::operator^(t);
}

void WildCard::serialize(ostream& os) const{
  switch(color){
    case Color::red :
      os<<"Rw"; break;
    case Color::blue:
      os<<"Bw"; break;
    case Color::green:
      os<<"Gw"; break;
    case Color::yellow:
      os<<"Yw"; break;
    case Color::meta:
      os<<"WC"; break;
    default: break;
  }
}

void WildCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile){
  Color newColor = currentPlayer->chooseColor();
  this->color = newColor;
}

void WildCard::init(){
  this->color = Color::meta;
}

WildCard::~WildCard(){}
