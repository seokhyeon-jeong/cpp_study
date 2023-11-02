#include <bits/stdc++.h>
using namespace std;

void josephus(int n, int k)
{
	list<int> survivors;
	for(int i=1; i<=n; ++i)
		survivors.push_back(i);
	auto kill=survivors.begin();
	cout << '<';
	while(survivors.size()>1)
	{
		for(int i=0; i<k-1; ++i)
		{
			++kill;
			if(kill==survivors.end())
				kill=survivors.begin();
		}
		cout << *kill << ", ";
		kill = survivors.erase(kill);
		if(kill==survivors.end())
			kill=survivors.begin();
	}
	cout << survivors.front() << '>' << endl;
}

int main()
{
	int N, K;
	cin >> N >> K;
	josephus(N,K);
}
