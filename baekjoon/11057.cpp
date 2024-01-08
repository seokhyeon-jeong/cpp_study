#include <bits/stdc++.h>
using namespace std;

#define MOD 10007
#define MAX_N 1001

int cache[MAX_N][10];

int solution(const int n){
	for(int i=2; i<=n; ++i)
		for(int j=0; j<=9; ++j)
			for(int k=j; k<=9; ++k)
				cache[i][j]=(cache[i][j]+cache[i-1][k])%MOD;
	int ret=0;
	for(int i=0; i<=9; ++i)
		ret = (ret+cache[n][i])%MOD;
	return ret;
}

int main(void){
	for(int i=0; i<=9; ++i)
		cache[1][i]=1;

	cin >> cache[0][0];
	int ret=solution(cache[0][0]);
	cout << ret << endl;
}

