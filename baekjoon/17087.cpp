#include <bits/stdc++.h>
using namespace std;

int hide_and_seek(vector<int>& sisters)
{
	auto gcd=[=](int a, int b){
		if(a<b)
			swap(a,b);
		while(b!=0){
			a %= b;
			swap(a,b);
		}
		return a;
	};

	for(int i=1; i<sisters.size(); ++i){
		sisters[0] = gcd(sisters[0],sisters[i]);
	}
	return sisters[0];
}

int main(void)
{
	int N, S;
	vector<int> v(N);
	cin >> N >> S;
	for(int i=0; i<N; ++i){
		cin >> v[i];
		if(v[i]>S)
			v[i] = v[i]-S;
		else
			v[i] = S-v[i];
	}

	cout << hide_and_seek(v) << endl;
}

