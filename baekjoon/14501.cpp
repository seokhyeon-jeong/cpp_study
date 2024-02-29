#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)

int N, T[15], P[15], ret;

void solution(int day, int wage){
	if(day>=N){
		if(T[day]==1)
			wage+=P[day];
		ret=max(ret,wage);
		return;
	}

	for(auto next=day; next<N; ++next){
		if(next+T[day]>N)
			continue;
		solution(next+T[day], wage+P[day]);
	}
}

int main(void){
	cin >> N;
	FOR(i,N){
		cin >> T[i] >> P[i];
	}
	solution(0,0);

	cout << ret << endl;
}
