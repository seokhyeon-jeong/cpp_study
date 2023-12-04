#include <bits/stdc++.h>

#define MAX_N 1000001

std::vector<bool> isPrime(MAX_N, true);
std::vector<int> prime;

void eratosthenes(const int n=MAX_N)
{
	isPrime[0]=isPrime[1]=false;

	auto sqrtn = int(std::sqrt(n));

	for(auto i=2; i<=sqrtn; ++i)
	{
		if(isPrime[i])
		{
			prime.push_back(i);
			for(auto j=i*i; j<=n; j+=i)
				isPrime[j]=false;
		}
	}
}

void goldbach(const int n)
{
	for(auto ele : prime)
	{
		if(ele>=n)
			break;
		if(isPrime[n-ele])
		{
			std::cout << n << " = " << ele << " + " << n-ele << '\n';
			return;
		}
	}
	std::cout << "Goldbach's conjecture is wrong.\n";
}

int main()
{
	eratosthenes();
	while(true)
	{
		int n;
		std::cin >> n;
		if(n==0)
			break;
		goldbach(n);
	}
}
