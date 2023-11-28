#include <bits/stdc++.h>
using namespace std;

string conversion(const string& s)
{
	string ret;
	string piece{"000"};
	for(const char ch : s)
	{
		unsigned num = ch - '0';
		for(auto it=piece.rbegin(); it!=piece.rend(); ++it)
		{
			*it = (num&0x1) + '0';
			num >>= 1;
		}
		ret += piece;
	}
	if(ret[0]=='0' && ret[1]=='0')
		return string{ret.begin()+2,ret.end()};
	else if(ret[0]=='0')
		return string{ret.begin()+1,ret.end()};
	return ret;
}

int main(void)
{
	string s;
	cin >> s;
	cout << conversion(s) << endl;
}
