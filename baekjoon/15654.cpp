#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)

int N, M, input[2][8], buffer[8];

void solution(int depth){
	if(depth==M){
		FOR(i,depth)
			cout << buffer[i] << ' ';
		cout << '\n';
		return; 
	}

	FOR(i,N){
		if(input[1][i]==-1)
			continue;
		input[1][i]=-1;
		buffer[depth]=input[0][i];
		solution(depth+1);
		input[1][i]=0;
	}
}

int main(void){
	cin >> N >> M;
	FOR(i,N)
		cin >> input[0][i];
	sort(input[0],input[0]+N);
	solution(0);
}
