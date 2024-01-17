#include <bits/stdc++.h>
using namespace std;

int N;
char board[50][50];

int check(int y, int x){
	int i=0, j=1;
	int ret=1;
	//horizontal
	while(i<N){
		while(j<N && board[y][i]==board[y][j])
			++j;
		ret=max(ret,j-i);
		i=j;
		j=i+1;
	}
	//vertical
	i=0; j=1;
	while(i<N){
		while(j<N && board[i][x]==board[j][x])
			++j;
		ret=max(ret,j-i);
		i=j;
		j=i+1;
	}
	return ret;
}
int main(void){
	cin >> N;

	for(int y=0; y<N; ++y)
		for(int x=0; x<N; ++x)
			scanf(" %c", &board[y][x]);
	int ret=1;	
	for(int y=0; y<N-1; ++y){
		for(int x=0; x<N-1; ++x){
			ret=max(ret,check(y,x));
			if(board[y][x]!=board[y][x+1]){
				swap(board[y][x],board[y][x+1]);
				ret=max(ret,check(y,x));
				swap(board[y][x],board[y][x+1]);
			}
			if(board[y][x]!=board[y+1][x]){
				swap(board[y][x],board[y+1][x]);
				ret=max(ret,check(y,x));
				swap(board[y][x],board[y+1][x]);
			}
		}
	}
	cout << ret << '\n';
}
