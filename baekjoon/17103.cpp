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

int goldbach(const int N)
{
	int duplicated=0;
	int ret=0;

	for(size_t i=0; prime[i]<N && i<prime.size(); ++i)
	{
		auto partition=prime[i];
		if(indexedPrime[partition]==1 && indexedPrime[N-partition]==1)
		{
			duplicated += (partition == (N-partition));
			ret += 1*(i != (N-partition));
		}
	}
	ret >>= 1;
	
	return ret+duplicated;
}

int main()
{
	generatePrime();
	int T, N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		cout << goldbach(N) << '\n';
	}
}

