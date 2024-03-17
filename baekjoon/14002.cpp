#include <bits/stdc++.h>
using namespace std;

int arr[1001], cache[1002];
int n;

int lis(int start){
	int& ret=cache[start+1];
	if(ret!=-1)
		return ret;
	
	ret=1;
	for(int next=start+1; next<n; ++next){
		if(start==-1 || arr[start]<arr[next]){
			ret=max(ret, lis(next)+1);
		}
	}
	return ret;
}

int main(void){
	memset(cache, -1, sizeof(cache));
	scanf("%d",&n);

	for(int i=0; i<n; ++i)
		scanf("%d",&arr[i]);

	auto ret=lis(-1)-1;
	
	return 0;
}
