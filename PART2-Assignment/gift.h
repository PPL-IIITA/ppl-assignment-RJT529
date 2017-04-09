#ifndef gift_h
#define gift_h

#include<iostream>
using namespace std;

class Gift
{
	int id;
	int price;
	char type;
	int value;
	int status;
	public:
	void setDetail(int,int,char,int);
	void setStatus(int);
	int getId();
	int getprice();
	char getType();
	int getStatus();
	
};

#endif
