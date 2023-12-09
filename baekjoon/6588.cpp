#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000*1000+1

bool isPrime[MAX_N];

void eratosthenes(){
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0]=isPrime[1]=false;
	
	int sqrtn=int(sqrt(MAX_N));
	for(auto i=2; i<=sqrtn; ++i)
		if(isPrime[i])
			for(auto j=i*i; j<=MAX_N; j+=i)
				isPrime[j]=false;
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
			if(isPrime[i] && isPrime[n-i]){
				printf("%d = %d + %d\n",n,i,n-i);
				n=0;
				break;
			}
		}
		if(n!=0)
			puts("Goldbach's conjecture is wrong.");
	}
}

