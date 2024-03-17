#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)

int k, S[13], buf[6];
void solution(int start, int cnt){
	if(cnt==6){
		FOR(i,6)
			printf("%d ", buf[i]);
		putchar('\n');
		return;
	}
	for(auto next=start; next<k; ++next){
		buf[cnt]=S[next];
		solution(next+1, cnt+1);
	}
}

int main(void){
	while(true){
		cin >> k;
		if(k==0)
			break;
		FOR(i,k)
			cin >> S[i];
		solution(0,0);
	}
}
