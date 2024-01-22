#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0; i<(n); ++i)

int gcd(int a, int b){
	if(b==0)
		return a;
	return gcd(b, a%b);
}
int solution(int M, int N, int x, int y){
	int ret=1;
	int lcm=(M/gcd(M,N))*N;
	int year=1, month=1;

	FOR(i, lcm){
		++year;
		++month;
		year -= M*(year>M);
		month -= N*(month>N);
		++ret;
		if(year==x && month==y)
			return ret;
	}
	return -1;
}
int main(void){
	int T, M, N, x, y;
	cin >> T;
	while(T--){
		cin >> M >> N >> x >> y;
		cout << solution(M, N, x, y) << '\n';
	}
}

