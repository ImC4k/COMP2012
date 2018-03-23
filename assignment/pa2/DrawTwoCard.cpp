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
  if(this->Card::operator^(t)) return true;
  return false;
}

void DrawTwoCard::serialize(ostream& os) const{
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
  cout<<'+'<<endl;
}

 // next player draws addtional two cards
void DrawTwoCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile){
  Player* nextPlayer = currentPlayer->getNextPlayer();
  nextPlayer->drawCard(drawPile, discardPile, 2);
  SkipCard::castEffect(currentPlayer, drawPile, discardPile);
}

DrawTwoCard::~DrawTwoCard(){

}
