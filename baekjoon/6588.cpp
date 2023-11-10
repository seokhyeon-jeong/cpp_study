#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;

static set<uint> prime;

void pushPrime(uint target)
{
	bool isPrime=true;

	for(uint n=*prime.rbegin()+2; n<=target; n+=2)
	{
		for(auto it=prime.begin(); (*it)*(*it)<=n; ++it)
		{
			if(n%*it==0)
			{
				isPrime=false;
				break;
			}
		}
		if(isPrime)
			prime.insert(n);
		isPrime=true;
	}
}

pair<int,int> Goldbach(uint n)
{
	if(*prime.rbegin()<n)
		pushPrime(n);

	uint maxDiff=0;
	pair<uint,uint> ret{-1,-1};
	for(auto it=prime.begin();it!=prime.end(); ++it)
	{
		uint target=n-*it;
		auto found=prime.find(target);
		if(found!=prime.end())
		{
			if(abs(static_cast<int>(*found-*it))>maxDiff)
			{
				ret = make_pair(*found,*it);
				maxDiff=abs(static_cast<int>(*found-*it));
			}
		}
	}
	return ret;
}

int main()
{
	uint n;
	prime.insert(2);
	prime.insert(3);
	prime.insert(5);
	prime.insert(7);
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
