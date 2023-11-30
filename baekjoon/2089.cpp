#include <bits/stdc++.h>


const std::string negativeBase(int n)
{
	std::string ret;
	while(n)
	{
		if(n%-2==0)
		{
			ret += "0";
			n /= -2;
		}
		else
		{
			ret += "1";
			n = (n-1)/(-2);
		}
	}
	std::reverse(ret.begin(), ret.end());
	return ret;
}
int main(void)
{
	int N;
	std::cin >> N;
	std::cout << negativeBase(N) << '\n';
}
