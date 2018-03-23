/*
 * DrawFourCard.h
 *
 *  Created on: Feb 6, 2018
 *      Author: kevinw
 */

#ifndef DRAWFOURCARD_H_
#define DRAWFOURCARD_H_
#include "WildCard.h"
// #include "typeinfo"

class DrawFourCard: public WildCard{
public:
  DrawFourCard();
  virtual bool operator^(const Card& t) const;
  virtual void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile);
  ~DrawFourCard();
protected:
  virtual void serialize(ostream& os) const;

};
#endif /* DRAWFOURCARD_H_ */
