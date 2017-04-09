#include "couple.h"

void Couple::setHappiness(float i)
{
	this->happiness = i; 
}

float Couple::getCompatibility()
{	
	return this->compatibility ;
}

float Couple::getHappiness()
{
       return  this->happiness;
}

void Couple::setCompatibility(float i)
{
        this->compatibility = i;
}

int * Couple::getGifts() 
{
	return this->giftsArr;
}

int Couple::getNum()
{
	return this->num;
}

void Couple::setGifts(int i) 
{
	giftsArr[(num)++] = i;
}

string	Couple:: getBoy()
{
	return this->boy;
}


string Couple::getGirl()
{
	return this->girl;
}	

void Couple::setDetails(string boy, string girl)
{
	this->num = 0;
	this->boy = boy;
	this->girl = girl;
}
