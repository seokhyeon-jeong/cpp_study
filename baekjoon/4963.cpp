#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)

int w, h;
int m[50][50];
int dy[]={0,1,1,1,0,-1,-1,-1};
int dx[]={1,1,0,-1,-1,-1,0,1};
int visited[50][50]={0,};

inline bool out_of_map(int y, int x){
    return (y<0) || (y>=h) || (x<0) || (x>=w);
}
int solution(int y, int x){
    if(out_of_map(y,x) || visited[y][x]==1)
        return 0;
    if(m[y][x]==0){
        visited[y][x]=1;
        return 0;
    }
    visited[y][x]=1;
    int ret=1;
    FOR(next, 8){
        ret += solution(y+dy[next], x+dx[next]); 
    }
    return ret;
}

int main(void){
    int cnt=0;
    int ret=0;
    while(true){
        ret=0;
        cin >> w >> h;
        if(w==0 && h==0)
            break;
        FOR(y,h){
            FOR(x,w){
                cin >> m[y][x];
            }
        }
        FOR(y,h){
            FOR(x,w){
                if(visited[y][x]==0 && solution(y,x)>0)
                    ++ret;
            }
            cnt=0;
        }
        cout << ret << '\n';
        memset(visited, 0, sizeof(visited));
    }
}
