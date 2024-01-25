#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)

int N, M, input[7], buffer[7];

void solution(int depth){
	if(depth==M){
		FOR(i,depth)
			cout << buffer[i] << ' ';
		putchar('\n');
		return;
	}

	FOR(i,N){
		buffer[depth]=input[i];
		solution(depth+1);
	}
}

int main(void){
	cin >> N >> M;
	FOR(i, N)
		cin >> input[i];
	sort(input, input+N);
	solution(0);
}
