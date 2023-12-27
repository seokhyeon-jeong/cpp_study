#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100001

int cache[MAX_N];

void solution(void){
	for(int i=1; i<MAX_N; ++i)
		cache[i] = i;

	for(int i=1; i<MAX_N; ++i){
		for(int j=1; j*j<=i; ++j){
			cache[i] = min(cache[i], cache[i-j*j]+1);
		}
	}
}

int main(void){
	int n;
	solution();
	scanf("%d", &n);
	printf("%d\n", cache[n]);
}
