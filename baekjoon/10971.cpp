#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)

int N, W[10][10], visited[10];
int ret=987654321;

void solution(int begin, int city, int cnt, int cost){
	if(cnt==N-1){
		if(W[city][begin]==0)
			return;
		ret=min(ret, cost+W[city][begin]);
		return;
	}

	FOR(nextCity, N){
		if(visited[nextCity]==1)
			continue;
		if(W[city][nextCity]==0)
			continue;
		if(cost+W[city][nextCity]>ret)
			continue;
		visited[nextCity]=1;
		solution(begin, nextCity, cnt+1, cost+W[city][nextCity]);
		visited[nextCity]=0;
	}
}

int main(void){
	cin >> N;
	FOR(y,N)
		FOR(x,N)
			cin >> W[y][x];
	FOR(i, N){
		memset(visited, 0, sizeof(visited));
		visited[i]=1;
		solution(i, 0, 0, 0);
	}
	cout << ret << endl;

}

