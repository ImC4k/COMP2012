#include "Dog.h"

Dog::Dog(string name):Animal(name){}

void Dog::speak() const{
  Animal::speak();
  cout<<" I am a Dog. Woof!"<<endl;
}

void Dog::eat(string food) const{
  cout<<"The dog swings its tail furiously and eats "<<food<<"!"<<endl;
}

void Dog::swim() const{
  cout<<"The dog swims freely!"<<endl;
}

Dog::~Dog(){
  cout<<"~Dog()"<<endl;
}
