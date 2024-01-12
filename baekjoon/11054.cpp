#include <bits/stdc++.h>
using namespace std;

int N, A[1000], cache[1000];

void lds(void){
	cache[N-1]=1;

	for(int idx=N-2; idx>=0; --idx){
		cache[idx]=1;
		for(int next=idx+1; next<N; ++next){
			if(A[idx]>A[next])
				cache[idx]=max(cache[idx], cache[next]+1);
		}
	}
}

int bitonic(int start){
	int ret=1;
	for(int next=start+1; next<N; ++next){
		if(A[start]<A[next])
			ret=max(ret,bitonic(next)+1);
		else if(A[start]>A[next])
			ret=max(ret,cache[next]+1);
		else
			;
	}
	return ret;
}
int main(void){
	cin >> N;
	for(int i=0; i<N; ++i)
		scanf("%d", &A[i]);
	lds();
	int ret=1;
	for(int begin=0; begin<N; ++begin)
		ret=max(ret, bitonic(begin));
	cout << ret << endl;
}
