#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)
#define MAX_I 300
#define INIT_VALUE 987654321
int I;
int board[MAX_I][MAX_I];

void display(void){
    FOR(y,MAX_I){
        FOR(x,MAX_I){
            cout << board[y][x] << ' ';
        }
        cout << '\n';
    }
}
inline bool out_of_board(int y, int x){
    return (y<0) || (y>=I) || (x<0) || (x>=I);
}

int solution(int y, int x, int targetY, int targetX){
    if(y==targetY && x==targetX)
        return 0;
    int dy[]={1,2,2,1,-1,-2,-2,-1};
    int dx[]={2,1,-1,-2,-2,-1,1,2};
    queue<pair<int,int>> q;
    q.push({y,x});
    while(!q.empty()){
        int cy=q.front().first;
        int cx=q.front().second;
        q.pop();
        FOR(next, 8){
            int ny=cy+dy[next];
            int nx=cx+dx[next];
            if(out_of_board(ny,nx))
                continue;
            if(ny==targetY && nx==targetX)
                return board[cy][cx]+1;
            if(board[ny][nx]!=INIT_VALUE)
                continue;
            board[ny][nx]=board[cy][cx]+1;
            q.push({ny,nx});
        }
    }
    return board[targetY][targetX];
}

int main(void){
    cin >> I;
    FOR(y,I){
        FOR(x,I){
            board[y][x]=INIT_VALUE;
        }
    }
    int y, x, targetX, targetY;
    cin >> y >> x >> targetY >> targetX;
    board[y][x]=0;
    int ret=solution(y,x,targetY,targetX);
    cout << ret << endl;
}
