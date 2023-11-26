#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
inline ull gcd(ull a, ull b)
{
	if(a<b)
		swap(a,b);
	while(b!=0)
	{
		a %= b;
		swap(a,b);
	}
	return a;
}

ull sum_of_gcd(ull n)
{
	ull *num = new ull[n];
	ull ret=0;
	for(ull i=0; i<n; ++i)
		cin >> num[i];
	for(ull i=0; i<n; ++i)
	{
		for(ull j=i+1; j<n; ++j)
		{
			ret += gcd(num[i],num[j]);
		}
	}
	delete num;
	return ret;
}

int main(void)
{
	ull t;
	cin >> t;
	while(t--)
	{
		ull n;
		cin >> n;
		cout << sum_of_gcd(n) << '\n';
	}
}
