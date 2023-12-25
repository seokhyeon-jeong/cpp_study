#include <bits/stdc++.h>
using namespace std;

int cache[91];

void solution(void){
	cache[1]=1;
	cache[2]=1;
	for(int i=3; i<=90; ++i)
		cache[i] = cache[i-1]+cache[i-2];
}

int main(){
	solution();
	int N;
	cin >> N;
	cout << cache[N] << endl;
}

