#include <bits/stdc++.h>
using namespace std;

int house[1001][3], cost[3];

int main(void){
	int N;
	scanf("%d",&N);
	
	for(int i=1; i<=N; ++i){
		scanf("%d %d %d",&cost[0],&cost[1],&cost[2]);
		house[i][0]=min(house[i-1][1],house[i-1][2])+cost[0];
		house[i][1]=min(house[i-1][0],house[i-1][1])+cost[1];
		house[i][2]=min(house[i-1][1],house[i-1][2])+cost[2];
	}

	N=min(house[N][0],min(house[N][1],house[N][2]));
	printf("%d\n",N);
}
