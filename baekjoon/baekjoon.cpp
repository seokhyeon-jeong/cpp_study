#include <bits/stdc++.h>
using namespace std;

int cache[101][10];

void stair(void){
   for(int i=1; i<=9; ++i)
      cache[1][i]=1;
   for(int i=2; i<=100; ++i){
      cache[i][0]=cache[i-1][1];
      for(int j=1; j<=8; ++j){
         cache[i][j]=cache[i-1][j-1]+cache[i-1][j+1];
      }
      cache[i][9]=cache[i-1][8];
   }   
}

int main(void){
   stair();
   int ret=0;
   for(int i=0; i<=9; ++i)
      ret+=cache[2][i];
   cout << ret << endl;
   return 0;
}