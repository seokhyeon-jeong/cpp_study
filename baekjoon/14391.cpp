#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)

int N, M, paper[4][4];
int ret;

void solution(void){

    for(int subset=0; subset<=((1<<(N*M))-1); ++subset){
        int sum=0;
        FOR(y,N){
            int tmpSum=0;
            FOR(x,M){
                if((subset&(1<<(y*M+x)))==0)
                    tmpSum = tmpSum*10+paper[y][x];
                else{
                    sum += tmpSum;
                    tmpSum=0;
                }
            }
            sum += tmpSum;
        }

        FOR(x,M){
            int tmpSum=0;
            FOR(y,N){
                if((subset&(1<<(y*M+x)))!=0)
                    tmpSum = tmpSum*10+paper[y][x];
                else{
                    sum += tmpSum;
                    tmpSum=0;
                }
            }
            sum += tmpSum;
        }
        ret = max(ret, sum);
    }
}
     
int main(void){
    ret=-1;
    cin >> N >> M;
    string in;
    FOR(i,N){
        string tmp;
        cin >> tmp;
        in += tmp;
    }
    FOR(y,N){
        FOR(x,M){
            paper[y][x]=in[y*M+x]-'0';
        }
    }
    solution();
    cout << ret << endl;
}
