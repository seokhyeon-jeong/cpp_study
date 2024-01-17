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
				for(int k=0; k<9; ++k)
					if(k!=i && k!=j)
						cout << a[k] << '\n';
			}
}

int main(void){
	solution();
}
