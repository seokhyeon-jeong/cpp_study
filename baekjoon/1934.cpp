#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;

uint gcd(uint a, uint b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}

uint lcm(uint a, uint b)
{
	return a/gcd(a,b)*b;
}

int main()
{
	uint T;
	cin >> T;
	while(T--)
	{
		uint a, b;
		cin >> a >> b;
		cout << lcm(a,b) << '\n';
	}
}
