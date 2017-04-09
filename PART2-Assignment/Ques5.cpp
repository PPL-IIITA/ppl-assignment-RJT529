#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
# include "boy.h"
# include "girl.h"
#include "couple.h"
#include "gift.h"


#define B 9	
#define G 5
#define C 5
#define Gf 15
#define K 3


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

void swapB(Boy &a, Boy &b)
{
	Boy temp = a;
	a = b;
	b = temp;
}

void swapG(Girl &a, Girl &b)
{
	Girl temp = a;
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
	logFile.open("logFile5.dat");


	
	/*
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
	/*
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
	x = 0;
	/*
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

	/*
	 * sorting boys
	 */
	for(int i = 0  ; i< B-1; i++) {
		for(int j = i+1; j < B; j++) {
			if(boys[i].getAttractiveness() > boys[j].getAttractiveness()) {
				swapB(boys[i],boys[j]);
			}	
		}
	}

	/*
	 *sorting girls
	 */
	for(int i = 0  ; i< G-1; i++) {
		for(int j = i+1; j < G; j++) {
			if(girls[i].getMaintenance() > girls[j].getMaintenance()) {
				swapG(girls[i],girls[j]);
			}	
		}
	}
	
	c = 0;
	int i = 0;
	/*
	 *Forming Couples
	 */
	for(int m = 0 ; m < G; m++) {
		if(m %2 == 0) {		//assigning a boy to a girl
			while(girls[i].getStatus() != 0 && i != G)i++;
 
			if(i == G) break;

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
		} else {		//assigning a girl to a boy
			for(int j = 0; j < B; j++) {
				if(boys[j].getStatus() == 0) {
					int ind = -1;
					int max = -99;
					for(int k = 0; k < G; k++) {
						if(girls[k].getStatus() == 0 && girls[i].getAttractiveness() > max) {
							max = girls[i].getAttractiveness();
							ind = k;
						} 
						
					}
					boys[j].setStatus(1);
		                        girls[ind].setStatus(1);
					couples[c++].setDetails(boys[j].getName(),girls[ind].getname()) ;
					break;
				}
			}
		}
	}

	/*
	 *Printing couples
	 */
	logFile<<"-----------------COUPLES-------------------\n\n";

	for(int i = 0 ;i < C; i++) {
		logFile<<"Boy b"<<couples[i].getBoy()<<" and Girl g"<<couples[i].getGirl()<<"\n";
		
	}

	/*
	 *Sorting gifts
	 */
	for(int i = 0  ; i< Gf-1; i++) {
		for(int j = i+1; j < Gf; j++) {
			if(gifts[j].getprice() < gifts[i].getprice()) {
				swap(gifts[j],gifts[i]);
			}
		}
	}

	/*
	 *Assigning gifts to couples
	 */
	for(int i  = 0 ;i < C; i++) {
		int boy = couples[i].getBoy()[0] - 48;
		int girl = couples[i].getGirl()[0] - 48;
		int mc = girls[girl-1].getMaintenance();
		int bud = boys[boy-1].getBudget();
		int x = bud - mc;
		char bt = boys[boy-1].getType();	
	
		if(bt == 'M') {
			for(int j = 0 ; j < Gf; j++) {
				
				if(gifts[j].getprice() <= mc && gifts[j].getStatus() == 0) {
					couples[i].setGifts(j+1);
					gifts[j].setStatus(1);
					mc = mc - gifts[j].getprice();
				} else if( gifts[j].getprice() <= x +mc ) {
					if( gifts[j].getStatus() == 0)	{				
						couples[i].setGifts(j+1);
						gifts[j].setStatus(1);
						break;
					}
				} else {
					break;
				}
			} 
		} else  if(bt == 'N') {
			for(int j = Gf-1 ; j >= 0; j--) {
				if(gifts[j].getprice() <= bud && gifts[j].getStatus() == 0) {
					couples[i].setGifts(j+1);
					gifts[j].setStatus(1);
					bud = bud- gifts[j].getprice();
				}
			}
		} else {
			for(int j = 0 ; j < Gf; j++) {
				if(gifts[j].getprice() <= mc && gifts[j].getStatus() == 0) {
					couples[i].setGifts(j+1);
					gifts[j].setStatus(1);
					mc = mc - gifts[j].getprice();
				}else if(gifts[j].getprice() <= x +mc) {
					if( gifts[j].getStatus() == 0)	{				
						couples[i].setGifts(j+1);
						gifts[j].setStatus(1);
						break;
					}
				} else {
					break;
				}
			}
		}
	}
	
	

	/*
	 *Calculating Happiness
	 */
	for(int i = 0; i < C; i++) {
		int boy = couples[i].getBoy()[0] - 48;
		int girl = couples[i].getGirl()[0] - 48;

		int mc = girls[girl-1].getMaintenance();
		int bud = boys[boy-1].getBudget();
		int x1 = bud - mc;

		char bt = boys[boy-1].getType();
		char gt = girls[girl-1].getType();
		
		int hb = 0;
		int hg = 0;

		int total = 0;
	
		
		int * arr =	couples[i].getGifts();
		for(int j = 0 ; j < couples[i].getNum(); j++) {
			total += gifts[arr[j]-1].getprice();
		}
	
		if(bt == 'M') {
			hb = bud-total;
		} else if(bt == 'N') {
			hb = hg;
		} else {
			hb = girls[girl-1].getIntelligence();
		}

		if(gt == 'C') {
			hg = log(abs(mc-total));
		} else if(gt == 'N') {
			hg = abs(mc-total);
		} else {
			hg = exp(abs(mc-total));
		}
		couples[i].setHappiness(hb + abs(hg));
		
	}


	/*
	 *sorting couples according to happiness
	 */
	for(int i = 0  ; i< C-1; i++) {
		for(int j = i+1; j < C; j++) {
			if(couples[i].getHappiness() > couples[j].getHappiness()) {
				swapC(couples[i],couples[j]);
			}	
		}
	}
	
	/*
	 *Printing k most happy couples
	 */
	logFile<<"\n---------------------K(== 3) Most Happy Couples------------------------\n\n";
	for(int i = C-1; i >C-K-1 ;i--) {
		logFile<<"Boy b"<<couples[i].getBoy()<<" and Girl g"<<couples[i].getGirl()<<"\n";
	}



	logFile.close();
}
