#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000000
unsigned cache[101][10];

void stair(void){
   for(int i=1; i<=9; ++i)
      cache[1][i]=1;
   for(int i=2; i<=100; ++i){
      cache[i][0]=cache[i-1][1];
      for(int j=1; j<=8; ++j){
         cache[i][j]=(unsigned)(((unsigned long long)cache[i-1][j-1]+cache[i-1][j+1])%MOD);
      }
      cache[i][9]=cache[i-1][8];
   }   
}

inline unsigned getStair(int n){
	unsigned ret=0;
	for(int i=0; i<=9; ++i){
		ret = (ret+cache[n][i])%MOD;
	}
	return ret;
}
int main(void){
	stair();
	int n,ret;
	scanf("%d",&n);
	ret=getStair(n);
	printf("%d\n",ret);
	return 0;
}
