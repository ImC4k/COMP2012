#include "ttt.h"

ttt::ttt(){
  for(int i = 0; i < 9; i++){
    inputs[i] = BLANK;
  }
}

bool ttt::isVacant(const int& position) const{
  if(position < 0 || position > 9) return false;
  return (inputs[position] == BLANK)? true : false;
}

bool ttt::putElement(ELEMENT element, const int& position){
  if(!isVacant(position)) return false;
  else inputs[position] = element;
  return true;
}

void ttt::removeElement(int position){
  inputs[position] = BLANK;
}

void ttt::print()const{ // TODO
  char inputs_to_visual[9];
  for(int i = 0; i < 9; i++){
    switch(inputs[i]){
      case BLANK: inputs_to_visual[i] = i + '1'; break;
      case P1: inputs_to_visual[i] = 'X'; break;
      case P2: inputs_to_visual[i] = 'O'; break;
      default: inputs_to_visual[i] = '?'; break;
    }
  }
  cout<<inputs_to_visual[0]<<"  |  "<<inputs_to_visual[1]<<"  |  "<<inputs_to_visual[2]<<endl;
  cout<<"---|-----|---"<<endl;
  cout<<inputs_to_visual[3]<<"  |  "<<inputs_to_visual[4]<<"  |  "<<inputs_to_visual[5]<<endl;
  cout<<"---|-----|---"<<endl;
  cout<<inputs_to_visual[6]<<"  |  "<<inputs_to_visual[7]<<"  |  "<<inputs_to_visual[8]<<endl;


}

int ttt::findWin(const int& position){ // TODO
  int numLine = 0;
  return 0;
}

bool isGameOver();
