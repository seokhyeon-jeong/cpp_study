#include <bits/stdc++.h>
using namespace std;

int N, A[1000], lisCache[1001], ldsCache[1001];

void lis(void){
	lisCache[0]=1;
	for(int start=1; start<N; ++start){
		int& ret=lisCache[start];
		ret=1;
		for(int next=start-1; next>=0; --next){
			if(A[start]>A[next])
				ret=max(ret, lisCache[next]+1);
		}
	}
}
void lds(void){
	ldsCache[N-1]=1;
	for(int start=N-2; start>=0; --start){
		int& ret=ldsCache[start];
		ret=1;
		for(int next=start+1; next<N; ++next){
			if(A[start]>A[next])
				ret=max(ret, ldsCache[next]+1);
		}
	}
}
int main(void){
	cin >> N;
	for(int i=0; i<N; ++i)
		scanf("%d", &A[i]);

	lis();
	lds();

	int ret=-1;
	for(int i=0; i<N; ++i){
		lisCache[i] += ldsCache[i];
		if(lisCache[i]>ret)
			ret=lisCache[i];
	}
	cout << --ret << endl;
	return 0;
}

