#include <bits/stdc++.h>
using namespace std;

void postfix(const string& expression)
{
	stack<char> stk;
	string op{"+-*/()"};

	for(const char ch : expression)
	{
		if(op.find(ch)==string::npos)
			cout << ch;
		else if(ch=='(')
			stk.push(ch);
		else if(ch==')')
		{
			while(!stk.empty() && stk.top()!='(')
			{
				cout << stk.top();
				stk.pop();
			}
			stk.pop();
		}
		else if(ch=='*' || ch=='/')
		{
			while(!stk.empty() && (stk.top() == '*' || stk.top()=='/'))
			{
				cout << stk.top();
				stk.pop();
			}
			stk.push(ch);
		}
		else if(ch=='+' || ch=='-')
		{
			while(!stk.empty() && stk.top()!='(')
			{
				cout << stk.top();
				stk.pop();
			}
			stk.push(ch);
		}
		else
			;
	}
	while(!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}
	cout << '\n';
}

int main()
{
	string iString;
	cin >> iString;
	postfix(iString);
}
		
