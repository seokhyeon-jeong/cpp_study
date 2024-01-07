#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000
#define MOD 9901

int cache[MAX_N+1][3];

int solution(const int N){
	for(int i=2; i<=N; ++i){
		cache[i][0]=(cache[i-1][0]+cache[i-1][1]+cache[i-1][2])%MOD;
		cache[i][1]=(cache[i-1][0]+cache[i-1][2])%MOD;
		cache[i][2]=(cache[i-1][0]+cache[i-1][1])%MOD;
	}
	return (cache[N][0]+cache[N][1]+cache[N][2])%MOD;
}

int main(void){
	cache[1][0]=1;
	cache[1][1]=1;
	cache[1][2]=1;

	int N;
	cin >> N;

	int ret=solution(N);
	cout << ret << endl;
}
