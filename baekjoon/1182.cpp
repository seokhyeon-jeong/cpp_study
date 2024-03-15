#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)

int N, S;
int ret, used[20], seq[20];

void solution(int start, int depth, int sum, int cnt){
    if(depth==cnt){
        if(sum==S)
            ++ret;
    }

    for(int i=start; i<N; ++i){
        solution(i+1, depth+1, sum+seq[i], cnt);
    }
}

int main(void){
    cin >> N >> S;
    FOR(i,N)
        cin >> seq[i];
    for(int i=1; i<=N; ++i)
        solution(0,0,0,i);
    cout << ret << endl;
}
