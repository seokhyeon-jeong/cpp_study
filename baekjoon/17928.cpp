#include <bits/stdc++.h>
using namespace std;

auto getInput(int n)
{
	vector<int> ret(n);
	for(int i=0; i<n; ++i)
		cin >> ret[i];
	return ret;
}

auto NGE(const vector<int>& a)
{
	stack<int> stk;
	vector<int> ret(a.size());

	for(int i=a.size()-1; i>=0; --i)
	{
		while(!stk.empty() && stk.top()<a[i])
			stk.pop();
		if(stk.empty())
			ret[i]=-1;
		else
			ret[i]=stk.top();
		stk.push(a[i]);
	}
	return ret;
}

int main()
{
	int N;
	cin >> N;
	auto v = getInput(N);
	auto ret = NGE(v);
	for(auto ele : ret)
		cout << ele << ' ';
	cout << '\n';
}
