#include <bits/stdc++.h>
using namespace std;

int wine[10001], cache[10001][3];
int n;

int solution(int pn){
	cache[0][0]=0;
	cache[0][1]=wine[0];
	cache[1][0]=cache[0][1];
	cache[1][1]=wine[1];
	cache[1][2]=wine[0]+wine[1];

	for(int i=2; i<pn; ++i){
		cache[i][0]=max(cache[i-1][0],max(cache[i-1][1],cache[i-1][2]));
		cache[i][1]=cache[i-1][0]+wine[i];
		cache[i][2]=cache[i-1][1]+wine[i];
	}

	return max(cache[pn-1][0],max(cache[pn-1][1],cache[pn-1][2]));
}

int main(void){
	cin >> n;
	for(int i=0; i<n; ++i)
		scanf("%d",&wine[i]);
	printf("%d\n",solution(n));
}
