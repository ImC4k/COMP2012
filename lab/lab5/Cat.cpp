#include "Cat.h"

Cat::Cat(string name):Animal(name){}

void Cat::speak() const{
  Animal::speak();
  cout<<" I am a Cat. Meow!"<<endl;
}

void Cat::eat(string food) const{
  cout<<"The cat meows happily and eats "<<food<<"!"<<endl;
}

Cat::~Cat(){
  cout<<"~Cat()"<<endl;
}
