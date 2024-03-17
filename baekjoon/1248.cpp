#include <bits/stdc++.h>
using namespace std;

int n, buf[10], used[21];
char matrix[10][10];

void solution(void){
}
int main(void){
    cin >> n;
    for(int y=0; y<n; ++y)
        for(int x=0; x<n; ++x)
            cin >> matrix[y][x];
    solution(0,0);
}
