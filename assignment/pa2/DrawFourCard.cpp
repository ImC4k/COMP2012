#include "DrawFourCard.h"

DrawFourCard::DrawFourCard(): WildCard(POINT_DRAWFOURCARD){}

bool operator^(const Card& t) const{
  return true;
}

void DrawFourCard::serialize(ostream& os) const{
  switch(color){
    case Color::red :
      cout<<"4R"<<endl; break;
    case Color::blue:
      cout<<"4B"<<endl; break;
    case Color::green:
      cout<<"4G"<<endl; break;
    case Color::yellow:
      cout<<"4Y"<<endl; break;
    case Color::meta:
      cout<<"4+"<<endl; break;
    default: break;
  }
}

void DrawFourCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile){
  Player* nextPlayer = currentPlayer->getNextPlayer();
  if(nextPlayer->appealDrawFour()){
    Card* prevCard = discardPile.getTopCard();
    for(int i = 0; i < currentPlayer->getSize(); i++){
      Card* current = currentPlayer->getCard(i);
      if(typeid(*current) == typeid(DrawFourCard)) continue;
      if((*current)^(*prevCard)){ // another card could be placed
        currentPlayer->drawCard(drawPile, discardPile, 4);
        return;
      }
    }
    WildCard::castEffect();
    nextPlayer->drawCard(drawPile, discardPile, 6);
  }
  // without appeal
  WildCard::castEffect();
  nextPlayer->drawCard(drawPile, discardPile, 4);
}

DrawFourCard::~DrawFourCard(){}
