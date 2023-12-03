#include <bits/stdc++.h>
using namespace std;
#define INPUT_LIMIT 1000000

static vector<int> indexedPrime(INPUT_LIMIT+1,0);
static vector<int> prime;

void generatePrime()
{
	prime.push_back(2);
	prime.push_back(3);
	indexedPrime[2]=indexedPrime[3]=1;
	

	for(size_t num=5; num<=INPUT_LIMIT; num+=2)
	{
		bool isPrime=true;
		for(size_t i=0; i<prime.size() && prime[i]*prime[i]<=num; ++i)
		{
			if(num % prime[i] == 0)
			{
				isPrime=false;
				break;
			}
		}
		if(isPrime)
		{
			prime.push_back(num);
			indexedPrime[num]=1;
		}
	}
}

void goldbach(const int n)
{
	for(size_t i=1; i<prime.size(); ++i)
	{
		auto ele=prime[i];
		if(ele>=n)
		{
			cout << "Goldbach's conjecture is wrong.\n";
			break;
		}
		if(indexedPrime[ele]==1 && indexedPrime[n-ele]==1)
		{
			cout << n << " = " << ele << " + " << n-ele << '\n';
			break;
		}
	}
}
int main()
{
	generatePrime();
	int n;
	while(true)
	{
		cin >> n;
		if(n==0)
			break;
		goldbach(n);
	}
}
