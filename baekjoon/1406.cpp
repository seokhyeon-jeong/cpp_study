#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	int numberOfOp;
	stack<char> left, right;

	getline(cin, s);
	cin >> numberOfOp;
	cin.ignore();
	cin.clear();

	if(s.empty())
		return 0;

	for(const char ch : s)
		left.push(ch);

	while(numberOfOp--)
	{
		getline(cin, s);
		if(s.front()=='L')
		{
			if(left.empty())
				continue;
			right.push(left.top());
			left.pop();
		}
		else if(s.front()=='D')
		{
			if(right.empty())
				continue;
			left.push(right.top());
			right.pop();
		}
		else if(s.front()=='B')
		{
			if(left.empty())
				continue;
			left.pop();
		}
		else if(s.front()=='P')
		{
			left.push(s.back());
		}
		else
			;
	}
	
	while(!left.empty())
	{
		right.push(left.top());
		left.pop();
	}
	while(!right.empty())
	{
		cout << right.top();
		right.pop();
	}
}
