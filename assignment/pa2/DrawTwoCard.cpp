/*
 * DrawTwoCard.cpp
 *
 *  Created on: Feb 5, 2018
 *      Author: kevinw
 */

#include "DrawTwoCard.h"
#include "Player.h"

DrawTwoCard::DrawTwoCard(Color color): SkipCard(color, POINT_DRAWTWOCARD){}

bool DrawTwoCard::operator^(const Card& t) const{
  if(this->Card::operator^(t) || typeid(t) == typeid(*this)) return true;
  return false;
}

void DrawTwoCard::serialize(ostream& os) const{
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
  os<<'+';
}

 // next player draws addtional two cards
void DrawTwoCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile){
  Player* nextPlayer = currentPlayer->getNextPlayer();
  nextPlayer->drawCard(drawPile, discardPile, 2);
  SkipCard::castEffect(currentPlayer, drawPile, discardPile);
}

DrawTwoCard::~DrawTwoCard(){

}
