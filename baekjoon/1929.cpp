#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;

vector<uint> prime(uint M, uint N)
{
	vector<uint> ret{2,3};
	vector<uint>::iterator it;
	bool is_prime=true;	
	for(uint i=5; i<=N; i+=2)
	{
		for(it=ret.begin(); (*it)*(*it)<=i; ++it)
			if(i % (*it) == 0)
			{
				is_prime=false;
				break;
			}
		if(is_prime)
			ret.push_back(i);
		is_prime = true;
	}
	auto start=lower_bound(ret.begin(), ret.end(), M);

	return vector<uint>{start,ret.end()};
}
int main()
{
	uint M,N;
	cin >> M >> N;
	auto ret=prime(M,N);
	
	for(auto ele : ret)
		cout << ele << '\n';
}
