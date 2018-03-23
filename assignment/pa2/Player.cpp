/*
 * Player.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 */

#include "Player.h"

ostream& operator<<(ostream& os, const Player& h) {
	os << h.name << ":";
	for (int i = 0; i < h.getSize(); i++) {
		os << *h.getCard(i) << " ";
	}
	return os;
}

Player::Player(string name, Player* previous): name(name){
	if(previous == nullptr){
		nextPlayer = this;
	}
	else{
		Player* prev = previous->nextPlayer;
		previous->nextPlayer = this;
		this->nextPlayer = prev;
	}
}

void Player::drawCard(CardPile& drawPile, CardPile& discardPile, int number_of_cards){

	Card* prevCard = discardPile.removeTopCard(); // remove the top card in discardPile

	if(drawPile.getSize() >= number_of_cards){ // sufficient card to draw in drawPile
		for(int i = 0; i < number_of_cards; i++){
			*this += drawPile.removeTopCard();
		}
	}
	else if(drawPile.getSize() + discardPile.getSize() >= number_of_cards){ // sufficient card to draw in total
		for(int i = 0; i < number_of_cards; i++){
			if(drawPile.getSize() != 0){ // get every possible cards from cardPile
				*this += drawPile.removeTopCard();
			}
			else{ // move cards from discardPile to drawPile, and shuffle
				for(int i = 0; i < discardPile.getSize(); i++){
					drawPile += discardPile.removeTopCard();
				}
				drawPile.shuffle();
				*this += drawPile.removeTopCard();
			}
		}
	}
	else{ // not enough card, must draw all cards
		for(int i = 0; i < discardPile.getSize(); i++){
			drawPile += discardPile.removeTopCard();
		}
		for(int i = 0; i < drawPile.getSize(); i++){
			*this += drawPile.removeTopCard();
		}
	}

	discardPile += prevCard; // add back the top card to discardPile
}

Card* Player::playCardAfter(const Card* topCard, int index){
	if(index >= this->getSize())
		return nullptr;
	if(!((*topCard)^(*(this->getCard(index)))))
		return nullptr;
	else return this->removeCard(index);
}

int Player::getScore() const{
	int score = 0;
	for(int i = 0; i < this->getSize(); i++){
		score += this->getCard(i)->getPoint();
	}
	return score;
}
