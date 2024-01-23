#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)

int N, M, visited[8], buffer[8];

void solution(int start, int depth){
	if(depth==M){
		FOR(i,depth)
			printf("%d ",buffer[i]+1);
		putchar('\n');
		return;
	}

	for(auto i=start; i<N; ++i){
		buffer[depth]=i;
		solution(i, depth+1);
	}
}
int main(void){
	cin >> N >> M;
	solution(0, 0);
}
