#include <bits/stdc++.h>
using namespace std;

vector<int> analyze_string(const string& s)
{
	vector<int> ret(4);
	for(const char ch : s)
	{
		if(ch>='a'&&ch<='z')
			++ret[0];
		else if(ch>='A'&&ch<='Z')
			++ret[1];
		else if(ch>='0'&&ch<='9')
			++ret[2];
		else if(ch==' ')
			++ret[3];
		else
			;
	}
	return ret;
}

int main()
{
	string s;
	while(getline(cin,s))
	{
		auto ret=analyze_string(s);
		for(auto ele : ret)
			cout << ele  << ' ';
		cout << '\n';
	}
}
