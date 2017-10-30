/*The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
Answer: 6857

Moded to do prime factor 4 every number
*/

#include <iostream>
using namespace :: std;
int is_prime(long value){
	if(value == 2){return 1;}
	if(value == 3){return 1;}
	if(value%2 == 0){return 0;}
	if(value%3 == 0){return 0;}

	long long unsigned i = 5;
	long long unsigned w = 2;

	while(i*i<=value){
		if(value%i == 0){return 0;}
		i+=w;
		w = 6-w;
		cout << "i=" << i << endl;
		cout << "w=" << w << endl;
	}
	return 1;
}
int main(){
	long number;
	long factor;
	long primefactor;
	cout << "\nEnter number:"; 
	cin >> number;
	for(int i = 1; i<number; i++){
		if(number%i==0){
			factor = i;
			if(is_prime(factor)){
				primefactor = i;
			}
		}
	}	
	
	cout << "\nLargest prime factor is:"<< primefactor <<endl;		
	
	return 0;
}
