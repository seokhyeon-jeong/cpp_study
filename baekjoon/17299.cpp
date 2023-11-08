#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> getArray(int N)
{
	map<int,int> m;
	vector<pair<int,int>> ret;

	for(int i=0; i<N; ++i)
	{
		int tmp;
		cin >> tmp;
		if(m.find(tmp)==m.end())
			m[tmp]=1;
		else
			++m[tmp];
		ret.push_back({tmp,0});
	}
	for(auto& ele : ret)
		ele.second = m[ele.first];

	return ret;
}

vector<int> NGF(vector<pair<int,int>>& v)
{
	stack<pair<int,int>> stk;
	vector<int> ret(v.size());

	for(int i=v.size()-1; i>=0; --i)
	{
		while(!stk.empty() && stk.top().second<=v[i].second)
			stk.pop();

		if(stk.empty())
			ret[i]=-1;
		else
			ret[i]=stk.top().first;
		stk.push(v[i]);
	}
	return ret;
}

int main()
{
	int N;
	cin >> N;
	auto v = getArray(N);
	auto ret = NGF(v);
	for(auto ele : ret)
		cout << ele << ' ';
	cout << '\n';
}
