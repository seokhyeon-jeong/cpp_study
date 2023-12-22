#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
#define MOD 1000000009

int cache[MAX_N+1][4];

int main()
{
    cache[1][1]=1;
    cache[2][2]=1;
    cache[3][1]=1;
    cache[3][2]=1;
    cache[3][3]=1;

    for(int i=4; i<=MAX_N; ++i){
        cache[i][1]=(cache[i-1][2]+cache[i-1][3])%MOD;
        cache[i][2]=(cache[i-2][1]+cache[i-2][3])%MOD;
        cache[i][3]=(cache[i-3][1]+cache[i-3][2])%MOD;
    }
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int ret=(((cache[n][1]+cache[n][2])%MOD)+cache[n][3])%MOD;
        printf("%d\n",ret);
    }
}