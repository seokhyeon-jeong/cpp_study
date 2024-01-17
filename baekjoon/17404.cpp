#include <bits/stdc++.h>
using namespace std;

int N, house[1000][3], cache[1000][3];

int solution(void){
	int ret=987654321;
	int r, g, b;
	for(int color=0; color<3; ++color){
		cache[0][0]=house[0][0];
		cache[0][1]=house[0][1];
		cache[0][2]=house[0][2];

		if(color==0){
			r=0; g=1; b=2;
		}
		if(color==1){
			r=1; g=2; b=0;
		}
		if(color==2){
			r=2; g=0; b=1;
		}
		int i=1;	
		cache[i][r]=987654321;
		cache[i][g]=cache[i-1][r]+house[i][g];
		cache[i][b]=cache[i-1][r]+house[i][b];
		++i;
		for(; i<N-1; ++i){
			cache[i][r]=min(cache[i-1][g],cache[i-1][b])+house[i][r];
			cache[i][g]=min(cache[i-1][r],cache[i-1][b])+house[i][g];
			cache[i][b]=min(cache[i-1][r],cache[i-1][g])+house[i][b];
		}
		cache[i][r]=987654321;
		cache[i][g]=min(cache[i-1][r],cache[i-1][b])+house[i][g];
		cache[i][b]=min(cache[i-1][r],cache[i-1][g])+house[i][b];
		cache[N-1][r]=min(cache[N-1][r],min(cache[N-1][g],cache[N-1][b]));
		ret=min(ret, cache[N-1][r]);
	}
	return ret;
}

int main(void){
	cin >> N;
	for(int i=0; i<N; ++i)
		scanf("%d %d %d", &house[i][0], &house[i][1], &house[i][2]);
	int ret=solution();
	cout << ret << endl;
}
	
