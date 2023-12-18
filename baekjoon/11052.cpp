#include <bits/stdc++.h>
using namespace std;

int P[10001], cache[10001];
int n;

int purchase(int buy){
	int& ret=cache[buy];
	if(ret!=-1)
		return ret;
	ret=P[buy];
	for(int i=0; i<=buy; ++i)
		ret=max(ret,purchase(buy-i)+purchase(i));
	return ret;
}
int main()
{
	scanf("%d",&n);

	for(int i=1; i<=n; ++i)
		scanf("%d",&P[i]);
	memset(cache, -1, sizeof(cache));
	cache[0]=0;
	cache[1]=P[1];

	printf("%d\n", purchase(n));
}
