#include <bits/stdc++.h>
using namespace std;

int sticker[100001][2], cache[100001][3], N;

int solution(const int n){
	cache[0][0]=0;
	cache[0][1]=sticker[0][0];
	cache[0][2]=sticker[0][1];

	for(int i=1; i<=n; ++i){
		cache[i][0]=max(cache[i-1][0], max(cache[i-1][1],cache[i-1][2]));
		cache[i][1]=max(cache[i-1][0],cache[i-1][2])+sticker[i][0];
		cache[i][2]=max(cache[i-1][0],cache[i-1][1])+sticker[i][1];
	}

	return max(cache[n][1],cache[n][2]);
}

int main(void){
	int T;
	cin >> T;
	while(T--){
		cin >> N;
		for(int i=0; i<N; ++i)
			scanf("%d",&sticker[i][0]);
		for(int i=0; i<N; ++i)
			scanf("%d",&sticker[i][1]);

		printf("%d\n", solution(N));
	}
}
