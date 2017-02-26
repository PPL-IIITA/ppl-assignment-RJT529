#ifndef couple_h
#define couple_h

#include<iostream>
#define Gf 15
using namespace std;

class Couple
{
        string boy;
        string girl;
	int giftsArr[Gf];
	int num;
        float happiness;
        float compatibility;
        
	public:
	string getBoy();
	string getGirl();
	int getNum();
	int * getGifts();
	void setGifts(int);
	void setHappiness(float);
	void setCompatibility(float);
	float getHappiness();
        float getCompatibility();

        void setDetails(string,string);
};

#endif
