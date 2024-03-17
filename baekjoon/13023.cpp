#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)

int N, M;
vector<vector<int>> people(2001);
int visited[2001], ret;

void solution(int currentPerson, int depth){
    if(depth==5){
        ++ret;
        return;
    } 
    
    for(auto nextFriend : people[currentPerson]){
        if(visited[nextFriend]==1)
            continue;
        visited[nextFriend]=1;
        solution(nextFriend, depth+1);
        visited[nextFriend]=0;
    }
}

int main(void){
    int person_1=0, person_2=0;
    ret=0;
    cin >> N >> M;
    FOR(i, M){
        cin >> person_1 >> person_2;
        people[person_1].push_back(person_2);
        people[person_2].push_back(person_1);
    }

    FOR(i,N){
        visited[i]=1;
        solution(i,0);
        visited[i]=0;
        if(ret>0)
            break;
    }
    cout << (ret>0) << endl;
}
