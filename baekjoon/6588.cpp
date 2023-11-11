#include <bits/stdc++.h>
using namespace std;

vector<int> generatePrimeNumbers(int n)
{
	vector<int> ret{2,3};

	for(int i=5; i<=n;i+=2)
	{
		bool isPrime=true;
		for(int prime=0; isPrime && ret[prime]*ret[prime]<=i; ++prime)
		{
			if(i % ret[prime] == 0)
				isPrime=false;
		}
		if(isPrime)
			ret.push_back(i);
	}

	return ret;
}

void Goldbach(vector<int>& primes, int n)
{
	int a=-1, b=-1;
	for(int i=0; i<primes.size(); ++i)
	{
		int target=n-primes[i];
		auto found=lower_bound(primes.begin(), primes.end(), target);

		if(target==*found)
		{
			a=target;
			b=primes[i];
			break;
		}
	}
	if(a!=-1)
		cout << n << " = " << a << " + " << b << '\n';
	else
		cout << "Goldbach's conjecture is wrong.\n";
}

int main()
{
	auto primes=generatePrimeNumbers(1000000);
	while(true)
	{
		int n;
		cin >> n;
		if(n==0)
			break;
		Goldbach(primes,n);
	}
}
	
