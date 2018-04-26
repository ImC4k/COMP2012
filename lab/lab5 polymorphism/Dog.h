#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog: public Animal{

public:
  Dog(string name);
  virtual void speak() const;
  virtual void eat(string food = "") const;
  virtual void swim() const;
  ~Dog();
};

#endif
