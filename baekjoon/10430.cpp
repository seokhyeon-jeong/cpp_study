#include <bits/stdc++.h>
using namespace std;

void remainders(int a, int b, int c)
{
	int ret1=(a+b)%c;
	int ret2=((a%c)+(b%c))%c;
	int ret3=(a*b)%c;
	int ret4=((a%c)*(b%c))%c;

	cout << ret1 << '\n' << ret2 <<'\n' << ret3 <<'\n' << ret4 << endl;
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	remainders(a, b, c);
}
