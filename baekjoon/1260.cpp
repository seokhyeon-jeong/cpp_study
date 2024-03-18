#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)
#define MAX_N 1001 
int N, M, V;
vector<vector<int>> matrix(MAX_N);

void bfs(void){
    vector<int> ret;
    vector<bool> visited(MAX_N, false);
    queue<vector<int>> q;

    for(auto& nodes : matrix)
        sort(nodes.begin(), nodes.end());

    q.push(matrix[V]);
    ret.push_back(V);
    visited[V]=true;

    while(!q.empty()){
        auto nextVector = q.front();
        q.pop();
        sort(nextVector.begin(), nextVector.end());
        for(auto& nextNode : nextVector){
            if(visited[nextNode])
                continue;
            ret.push_back(nextNode);
            q.push(matrix[nextNode]);
            visited[nextNode]=true;
        }
    }
    for(auto ele : ret)
        cout << ele << ' ';
    cout << '\n';
}

void dfs(void){
    vector<int> ret;
    vector<bool> visited(MAX_N, false);
    stack<vector<int>> stk;
    
    for(auto& nodes : matrix)
        sort(nodes.begin(), nodes.end());

    stk.push(matrix[V]);
    ret.push_back(V);
    visited[V]=true;

    while(!stk.empty()){
        auto nextVector = stk.top();
        bool endOfDepth = true;
        for(auto nextNode : nextVector){
            if(visited[nextNode])
                continue;
            ret.push_back(nextNode);
            visited[nextNode]=true;
            stk.push(matrix[nextNode]);
            endOfDepth=false;
            break;
        }
        if(endOfDepth){
            stk.pop();
        }
    }
    for(auto ele : ret)
        cout << ele << ' ';
    cout << '\n';
}
int main(void){
    int node1=0, node2=0;
    cin >> N >> M >> V;
    FOR(i,M){
        cin >> node1 >> node2;
        matrix[node1].push_back(node2);
        matrix[node2].push_back(node1);
    }
    dfs();
}
