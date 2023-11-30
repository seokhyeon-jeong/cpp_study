#include <bits/stdc++.h>
using namespace std;
#define INPUT_LIMIT 1000000

static vector<bool> prime(INPUT_LIMIT+1,false);

void generate_prime(void)
{
	prime[2]=prime[3]=prime[5]=true;
	for(int i=7; i<=INPUT_LIMIT; i+=2)
	{
		int j=3;
		for(; j*j<=i; j+=2)
		{
			if(prime[j] && i%j==0)
			{
				prime[1]=true;
				break;
			}
		}
		if(prime[1])
		{
			prime[1]=false;
		}
		else
		{
			prime[i]=true;
		}
	}
}
const int goldbach(const int n)
{
	int ret=0;
	int duplicate=0;
	for(int i=3; i<=n; i+=2)
	{
		ret += (prime[i] && prime[n-i]);
		duplicate += (i == (n-i));
	}
	ret -= duplicate;
	ret >>= 1;
	ret += duplicate;
	return ret;
}

int main(void)
{
	generate_prime();
	int T, N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		cout << goldbach(N) << '\n';
	}
	return 0;
}

