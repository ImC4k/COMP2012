#include "DrawFourCard.h"
#include "Player.h"

DrawFourCard::DrawFourCard(): WildCard(POINT_DRAWFOURCARD){}


void DrawFourCard::serialize(ostream& os) const{
  switch(color){
    case Color::red :
      os<<"4R"; break;
    case Color::blue:
      os<<"4B"; break;
    case Color::green:
      os<<"4G"; break;
    case Color::yellow:
      os<<"4Y"; break;
    case Color::meta:
      os<<"+4"; break;
    default: break;
  }
}

void DrawFourCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile){
  Player* nextPlayer = currentPlayer->getNextPlayer();
  WildCard::castEffect(currentPlayer, drawPile, discardPile);
  if(nextPlayer->appealDrawFour()){
    const Card* prevCard = discardPile.getTopCard();
    for(int i = 0; i < currentPlayer->getSize(); i++){
      const Card* current = currentPlayer->getCard(i);
      if(typeid(*current) == typeid(DrawFourCard)) continue;
      if((*prevCard)^(*current)){ // another card could be placed
        currentPlayer->drawCard(drawPile, discardPile, 4); // self draw four
        return;
      }
    }
    nextPlayer->drawCard(drawPile, discardPile, 6);
    currentPlayer = currentPlayer->getNextPlayer();
    return;
  }
  // without appeal
  nextPlayer->drawCard(drawPile, discardPile, 4);
  currentPlayer = currentPlayer->getNextPlayer();
}

DrawFourCard::~DrawFourCard(){}
