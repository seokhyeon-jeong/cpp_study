#include <bits/stdc++.h>
using namespace std;

const int zeros(const int n)
{
	int ret=0;

	for(int i=5; i<=n; i*=5)
	{
		ret += n/i;
	}
	return ret;
}

int main()
{
	int n,m;
	cin >> n >> m;
	cout << zeros(n)-zeros(n-m)-zeros(m) << endl;
}
