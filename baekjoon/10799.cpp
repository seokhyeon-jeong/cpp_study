#include <bits/stdc++.h>
using namespace std;

int cut_bars(string& Bars)
{
	int numOfBars=0;
	int ret=0;
	bool isLazer=false;

	for(auto it=Bars.begin(); it!=Bars.end(); ++it)
	{
		if(*it=='(')
		{
			++numOfBars;
			isLazer=true;
		}
		else //*it==')'
		{
			if(isLazer)
			{
				--numOfBars;
				ret += numOfBars;	
			}
			else
			{
				++ret;
				--numOfBars;
			}
			isLazer=false;
		}
	}
	return ret;
}

int main()
{
	string s;
	cin >> s;

	cout << cut_bars(s) << endl;
}
