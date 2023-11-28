#include <bits/stdc++.h>
using namespace std;

const string conversion(const string& s)
{
	int i=s.length()-1;
	string ret;	
	stack<char> stk;
	for(; i>=0; i-=3){
		int tmp = 1*(s[i]=='1') + 2*(s[i-1]=='1') + 4*(s[i-2]=='1');
		stk.push(tmp+'0');
	}
	while(!stk.empty()){
		ret.push_back(stk.top());
		stk.pop();
	}
	return ret;
}

int main()
{
	string s;
	cin >> s;
	cout << conversion(s) << endl;
}
