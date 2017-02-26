#include "boy.h"

string Boy:: getName() 
{
	return this->name;
}

int Boy::getIntelligence()
{
	return this->intelligence;
}
int Boy::getAttractiveness()
{
	return this->attractiveness;
}

int Boy::getBudget()
{
	return this->budget;
}

int Boy::getStatus()
{
	return this->status;
}

int Boy::getThreshold()
{
	return this->threshold;
}

char Boy::getType()
{
	return this->type;
}

void  Boy::setDetails(string name,int attractiveness,int intelligence,int budget ,int threshold,int status,char type)
{
	this->name = name;
	this->attractiveness = attractiveness;
	this->intelligence = intelligence;
	this->budget = budget;
	this->threshold = threshold;
	this->status = status;
	this->type = type;
}

void Boy::setStatus(int i)
{
	this->status = i;
}
