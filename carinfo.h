#ifndef _CARINFO_H
#define _CARINFO_H
#include "linklist.h"

struct carinfo{
  std::string models;
  std::string color;
  int id;
  float speed;
  float sellprice;
  float retailprice;
  float oTRprice;
  float totalSales;
};

#endif

