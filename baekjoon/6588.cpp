#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000*1000

unsigned char sieve[(MAX_N+7)/8];

inline bool isPrime(int k){
	return sieve[k>>3] & (1<<(k&7));
}

inline void setComposite(int k){
	sieve[k>>3] &= ~(1<<(k&7));
}

void eratosthenes(){
	memset(sieve, 0xff, sizeof(sieve));
	setComposite(0);
	setComposite(1);

	int sqrtn=int(sqrt(MAX_N));
	for(auto i=2; i<sqrtn; ++i){
		if(isPrime(i)){
			for(auto j=i*i; j<MAX_N; j+=i){
				setComposite(j);
			}
		}
	}
}

int main()
{
	eratosthenes();

	int n;
	while(true){
		cin >> n;
		if(n==0)
			break;
		int halfn=(n>>1);
		for(auto i=3; i<=halfn; i+=2){
			if(isPrime(i) && isPrime(n-i)){
				printf("%d = %d + %d\n",n,i,n-i);
				n=0;
				break;
			}
		}
		if(n!=0)
			puts("Goldbach's conjecture is wrong.");
	}
}

