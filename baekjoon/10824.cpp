#include <bits/stdc++.h>
using namespace std;

int fourNumbers(int A, int B, int C, int D)
{
	int copyB(B), copyD(D);
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
	int A,B,C,D;
	cin >> A >> B >> C >> D;
	cout << fourNumbers(A,B,C,D) << endl;	
}
