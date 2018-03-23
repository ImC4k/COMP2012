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
  return true;
}

void WildCard::serialize(ostream& os) const{
  switch(color){
    case Color::red :
      cout<<"Rw"<<endl; break;
    case Color::blue:
      cout<<"Bw"<<endl; break;
    case Color::green:
      cout<<"Gw"<<endl; break;
    case Color::yellow:
      cout<<"Yw"<<endl; break;
    case Color::meta:
      cout<<"WC"<<endl; break;
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
