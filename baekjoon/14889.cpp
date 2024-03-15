#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)

int N, S[20][20];
int members[20], ret=987654321;
void solution(int start, int depth){
    if(depth==N/2){
        int startTeam=0, linkTeam=0;
        FOR(start,N){
            FOR(link,N){
                if(members[start]==1 && members[link]==1)
                    startTeam += S[start][link];
                if(members[start]==0 && members[link]==0)
                    linkTeam += S[start][link];
            }
        }
        ret = min(ret, abs(startTeam-linkTeam));
        return;
    }
    for(int i=start+1; i<N; ++i){
        if(members[i]==1)
            continue;
        members[i]=1;
        solution(i, depth+1);
        members[i]=0;
    }
}
int main(void){
    cin >> N;
    FOR(i,N)
        FOR(j,N)
            cin >> S[i][j];
    solution(0, 0);
    cout << ret << endl;
}
