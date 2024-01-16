#include <bits/stdc++.h>
using namespace std;

int N, house[1000][3], cache[1000][3];

int solution(void){
	scanf("%d %d %d",&house[0][0],&house[0][1],&house[0][2]);
	cache[0][0]=house[0][0];
	cache[0][1]=house[0][1];
	cache[0][2]=house[0][2];

	for(int i=1; i<N; ++i){
		scanf("%d %d %d", &house[i][0],&house[i][1],&house[i][2]);

		cache[i][0]=min(cache[i-1][1],cache[i-1][2])+house[i][0];
		cache[i][1]=min(cache[i-1][0],cache[i-1][2])+house[i][1];
		cache[i][2]=min(cache[i-1][0],cache[i-1][1])+house[i][2];
	}

	return min(cache[N-1][0],min(cache[N-1][1],cache[N-1][2]));
}

int main(void){
	cin >> N;
	int ret=solution();
	cout << ret << endl;
}
