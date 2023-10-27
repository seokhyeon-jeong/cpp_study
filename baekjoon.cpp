#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string sentence;
	stack<char> stk;

	while(N--)
	{
		getline(cin, sentence);
		sentence += ' ';
		for(const char ch : sentence)
		{
			if(ch != ' ')
			{
				stk.push(ch);
				continue;
			}
			else
			{
				while(!stk.empty())
				{
					cout << stk.top();
					stk.pop();
				}
				cout << ' ';
			}
		}
		cout << '\n';
	}

}
