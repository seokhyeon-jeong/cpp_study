#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)

int L, C;
char alpa[15], buf[15];

void solution(int start, int depth){
	if(depth==L){
		string vowels{"aeiou"};
		int cnt=0;
		FOR(i,L){
			cnt += (vowels.find(buf[i])!=string::npos);
		}
		if(cnt>=1 && (L-cnt)>=2){
			FOR(i,L)
				cout << buf[i];
			cout << '\n';
		}
		return;
	}

	for(auto next=start; next<C; ++next){
		buf[depth]=alpa[next];		
		solution(next+1, depth+1);
	}
}
int main(void){
	cin >> L >> C;
	FOR(i, C)
		cin >> alpa[i];
	sort(alpa, alpa+C);
	solution(0,0);
}
