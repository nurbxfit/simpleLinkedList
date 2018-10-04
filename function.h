#ifndef _FUNCT_
#define _FUNCT_
#include "linklist.h"
#include "unorderlist.h"
#include "orderlist.h"
#include "carinfo.h"
void menu1(int&);
bool getanswer(bool&);
void askcarinfo(carinfo &);
void loadcarinfo(std::ifstream&,carinfo,unorderlist<carinfo>&,orderlist<carinfo>&);
void banner();



#endif
