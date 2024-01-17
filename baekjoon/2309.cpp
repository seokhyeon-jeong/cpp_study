#include <bits/stdc++.h>
using namespace std;

int a[9];

void solution(void){
	int sum=0;
	for(int i=0; i<9; ++i){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sort(a, a+9);
	sum -= 100;

	int i=0, j=0;
	for(; i<9; ++i)
		for(j=i+1; j<9; ++j)
			if(a[i]+a[j]==sum){
				a[i]=-1;
				a[j]=-1;
			}
	for(int i=0; i<9; ++i)
		if(a[i]!=-1)
			cout << a[i] << endl;
}

int main(void){
	solution();
}
