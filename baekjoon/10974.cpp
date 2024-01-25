#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)

int N, num[2][8], buf[8];

void solution(int len){
	if(len==N){
		FOR(i,N)
			cout << buf[i]+1 << ' ';
		cout << '\n';
		return;
	}

	FOR(i,N){
		if(num[1][i]==-1)
			continue;
		num[1][i]=-1;
		buf[len]=i;
		solution(len+1);
		num[1][i]=0;
	}
}

int main(void){
	cin >> N;
	FOR(i,N)
		num[0][i]=i;
	solution(0);
}
