#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
# include "boy.h"
# include "girl.h"
#include "couple.h"
#include "gift.h"


#define B 5
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

int main()
{
	Boy boys[B];
	Girl girls[G];
	Couple couples[C];
	Gift gifts[Gf];
	
	string line;
	int c = 0, x = 0;

	ofstream logFile;
	logFile.open("logFile.dat");


	//taking input from boy.dat
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
	x = 0;
	//taking input gift.dat
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
	logFile<<"-----------------COUPLES-------------------\n\n";

	for(int i = 0 ;i < C; i++) {
		logFile<<"Boy b"<<couples[i].getBoy()<<" and Girl g"<<couples[i].getGirl()<<"\n";
		
	}

	//sorting gifts	
	for(int i = 0  ; i< Gf-1; i++) {
		for(int j = i+1; j < Gf; j++) {
			if(gifts[j].getprice() < gifts[i].getprice()) {
				swap(gifts[j],gifts[i]);
			}
		}
	}

	//Assigning gifts to couples
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
	
	//printing assigned gifts
	logFile<<"\n\n-----------------GIFTS ALLOCATION-------------------\n\n";

	for(int i = 0 ;i < C; i++) {
		logFile<<"Boy b"<<couples[i].getBoy()<<" gives Girl g"<<couples[i].getGirl()<<" the following Gifts\n";
		
		int * arr =	couples[i].getGifts();
		for(int j = 0; j < couples[i].getNum(); j++) {
			logFile<<"G"<<gifts[arr[j]-1].getId()<<" of worth Rs "<<gifts[arr[j]-1].getprice()<<"\n";
		}
		logFile<<endl;
	}


	//calculating compatibility
	for(int i = 0 ; i < C; i++) {
		int boy = couples[i].getBoy()[0] - 48;
		int girl = couples[i].getGirl()[0] - 48;

		int mc = girls[girl-1].getMaintenance();
		int bud = boys[boy-1].getBudget();
		int x1 = bud - mc;

		int ag = girls[girl-1].getAttractiveness();
		int ab = boys[boy-1].getAttractiveness();
		int x2 = abs(ag-ab);				

		int ib = boys[boy-1].getIntelligence();
		int ig = girls[girl-1].getIntelligence();
		int x3 = abs(ib- ig);

		couples[i].setCompatibility(x1 + x2 + x3);		
	}

	//calculating happiness
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

	
	//sorting couples according to compatibility
	for(int i = 0  ; i< C-1; i++) {
		for(int j = i+1; j < C; j++) {
			if(couples[i].getCompatibility() > couples[j].getCompatibility()) {
				swapC(couples[i],couples[j]);
			}	
		}
	}

	logFile<<"\n------------------Most Compatible---------------------\n\n";
	for(int i = C-1 ;i >= C-K; i--) {
		logFile<<"Boy b"<<couples[i].getBoy()<<" and Girl g"<<couples[i].getGirl()<<"\n";;
	}


	//sorting couples according to happiness
	for(int i = 0  ; i< C-1; i++) {
		for(int j = i+1; j < C; j++) {
			if(couples[i].getHappiness() > couples[j].getHappiness()) {
				swapC(couples[i],couples[j]);
			}	
		}
	}
	
	logFile<<"\n---------------------Most Happy------------------------\n\n";
	for(int i = C-1 ;i >= C-K; i--) {
		logFile<<"Boy b"<<couples[i].getBoy()<<" and Girl g"<<couples[i].getGirl()<<"\n";
	}

	

	logFile.close();
}
