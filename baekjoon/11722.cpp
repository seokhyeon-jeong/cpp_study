#include <bits/stdc++.h>
using namespace std;

int N, a[1000], cache[1000];

int lds(int start=0){
	int& ret=cache[start];
	if(ret!=-1)
		return ret;

	ret=1;
	for(int next=start+1; next<N; ++next){
		if(a[next]<a[start])
			ret=max(ret, lds(next)+1);
	}
	return ret;
}

int main(void){
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for(int i=0; i<N; ++i)
		scanf("%d",&a[i]);
	int ret=-1;
	for(int begin=0; begin<N; ++begin)
		ret=max(ret, lds(begin));
	cout << ret << endl;
}
