#include <iostream>
#include <string>

using namespace std;

class Card{
  int a;
public:
  Card(int a = 0): a(a){}
};

class CardPile{
  Card card;
public:
  CardPile(int a = 0): card(a){}
};

class Player: private CardPile{
public:
  Player(int a = 0): CardPile(a){}
};

int main(){
  B hehe;
  B haha;
  hehe.print(haha);
  return 0;
}
