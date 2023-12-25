#include <bits/stdc++.h>
using namespace std;

int cache[91][2];

void solution(void){
	cache[1][1]=1;
	cache[2][0]=1;
	cache[2][1]=0;
	cache[3][1]=cache[2][0];
	cache[3][0]=cache[2][1]+cache[2][0];

	for(int i=4; i<=90; ++i){
		cache[i][1]=cache[i-1][0];
		cache[i][0]=cache[i-1][1]+cache[i-1][0];
	}
}

int main(){
	solution();
	int N;
	cin >> N;
	cout << cache[N][0]+cache[N][1] << endl;
}
