#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000
int n, arr[MAX_N], cache[MAX_N];

int maxSum(){
	int ret=arr[0];
	cache[0]=arr[0];
	for(int i=1; i<n; ++i){
		cache[i]=max(cache[i-1]+arr[i], arr[i]);
		ret=max(cache[i], ret);
	}
	return ret;
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; ++i){
			scanf("%d",&arr[i]);
	}
	printf("%d\n", maxSum());
}
