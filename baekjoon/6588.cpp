#include <bits/stdc++.h>
using namespace std;

vector<int> generatePrime(const int n=1000001)
{
	vector<int> prime{2,3};
	vector<int> primeSearch(n);
	primeSearch[2]=1;
	primeSearch[3]=1;
	for(int i=5; i<=n; i+=2)
	{
		bool isPrime=true;
		for(int j=0; prime[j]*prime[j]<=i; ++j)
		{
			if(i%prime[j]==0)
			{
				isPrime=false;
				break;
			}
		}
		if(isPrime)
		{
			prime.push_back(i);
			primeSearch[i]=1;
		}

	}

	return primeSearch;
}

void Goldbach(const vector<int>& p, const int n)
{
	for(int i=3; i<=n; i+=2)
	{
		if(p[i]==1 && p[n-i]==1)
		{
			cout << n << " = " << i << " + " << n-i << '\n';
			return;
		}
	}
	puts("Goldbach's conjecture is wrong.");
}

int main()
{
	int n;
	auto p = generatePrime();
	while(true)
	{
		cin >> n;
		if(n==0)
			break;
		Goldbach(p, n);
	}
}
