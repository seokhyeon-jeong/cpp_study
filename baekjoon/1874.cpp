#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, inputNumber, i=1;
	cin >> n;
	
	stack<int> stk;
	vector<char> ret;

	while(n--){
		cin >> inputNumber;
		if(stk.empty() || inputNumber>stk.top()){
			while(i <= inputNumber){
				stk.push(i);
				++i;
				ret.push_back('+');
			}
			ret.push_back('-');
			stk.pop();
			continue;
		}
		
		if(inputNumber < stk.top()){
			cout << "NO" << endl;
			return 0; // main will end.
		}
		else if(inputNumber == stk.top()){
			ret.push_back('-');
			stk.pop();
		}
		else //inputNumber > stk.top() was already checked at line 14.
			;
	}
	
	for(const char symbol : ret)
		cout << symbol << '\n';
}

