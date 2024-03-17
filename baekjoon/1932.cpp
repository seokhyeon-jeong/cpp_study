#include <bits/stdc++.h>
using namespace std;

int n, triangle[501][501], cache[501][501];

int solution(int n){
	cache[0][0]=triangle[0][0];

	for(int y=1; y<n; ++y){
		cache[y][0]=cache[y-1][0]+triangle[y][0];
		for(int x=1; x<y; ++x)
			cache[y][x]=max(cache[y-1][x-1],cache[y-1][x])+triangle[y][x];
		cache[y][y]=cache[y-1][y-1]+triangle[y][y];
	}
	int ret=-1;
	for(int x=0; x<n; ++x)
		if(cache[n-1][x]>ret)
			ret=cache[n-1][x];
	return ret;
}

int main(void){
	cin >> n;
	for(int y=0; y<n; ++y)
		for(int x=0; x<=y; ++x)
			scanf("%d",&triangle[y][x]);
	cout << solution(n) << endl;
}
