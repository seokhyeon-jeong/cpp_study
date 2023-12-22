#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000001

int cache[MAX_N];
int N;

int makeOne(int n){
	for(int i=4; i<=n; ++i){
		cache[i]=min(cache[i],makeOne(n-1)+1);
		if(i%2==0)
			cache[i]=min(cache[i],1+makeOne(n/2));
		if(i%3==0)
			cache[i]=min(cache[i],1+makeOne(n/3));
	}
	return cache[n];
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cache[1]=0;
	cache[2]=cache[3]=1;

	scanf("%d",&N);
	printf("%d\n",makeOne(N));
}
