#include <bits/stdc++.h>
using namespace std;

int n, triangle[501][501], cache[501][501];

int solution(int y, int x){
	if(y==n-1)
		return triangle[y][x];
	int& ret=cache[y][x];
	if(ret!=-1)
		return ret;
	
	return max(solution(y+1,x),solution(y+1, x+1))+triangle[y][x];
}

int main(void){
	memset(cache, -1, sizeof(cache));
	cin >> n;
	for(int i=0; i<n; ++i){
		for(int j=0; j<i+1; ++j){
			cin >> triangle[i][j];
		}
	}
	n=solution(0,0);
	cout << n << endl;
}
