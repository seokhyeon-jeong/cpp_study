#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)

int N, a[10000];

bool solution(void){
	int i=N-1;
	while(i>0 && a[i-1]>a[i])
		--i;
	if(i<=0)
		return false;

	int j=N-1;
	while(a[i-1]>a[j])
		--j;
	swap(a[i-1],a[j]);
	for(int left=i, right=N-1; left!=right; ++left,--right)
		swap(a[left],a[right]);
	return true;
}

int main(void){
	cin >> N;
	FOR(i,N)
		scanf(" %d", &a[i]);
	if(solution())
		FOR(i,N)
			printf("%d ",a[i]);
	else
		putchar(-1);
}


