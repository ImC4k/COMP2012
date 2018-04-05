#ifndef TIME_H
#define TIME_H

#include "utils.h"

class Time{
  int hh; // stores hours
  int mm; // stores minute
  int ss; // stores second

public:
  Time(int hh = 0, int mm = 0, int ss = 0);
  Time(const Time& another);

  const Time& operator=(const Time& another);

  void print_time();

  int getHour();
  int getMinute();
  int getSecond();

  void setHour(int hh);
  void setMinute(int mm);
  void setSecond(int ss);
};


#endif
