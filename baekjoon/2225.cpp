#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000000

int N, K, cache[201][201];

int solution(int n, int k){
	int& ret=cache[n][k];
	if(ret!=-1)
		return ret;
	if(k==0)
		return ret=0;
	if(k==1)
		return ret=1;
	if(k==2)
		return ret=n+1;
	if(n==0)
		return ret=1;
	if(n==1)
		return ret=k;
	ret=0;
	for(int i=0; i<=n; ++i){
		ret=((long long)ret+solution(n-i,k-1))%MOD;
	}
	return ret;
}

int main(void){
	memset(cache, -1, sizeof(cache));
	cin >> N >> K;
	int ret=solution(N, K);
	cout << ret << endl;
}
