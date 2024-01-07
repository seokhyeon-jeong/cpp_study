#include <bits/stdc++.h>
using namespace std;

int house[1001][3], N;

int solution(const int n){
	scanf("%d %d %d",&house[0][0], &house[0][1], &house[0][2]);

	for(int i=1; i<n; ++i){
		scanf("%d %d %d",&house[i][0], &house[i][1], &house[i][2]);

		house[i][0] += min(house[i-1][1],house[i-1][2]);
		house[i][1] += min(house[i-1][0],house[i-1][2]);
		house[i][2] += min(house[i-1][0],house[i-1][1]);
	}
	
	return min(house[n-1][0], min(house[n-1][1],house[n-1][2]));
}

int main(void){
	scanf("%d", &N);

	int ret=solution(N);
	cout << ret << endl;
}

