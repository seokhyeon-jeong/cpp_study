#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull fourNumbers(ull A, ull B, ull C, ull D)
{
	ull copyB(B), copyD(D);
	while(copyB)
	{
		A *= 10;
		copyB /= 10;
	}
	while(copyD)
	{
		C *= 10;
		copyD /= 10;
	}
	A += B;
	C += D;
	return A+C;
}

int main()
{
	ull A,B,C,D;
	cin >> A >> B >> C >> D;
	cout << fourNumbers(A,B,C,D) << endl;	
}
