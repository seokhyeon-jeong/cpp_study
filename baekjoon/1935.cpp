#include <bits/stdc++.h>
using namespace std;

float postfix(int N)
{
	string input;
	cin >> input;

	vector<float> numbers(N);
	for(int i=0; i<N; ++i)
		cin >> numbers[i];

	stack<float> stk;
	string op{"+-*/"};

	for(char ch : input)
	{
		if(op.find(ch)==string::npos)
		{
			stk.push(numbers[ch-'A']);
			continue;
		}

		auto a=stk.top();
		stk.pop();
		auto b=stk.top();
		stk.pop();
		
		if(ch=='+')
			b += a;
		else if(ch=='-')
			b -= a;
		else if(ch=='*')
			b *= a;
		else
			b /= a;

		stk.push(b);
	}

	return stk.top();
}

int main()
{
	int N;
	cin >> N;
	auto ret=postfix(N);
	cout << fixed;
	cout.precision(2);
	cout << ret << endl;
}
