#include <bits/stdc++.h>
using namespace std;

vector<int> cnt(1000001);

vector<int> getArray(int N)
{
	vector<int> ret(N);
	for(int i=0; i<N; ++i)
	{
		cin >> ret[i];
		++cnt[ret[i]];
	}
	return ret;
}

vector<int> NGF(vector<int>& A)
{
	stack<int> stk;
	vector<int> ret(A.size());

	for(int i=A.size()-1; i>=0; --i)
	{
		while(!stk.empty() && cnt[stk.top()]<=cnt[A[i]])
			stk.pop();
		
		if(stk.empty())
			ret[i]=-1;
		else
			ret[i]=stk.top();

		stk.push(A[i]);
	}
	return ret;
}

int main()
{
	int N;
	cin >> N;
	auto A = getArray(N);
	auto ret = NGF(A);
	for(auto ele : ret)
		cout << ele << ' ';
	cout << '\n';
}
