#include "lib8.h"

void GiftAllocation::swap(Gift& a, Gift& b)
{
    Gift temp = a;
    a = b;
    b = temp;
}

void GiftAllocation::sortingGifts()
{
	//sorting gifts	
	for(int i = 0  ; i< Gf-1; i++) {
		for(int j = i+1; j < Gf; j++) {
			if(gifts[j].getprice() < gifts[i].getprice()) {
				swap(gifts[j],gifts[i]);
			}
		}
	}
}

void GiftAllocation::takeInput()
{
	int c = 0;
	int x = 0;
	string line;
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
	
}

void GiftAllocation::printingGifts(Couple *couples)
{
	
	//printing assigned gifts
	fstream logFile("logFile8.dat", std::fstream::in | std::fstream::out | std::fstream::app);
	logFile<<"\n\n-----------------GIFTS ALLOCATION-------------------\n\n";

	for(int i = 0 ;i < C; i++) {
		logFile<<"Boy b"<<couples[i].getBoy()<<" gives Girl g"<<couples[i].getGirl()<<" the following Gifts\n";
		
		int * arr =	couples[i].getGifts();
		for(int j = 0; j < couples[i].getNum(); j++) {
			logFile<<"G"<<gifts[arr[j]-1].getId()<<" of worth Rs "<<gifts[arr[j]-1].getprice()<<"\n";
		}
		logFile<<endl;
	}
}


void method1:: allocate(Couple *couples, Boy *boys, Girl *girls)
{
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

	for(int j = 0 ; j < Gf; j++) {
		gifts[j].setStatus(0);
	}

}

void method2:: allocate(Couple *couples, Boy *boys, Girl *girls)
{
	//Assigning gifts to couples
	for(int i  = 0 ;i < C; i++) {
		int boy = couples[i].getBoy()[0] - 48;
		int girl = couples[i].getGirl()[0] - 48;
		int mc = girls[girl-1].getMaintenance();
		int bud = boys[boy-1].getBudget();
		int x = bud - mc;
		char bt = boys[boy-1].getType();	
	
		if(bt == 'N') {
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
		} else  if(bt == 'K') {
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

	for(int j = 0 ; j < Gf; j++) {
		gifts[j].setStatus(0);
	}

}

