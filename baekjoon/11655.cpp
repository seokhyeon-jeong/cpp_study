#include <bits/stdc++.h>
using namespace std;

void ROT13(string& S)
{
	for(char& ch : S)
	{
		if(isupper(ch)) // ch=='A'~'Z';
		{
			ch += 13;
			ch -= ('Z'-'A'+1)*(static_cast<unsigned char>(ch)>'Z');
		}
		else if(islower(ch)) // ch=='a'~'z';
		{
			ch += 13;
			ch -= ('z'-'a'+1)*(static_cast<unsigned char>(ch)>'z');
		}
		else //ch=='0'~'9';
			;
	}
}

int main()
{
	string S;
	getline(cin, S);
	ROT13(S);
	cout << S << endl;
}
