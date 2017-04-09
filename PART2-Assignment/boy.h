#ifndef _boy_h
#define _boy_h
#include <iostream>
using namespace std;
 class Boy
{
        string name;
        int intelligence;
        int attractiveness;
        int budget;
        int status;
        int threshold;
	char type;
        public:
        string getName();
        int getIntelligence();
        int getAttractiveness();
        int getBudget();
        int getStatus();
        int getThreshold();
	char getType();
        void setDetails(string,int,int,int,int,int,char);
	void setStatus(int);
	

};

 
#endif
