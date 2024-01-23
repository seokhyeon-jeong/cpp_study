#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)

int N, M, visited[7], buffer[7];

void solution(int depth){
	if(depth==M){
		FOR(i,depth)
			printf("%d ",buffer[i]+1);
		putchar('\n');
		return;
	}

	FOR(i,N){
		if(visited[i]==M)
			continue;
		++visited[i];
		buffer[depth]=i;
		solution(depth+1);
		--visited[i];
	}
}


int main(void){
	cin >> N >> M;
	solution(0);
}
