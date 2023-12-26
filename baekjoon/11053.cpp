#include <bits/stdc++.h>
using namespace std;

int arr[1000], cache[1000];
int n;

int lis(int start){
	int& ret=cache[start];
	if(ret!=-1)
		return ret;
	
	ret=1;
	for(int next=start+1; next<n; ++next){
		if(arr[start]<arr[next]){
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
	int ret=0;
	for(int i=0; i<n; ++i)
		ret=max(ret, lis(i));

	printf("%d\n",ret);
}
