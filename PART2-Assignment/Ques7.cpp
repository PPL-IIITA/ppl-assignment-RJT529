#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
# include "boy.h"
# include "girl.h"
#include "couple.h"
#include "gift.h"
#include "lib7.h"


#define B 9	
#define G 5
#define C 5
#define Gf 15
#define S 5
#define CHOICE 2


using namespace std;

void swap(Gift& a, Gift& b)
{
    Gift temp = a;
    a = b;
    b = temp;
}

void swapC(Couple &a, Couple &b) 
{
	Couple temp = a;
	a = b;
	b = temp;
}


int main()
{
	Boy boys[B];
	Girl girls[G];
	Library ob ;
	Couple couples[C];
	Gift gifts[Gf];
	
	string line;
	int c = 0, x = 0;

	ofstream logFile;
	logFile.open("logFile7.dat");


	/**
	 *taking input from boy.dat
	 */
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
	/**
	 *taking iput from girl.dat
	 */
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
	x = 0;
	/**
	 *taking input from gift.dat
	 */
	ifstream giftInp("gift.dat");
	while(getline(giftInp,line)) {
		if(c++ == 0) continue;
		istringstream iss(line);
		int id,p,v;
		char ty;
		if((iss>>id>>p>>ty>>v)){
			gifts[x++].setDetail(id,p,ty,0);
		} else {
			break;
		}
	}
	
	c = 0;
	/**
	 *forming couples
	 */
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

	/**
	 *printing the couples formed
	 */
	logFile<<"-----------------COUPLES-------------------\n\n";
	for(int i = 0 ;i < C; i++) {
		logFile<<"Boy b"<<couples[i].getBoy()<<" and Girl g"<<couples[i].getGirl()<<"\n";
		
	}

	/**
	 *original couple array
	 */
	ob.couples = couples;

	/**
	 *creating hashtables
	 */
	for(int i = 0; i < C-1; i++) {
		ob.hashCouples[i].setDetails("","") ;
	}
	for(int i = 0; i < C; i++) {
		int ind = (couples[i].getBoy()[0] + 7)%C;
		while(ob.hashCouples[ind].getBoy() != "") ind = (ind+1)%C;
		ob.hashCouples[ind] = couples[i]; 
	}

	/**
	 *Sorting couples according to happiness
	 */
		for(int i = 0  ; i< C-1; i++) {
			for(int j = i+1; j < C; j++) {
				if(couples[i].getBoy()[0] > couples[j].getBoy()[0]) {
					swapC(couples[i],couples[j]);
				}	
			}
		}
	ob.sortedCouples = couples;

	/**
	 *creating list of boys to be looked for
	 */
	logFile<<"\n-----------List of Boys----------\n\n";
	for(int i = 0; i < S; i++) {
		ob.boysList[i]= boys[i];	
		logFile<<"b"<<ob.boysList[i].getName()<<" ";
	}	
	logFile<<endl;

	/**
	 *Selecting algo from library file
	 */
	int choice = CHOICE;
	switch(choice) {
		case 1:		
			/**
			 *for linear search
			 */
			ob.searchArr();
			break;
		case 2:		
			/**
			 *for binary search
			 */
			ob.searchSortedArr();
			break;
		case 3:		
			/**
			 *for using hashtable
			 */
			cout<<choice<<endl;
			ob.searchHash();
			break;

	}
	logFile.close();
}
