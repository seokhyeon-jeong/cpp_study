#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)

int N, M, buf[8];

void solution(int start, int depth){
	if(depth==M){
		FOR(i,M)
			cout << buf[i]+1 << ' ';
		cout << endl;
		return;
	}
	
	for(auto next=start; next<N; ++next){
		buf[depth]=next;
		solution(next+1, depth+1);
	}
}

int main(void){
	cin >> N >> M;
	solution(0,0);
}
