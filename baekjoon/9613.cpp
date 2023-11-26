#include <bits/stdc++.h>
using namespace std;

inline unsigned gcd(unsigned a, unsigned b)
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

unsigned sum_of_gcd(unsigned n)
{
	unsigned *num = new unsigned[n];
	unsigned ret=0;
	for(unsigned i=0; i<n; ++i)
		cin >> num[i];
	for(unsigned i=0; i<n; ++i)
	{
		for(unsigned j=i+1; j<n; ++j)
		{
			ret += gcd(num[i],num[j]);
		}
	}
	delete num;
	return ret;
}

int main(void)
{
	unsigned t;
	cin >> t;
	while(t--)
	{
		unsigned n;
		cin >> n;
		cout << sum_of_gcd(n) << '\n';
	}
}
