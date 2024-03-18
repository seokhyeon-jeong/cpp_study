#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)

int N, M, u, v;
int graph[1001][1001], used[1001];

int solution(int node){
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        int nextNode=q.front();
        q.pop();
        if(used[nextNode]==1)
            continue;
        used[nextNode]=1;
        for(auto i=1; i<=N; ++i)
            if(graph[nextNode][i]==1)
                q.push(i);
    }
    for(auto i=1; i<=N; ++i)
        if(used[i]==0)
            return 1+solution(i);
    return 1;
}

int main(void){
    cin >> N >> M;
    FOR(i,M){
        cin >> u >> v;
        graph[u][v]=graph[v][u]=1;
    }
    cout << solution(1) << endl;
}
