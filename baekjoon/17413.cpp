#include <bits/stdc++.h>
using namespace std;

void reverseWord(string& s)
{
	auto it=s.begin();
	string ret;

	while(it!=s.end())
	{
		//tag
		if(*it=='<')
		{
			while(*it!='>')
				ret.push_back(*it++);
		//ret += "<...", I'd put '>' in the end;
			ret.push_back(*it++);
			continue;
		}
		stack<char> stk;
		while(it!=s.end() && *it!=' ' && *it!='<')
			stk.push(*it++);
		while(!stk.empty())
		{
			ret.push_back(stk.top());
			stk.pop();
		}
		if(*it==' ')
			ret.push_back(*it++);
	}

	for(const char ch:ret)
		cout << ch;
	cout << '\n';
}

int main()
{
	string S;
	getline(cin, S);
	reverseWord(S);
}
		
