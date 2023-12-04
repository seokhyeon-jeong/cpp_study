#include <bits/stdc++.h>

#define MAX_N 1000000

std::vector<bool> isPrime(MAX_N, true);

void eratosthenes(const int n=MAX_N)
{
	isPrime[0]=isPrime[1]=false;

	auto sqrtn = int(std::sqrt(n));

	for(auto i=3; i<=sqrtn; i+=2)
	{
		if(isPrime[i])
		{
			for(auto j=i*i; j<=n; j+=i)
				isPrime[j]=false;
		}
	}
}

void goldbach(const int n)
{
	for(auto i=3; i<=n; i+=2)
	{
		if(isPrime[i] && isPrime[n-i])
		{
			std::cout << n << " = " << i << " + " << n-i << '\n';
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
