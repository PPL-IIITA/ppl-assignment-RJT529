#ifndef lib7_h
#define lib7_h

#include<iostream>
#include<fstream>
#include<sstream>
# include "boy.h"
# include "girl.h"
#include "couple.h"
#include "gift.h"

#define B 9	
#define G 5
#define C 5
#define S 5
#define Gf 15
using namespace std;

class Library
{
	public:
	Couple * couples ;
	Couple * sortedCouples;
	Couple hashCouples[C];
	Boy boysList[S];
	ofstream logFile;	

	public:
	void searchArr();
	void searchSortedArr();
	void searchHash();
};


#endif
