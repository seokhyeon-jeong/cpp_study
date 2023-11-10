#include <bits/stdc++.h>
using namespace std;

vector<int> the_number_of_alphabets(const string& S)
{
	vector<int> alphabets('z'-'a'+1);
	for(const char ch : S)
		++alphabets[ch-'a'];

	return alphabets;
}

int main()
{
	string S;
	cin >> S;
	auto ret=the_number_of_alphabets(S);
	for(auto ele : ret)
		cout << ele << ' ';
	cout << '\n';
}
