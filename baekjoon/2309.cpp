#include <bits/stdc++.h>
using namespace std;

int a[9];

void solution(void){
	int sum=0;
	for(int i=0; i<9; ++i){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	int i, j;
	for(i=1; i<9; ++i){
		int tmp=a[i];
		for(j=i; j>0 && a[j-1]>tmp; --j)
			a[j]=a[j-1];
		a[j]=tmp;
	}
	sum -= 100;

	for(int i=0; i<9; ++i){
		for(int j=i+1; j<9; ++j){
			if(a[i]+a[j]==sum){
				for(int k=0; k<9; ++k){
					if(k!=i && k!=j)
						cout << a[k] << '\n';
				}
				return;
			}
		}
	}

}

int main(void){
	solution();
}
