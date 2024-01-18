#include <bits/stdc++.h>
using namespace std;

int solution(int e, int s, int m){
	int ret=0;

	while(e!=0 || s!=0 || m!=0){
		if(e<=0)
			e += 15;
		if(s<=0)
			s += 28;
		if(m<=0)
			m += 19;
		--e;
		--s;
		--m;
		++ret;
	}

	return ret;
}

int main(void){
	int E, S, M;
	cin >> E >> S >> M;
	int ret=solution(E,S,M);
	cout << ret << endl;
}
