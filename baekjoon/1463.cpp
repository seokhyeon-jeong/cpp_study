#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000001

int cache[MAX_N];
int N;

int makeOne(int n){
	int& ret=cache[n];
	if(ret!=-1)
		return ret;
	if(n&0x1) // n is odd
		return ret=1+min(makeOne(n%3),makeOne(n-1));
	else	// n is even
		return ret=1+min(makeOne(n>>1),makeOne(n-1));
}

int main(void)
{
	memset(cache, -1, sizeof(cache));

	cache[0]=std::numeric_limits<int>::max();
	cache[1]=0;
	
	scanf("%d",&N);
	
	auto ret=makeOne(N);

	printf("%d\n",ret);
}
