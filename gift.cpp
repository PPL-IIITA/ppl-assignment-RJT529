#include "gift.h"

void Gift::setDetail(int id,int price, char type,int status)
{
	this->id = id;
	this->price = price;
	this->type = type;
	this->status = status;
	
}

void Gift:: setStatus(int i)
{
	this->status = i;
}

int Gift::getId()
{
	return this->id;
}

int Gift::getprice()
{
	return this->price;
}

char Gift::getType()
{
	return this->type;
}

int Gift::getStatus()
{
	return this->status;
}


