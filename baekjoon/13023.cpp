#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)

int N, M;
int ret, people[2000][2000], used[2000][2000];

void solution(int y, int x, int depth){
    if(depth==4){
        ++ret;
        return;
    }
    for(int nx=0; nx<N; ++nx){
        if(people[y][nx]==0 || used[y][nx]==1)
            continue;
        used[y][nx]=1;
        used[nx][y]=1;
        solution(nx, 0, depth+1);
        used[y][nx]=0;
        used[nx][y]=0;
    }
}

int main(void){
    cin >> N >> M;
    int x=0, y=0;
    FOR(i,M){
        cin >> x >> y;
        people[x][y]=1;
        people[y][x]=1;
    }
    FOR(y,N){
        solution(y,0,0);
        if(ret>0)
            break;
    }
    if(ret>0)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
}
