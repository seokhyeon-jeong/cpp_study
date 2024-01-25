#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)

int N, num[2][8], buf[8];
int ret;

void solution(int len){
	if(len==N){
		int sum=0;
		for(auto i=1; i<N; ++i)
			sum += abs(buf[i]-buf[i-1]);
		ret=max(ret,sum);
		return;
	}

	FOR(i,N){
		if(num[1][i]==-1)
			continue;
		num[1][i]=-1;
		buf[len]=num[0][i];
		solution(len+1);
		num[1][i]=0;
	}
}
int main(void){
	cin >> N;
	FOR(i,N)
		cin >> num[0][i];
	solution(0);
	cout << ret << endl;
}
