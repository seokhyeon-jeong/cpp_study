#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)

int N, M;
int dy[]={0,1,0,-1};
int dx[]={1,0,-1,0};
int visited[100][100]={0,};
int m[100][100]={0,};
int ret=987564321;

void solution(int y, int x, int depth){
    FOR(next, 4){
        int ny=y+dy[next], nx=x+dx[next];
        if(ny<0 || ny>=N || nx<0 || nx>=M)
            continue;
        if(ny==N-1 && nx==M-1){
            ret=min(ret,depth+2);
            return;
        }
        if(visited[ny][nx]==1)
            continue;
        if(m[ny][nx]==0)
            continue;
        
        visited[ny][nx]=1;
        solution(ny, nx, depth+1);
        visited[ny][nx]=0;
    }
}

int main(void){
    cin >> N >> M;
    FOR(y,N){
        string str;
        cin >> str;
        FOR(x,M){
            m[y][x]=str[x]-'0';
        }
    }
    visited[0][0]=1;
    solution(0,0,0);
    cout << ret << endl;
}
