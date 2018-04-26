#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat: public Animal{

public:
  Cat(string name);
  virtual void speak() const;
  virtual void eat(string food = "") const;
  ~Cat();
};

#endif
