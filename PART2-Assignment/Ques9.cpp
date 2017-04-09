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
#define K 2


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

//generic datastructure
template<class T>
void sortingDatastructure(T * arr,int n, int k, string s) 
{
	for(int i = 0  ; i< n-1; i++) {
		for(int j = i+1; j < n; j++) {
			 if(s == "attractiveness") {
				if(arr[j].getAttractiveness() < arr[i].getAttractiveness()) {
					swap(arr[j],arr[i]);
				}
			}
		}
	}
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
	logFile.open("logFile9.dat");


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
		int k = G;
		sortingDatastructure(girls,G,k,"attractiveness");
		int ind = 0; 
		int min = 999999;	
		for(int j = 0; j< k ; j++) {
			if(girls[j].getMaintenance() < min && girls[j].getStatus() == 0)
			{
				ind = j;
			} 
		}
		boys[i].setStatus(1);
                girls[ind].setStatus(1);
                couples[c++].setDetails(boys[i].getName(),girls[ind].getname()) ;
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

	logFile.close();
}
