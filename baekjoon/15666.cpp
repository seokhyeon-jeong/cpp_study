#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)

int N, M, input[2][8], buf[8];

void solution(int start,int depth){
	if(depth==M){
		FOR(i,depth)
			cout << buf[i] << ' ';
		cout << '\n';
		return;
	}
	int flag=0;	
	for(int i=start; i<N; ++i){
		if(input[0][i]==flag)
			continue;
		flag=input[0][i];
		buf[depth]=input[0][i];
		solution(i, depth+1);
	}
}

int main(void){
	cin >> N >> M;
	FOR(i,N)
		cin >> input[0][i];
	sort(input[0], input[0]+N);
	solution(0,0);
}

