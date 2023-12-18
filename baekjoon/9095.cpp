#include <bits/stdc++.h>
using namespace std;

int cache[11];

int plus123(int n){
	if(n<=0)
		return 0;
	int& ret=cache[n];
	if(ret!=-1)
		return ret;
	
	return ret=plus123(n-3)+plus123(n-2)+plus123(n-1);	
}

int main()
{
	memset(cache, -1, sizeof(cache));
	cache[1]=1;
	cache[2]=2;
	cache[3]=4;

	int n;
	cin >> n;
	cout << plus123(n) << endl;
}
