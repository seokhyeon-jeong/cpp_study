#include <bits/stdc++.h>
using namespace std;

#define MAX_N 10000001

int minFactor[MAX_N];

void getMinFactor(){
	minFactor[0]=minFactor[1]=-1;
	for(auto i=2; i<=MAX_N; ++i)
		minFactor[i]=i;
	int sqrtn=int(sqrt(MAX_N));
	for(auto i=2; i<=sqrtn; ++i){
		if(minFactor[i]==i){
			for(auto j=i*i; j<=MAX_N; j+=i){
				if(minFactor[j]==j)
					minFactor[j]=i;
			}
		}
	}
}

int main()
{
	getMinFactor();
	int N;
	scanf("%d",&N);

	while(N>1){
		printf("%d\n",minFactor[N]);
		N /= minFactor[N];
	}
}
