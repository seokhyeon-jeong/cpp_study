#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    int S=0, M=0, x=0;
    string whatToDo;
    map<string,int> op;
    op["add"]=0;
    op["remove"]=1;
    op["check"]=2;
    op["toggle"]=3;
    op["all"]=4;
    op["empty"]=5;
    
    cin >> M;
    FOR(i, M){
        cin >> whatToDo;
        switch(op[whatToDo]){
            case 0:
                cin >> x;
                S |= (1<<x);
                break;
            case 1:
                cin >> x;
                S &= ~(1<<x);
                break;
            case 2:
                cin >> x;
                cout << ((S & (1<<x))!=0) << '\n';
                break;
            case 3:
                cin >> x;
                S ^= (1<<x);
                break;
            case 4:
                S = (1<<21)-1;
                break;
            case 5:
                S = 0;
                break;
        }
    }
}

