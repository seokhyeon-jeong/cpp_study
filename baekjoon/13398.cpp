#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000

int n, a[MAX_N], cache[MAX_N][2];

int solution(void){
	scanf("%d", &a[0]);
	cache[0][0]=cache[0][1]=a[0];
	int ret=a[0];

	for(int i=1; i<n; ++i){
		scanf("%d", &a[i]);

		cache[i][0]=max(cache[i-1][0]+a[i], a[i]);
		cache[i][1]=max(cache[i-1][0], cache[i-1][1]+a[i]);
		
		ret=max(ret, max(cache[i][0], cache[i][1]));
	}
	return ret;
}

int main(void){
	cin >> n;

	int ret=solution();

	cout << ret << endl;
}

