#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
# include "boy.h"
# include "girl.h"
#include "couple.h"
#include "gift.h"
#include "lib8.h"


#define B 9	
#define G 5
#define C 5
#define Gf 15
#define K 2	
#define CHOICE 2


using namespace std;

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
	Couple couples[C];
	Gift gifts[Gf];

	
	string line;
	int c = 0, x = 0;

	ofstream logFile;
	logFile.open("logFile8.dat");


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
	 *taking input from girl.dat
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
         *printing couples
	 */
	logFile<<"-----------------COUPLES-------------------\n\n";

	for(int i = 0 ;i < C; i++) {
		logFile<<"Boy b"<<couples[i].getBoy()<<" and Girl g"<<couples[i].getGirl()<<"\n";
		
	}
	logFile<<endl;


	GiftAllocation * ob;
		
	int choice = CHOICE;
	
	switch(choice) {
		case 1:		//for choosing method1
			method1 m1;
			
			ob = &m1;

			//taking input for gifts
			ob->takeInput();

			//sorting gifts	
			ob->sortingGifts();
			m1.allocate(couples,boys,girls);
			logFile<<"-----------------YOU CHOSE METHOD 1-------------------"<<endl;
			ob->printingGifts(couples);
			break;

		case 2:		//for choosing method2
			method2 m2;
			ob = &m2; 	//upcasting
			//taking input for gifts
			ob->takeInput();

			//sorting gifts	
			ob->sortingGifts();
			m2.allocate(couples,boys,girls);
			logFile<<"-----------------YOU CHOSE METHOD 2-------------------"<<endl;
			ob->printingGifts(couples);
			break;
		
	}



	
	

	
	

	logFile.close();
}
