#ifndef lib8_h
#define lib8_h

#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
# include "boy.h"
# include "girl.h"
#include "couple.h"
#include "gift.h"


#define B 9	
#define G 5
#define C 5
#define Gf 15
#define K 2

using namespace std;

class GiftAllocation
{
	public:
	Gift gifts[Gf];
	
	public:
	void takeInput();
	void sortingGifts();
	void swap(Gift& a, Gift& b);
	void printingGifts(Couple *couple);
	
};

class method1: public GiftAllocation
{
	public:
	void allocate(Couple * couples, Boy *boys, Girl *girls);
};

class method2: public GiftAllocation
{
	public:
	void allocate(Couple * couples, Boy *boys, Girl *girls);
};

#endif
