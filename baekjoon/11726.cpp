#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000
#define MOD 10007

int cache[MAX_N+1];

int tiling(int n){
	if(n<=2)
		return n;
	int& ret=cache[n];
	if(ret!=-1)
		return ret;
	
	return ret=(tiling(n-1)+tiling(n-2))%MOD;
}

int main()
{
	memset(cache, -1, sizeof(cache));
	int n;
	cin >> n;
	cout << tiling(n) << endl;
}
