#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)

int N, m[25][25];

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int visited[25][25]={0,};

inline bool out_of_map(int y, int x){
    return (y<0) || (y>=N) || (x<0) || (x>=N);
}

int solution(int y, int x){
    if(out_of_map(y,x))
        return 0;
    if(m[y][x]==0){
        visited[y][x]=1;
        return 0;
    }
    if(visited[y][x]==1)
        return 0;
    int ret=1;
    visited[y][x]=1;
    FOR(next, 4){
        ret+=solution(y+dy[next], x+dx[next]);
    }
    return ret; 
}
int main(void){
    vector<int> retBuf;
    int cnt=0;
    cin >> N;
    FOR(y,N){
        string row;
        cin >> row;
        FOR(x,N)
            m[y][x]=row[x]-'0';
    }
    int ret=0;
    FOR(y,N){
        FOR(x,N){
            if(visited[y][x]==0){
                ret=solution(y,x);
                if(ret!=0){
                    retBuf.push_back(ret);
                    
                }
            }
        }
    }
    sort(retBuf.begin(), ret.end());
    cout << retBuf.size() << '\n';
    for(auto ele : retBuf)
        cout << ele << '\n';
}
