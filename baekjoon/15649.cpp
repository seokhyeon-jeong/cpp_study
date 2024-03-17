#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0; i<(n); ++i)

int N, M;
int used[8], ret[8];

void solution(int depth){
	if(depth==M){
		for(int i=0; i<M; ++i)
			cout << ret[i]+1 << ' ';
		cout << '\n';
		return;
	}

	for(int i=0; i<N; ++i){
		if(used[i]==1)
			continue;
		used[i]=1;
		ret[depth]=i;
		solution(depth+1);
		used[i]=0;
	}
}
int main(void){
	cin >> N >> M;
	solution(0);
}
