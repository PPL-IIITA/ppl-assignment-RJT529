#include "dst9.h"

template<class T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
void sortingDatastructure(T * arr,int n, int k, string s) 
{
	for(int i = 0  ; i< n-1; i++) {
		for(int j = i+1; j < n; j++) {
			if(s == "price") {
				if(arr[j].getprice() < arr[i].getprice()) {
					swap(arr[j],arr[i]);
				}
			} else if(s == "attractiveness") {
				if(arr[j].getAttractiveness() < arr[i].getAttractiveness()) {
					swap(arr[j],arr[i]);
				}
			}
		}
	}
}
