#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)

int N, M, input[2][7], buf[7];

void solution(int start,int depth){
	if(depth==M){
		FOR(i,depth)
			cout << buf[i] << ' ';
		cout << '\n';
		return;
	}
	int flag=0;	
	FOR(i,N){
		if(input[0][i]==flag)
			continue;
		input[1][i]=-1;
		flag=input[0][i];
		buf[depth]=input[0][i];
		solution(i, depth+1);
		input[1][i]=0;
	}
}

int main(void){
	cin >> N >> M;
	FOR(i,N)
		cin >> input[0][i];
	sort(input[0], input[0]+N);
	solution(0,0);
}

