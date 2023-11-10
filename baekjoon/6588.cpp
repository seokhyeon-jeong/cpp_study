#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;

static vector<uint> prime{2,3,5,7};

void pushPrime(uint target)
{
	bool isPrime=true;

	for(uint n=prime.back()+1; n<=target; ++n)
	{
		for(uint i=0; prime[i]*prime[i]<=n; ++i)
		{
			if(n%prime[i]==0)
			{
				isPrime=false;
				break;
			}
		}
		if(isPrime)
			prime.push_back(n);
		isPrime=true;
	}
}

pair<int,int> Goldbach(uint n)
{
	if(prime.back()<n)
		pushPrime(n);

	set<uint> hashTable;
	uint maxDiff=0;
	pair<uint,uint> ret{-1,-1};
	for(uint i=0; i<prime.size(); ++i)
	{
		uint target=n-prime[i];
		auto found=hashTable.find(target);
		if(found==hashTable.end())
			hashTable.insert(prime[i]);
		else
		{
			if(abs(static_cast<int>(*found-prime[i]))>maxDiff)
			{
				ret = make_pair(*found,prime[i]);
				maxDiff=abs(static_cast<int>(*found-prime[i]));
			}
		}
	}
	return ret;
}

int main()
{
	uint n;
	while(true)
	{
		cin >> n;
		if(n==0)
			break;
		auto ret=Goldbach(n);
		if(ret==pair{-1,-1})
			cout << "Goldbach's conjecture is wrong.\n";
		else
			cout << n << " = " << ret.first << " + " << ret.second << '\n';
	}
}
