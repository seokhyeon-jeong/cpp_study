#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100001

int cache[MAX_N];

void solution(void){
	cache[1]=1;
	cache[2]=2;
	cache[3]=3;
	cache[4]=1;

	for(int n=5; n<MAX_N; ++n){
		int sqrtn=int(sqrt(n));
		cache[n]=1+cache[n-sqrtn*sqrtn];
	}
}

int main(void){
	int n;
	solution();
	scanf("%d", &n);
	printf("%d\n", cache[n]);
}
