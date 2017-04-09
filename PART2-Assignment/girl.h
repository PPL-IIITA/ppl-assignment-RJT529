#ifndef girl_h
#define girl_h

#include<iostream>
using namespace std;

class Girl
{
	string name;
        int intelligence;
        int attractiveness;
        int maintenance;
        int status;
	char type;
	char criterion;

        public:
        string getname();
        int getIntelligence();
        int getAttractiveness();
        int getMaintenance();
        int getStatus();
        char getType();
	char getCriterion();
        void setDetails(string,int,int,int,char,int,char);
	void setStatus(int );
};
#endif
