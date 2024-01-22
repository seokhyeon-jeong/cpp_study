#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0; i<(n); ++i)

int gcd(int a, int b){
	if(b==0)
		return a;
	return gcd(b, a%b);
}
int solution(int M, int N, int x, int y){
	int lcm=(M/gcd(M,N))*N;

	for(int i=x; i<=lcm; i+=M){
		int ny=i%N;
		if(ny==0)
			ny=N;
		if(ny==y)
			return i;
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

