#include<iostream>
#include<fstream>
#include<sstream>
# include "boy.h"
# include "girl.h"
#include "couple.h"

#define B 5
#define G 5
#define C 5

using namespace std;

int main()
{
	Boy boys[B];
	Girl girls[G];
	Couple couples[C];
	
	string line;
	int c = 0, x = 0;

	//takes input from boy.dat file
	ifstream boyInp("boy.dat");
	while(getline(boyInp,line)) {
		if(c++ == 0) continue;
		istringstream iss(line);
		string name;
		int a,i,b,t,s;
		char ty;
		if((iss>>name>>a>>i>>b>>t>>s>>ty)){
			boys[x++].setDetails(name,a,i,b,t,s,ty);
		} else {
			break;
		}
	}

	c = 0;
	x = 0;

	//taking input from girl.dat
	ifstream girlInp("girl.dat");
	while(getline(girlInp,line)) {
		if(c++ == 0) continue;
		istringstream iss(line);
		string name;
		int a,i,m,s;
		char ty,cr;
		if((iss>>name>>a>>i>>m>>cr>>s>>ty)){
			girls[x++].setDetails(name,a,i,m,ty,s,cr);
		} else {
			break;
		}
	}	
	c = 0;
	//forming couples
	for(int i = 0 ; i < G; i++) {
		if(girls[i].getCriterion() == 'A') {
			int max= -99;
			int ind = -1;
			for(int j = 0; j < B; j++) {
				if(boys[j].getAttractiveness() > max && boys[j].getStatus() == 0) {
					if(boys[j].getBudget() > girls[i].getMaintenance()) {
						if(girls[i].getAttractiveness() > boys[j].getThreshold()) {
							max = boys[j].getAttractiveness();
							ind = j;
						}
					}
				}
			}
		
			if(ind != -1) {
				boys[ind].setStatus(1);
				girls[i].setStatus(1);
				couples[c++].setDetails(boys[ind].getName(),girls[i].getname()) ; 
			}		
		} else if(girls[i].getCriterion() == 'I') {
			int max= -99;
                        int ind = -1;
                        for(int j = 0; j < B; j++) {
                                if(boys[j].getIntelligence() > max && boys[j].getStatus() == 0) {
                                        if(boys[j].getBudget() > girls[i].getMaintenance()) {
                                                if(girls[i].getAttractiveness() > boys[j].getThreshold()) {
                                                        max = boys[j].getIntelligence();
                                                        ind = j;
                                                }
                                        }
                                }
                        }
                          
                        if(ind != -1) {
                                boys[ind].setStatus(1);
                                girls[i].setStatus(1);
                                couples[c++].setDetails(boys[ind].getName(),girls[i].getname()) ;
                        }

		} else {
			int max= -99;
                        int ind = -1;
                        for(int j = 0; j < B; j++) {
                                if(boys[j].getBudget() > max && boys[j].getStatus() == 0) {
                                        if(boys[j].getBudget() > girls[i].getMaintenance()) {
                                                if(girls[i].getAttractiveness() > boys[j].getThreshold()) {
                                                        max = boys[j].getBudget();
                                                        ind = j;
                                                }
                                        }
                                }
                        }
                          
                        if(ind != -1) {
                                boys[ind].setStatus(1);
                                girls[i].setStatus(1);
                                couples[c++].setDetails(boys[ind].getName(),girls[i].getname()) ;
                        }
			
		}
	}

	//printing couples
	cout<<"-----------------COUPLES-------------------\n\n";

	for(int i = 0 ;i < C; i++) {
		cout<<"Boy b"<<couples[i].getBoy()<<" and Girl g"<<couples[i].getGirl()<<"\n";
		
	}
}
