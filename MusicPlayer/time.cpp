#include "time.h"

Time::Time(int hh, int mm, int ss): hh(hh), mm(mm), ss(ss){}

Time::Time(const Time& another){
  *this = another;
}

const Time& Time::operator=(const Time& another){
  if(this != &another){
    this->hh = another.hh;
    this->mm = another.mm;
    this->ss = another.ss;
  }
  return *this;
}

void Time::print_time(){
  cout<<"The duration is "<<hh<<" : "<<mm<<" : "<<ss<<"."<<endl;
}

int Time::getHour(){return hh;}

int Time::getMinute(){return mm;}

int Time::getSecond(){return ss;}

void Time::setHour(int hh){
  this->hh = hh;
}

void Time::setMinute(int mm){
  this->mm = mm;
}

void Time::setSecond(int ss){
  this->ss = ss;
}
