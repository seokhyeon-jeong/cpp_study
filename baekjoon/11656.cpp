#include <bits/stdc++.h>
using namespace std;

vector<string> suffixSort(const string& s)
{
	vector<string> ret;
	for(int i=0; i<s.length(); ++i)
		ret.emplace_back(s.substr(i));
	sort(ret.begin(), ret.end());
	return ret;
}
int main()
{
	string s;
	cin >> s;
	auto ret=suffixSort(s);
	for(auto ele : ret)
		cout << ele << '\n';
}
