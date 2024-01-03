#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000000
#define MOD 1000000009
int cache[MAX_N+1];

void solution(void){
	cache[0]=cache[1]=1;
	cache[2]=2;

	for(int i=3; i<=MAX_N; ++i)
		cache[i]=((long long)cache[i-1]+cache[i-2]+cache[i-3])%MOD;
}

int main(void){
	solution();
	int T;
	scanf("%d",&T);
	while(T--){
		int tmp;
		scanf("%d",&tmp);
		printf("%d\n",cache[tmp]);
	}
}
