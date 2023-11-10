#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;

vector<uint> prime(uint M, uint N)
{
	vector<uint> ret{2};
	vector<uint>::iterator it;
	for(uint i=3; i<=N; i+=2)
	{
		for(it=ret.begin();it!=ret.end();++it)
			if(i%*it==0)
				break;
		if(it==ret.end())
			ret.push_back(i);
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
