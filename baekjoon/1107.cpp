#include <bits/stdc++.h>
using namespace std;

int channel, M, button[10];

bool isBroken(int n){
	do{
		if(button[n%10]==-1)
			return true;
		n/=10;
	}while(n!=0);
	return false;
}

int pushButton(int n){
	int ret=0;
	do{
		n/=10;
		++ret;
	}while(n!=0);
	return ret;
}
int solution(void){
	int ret=abs(channel-100);
	
	for(int i=channel; i<=1000000; ++i){
		if(!isBroken(i)){
			ret=min(ret, pushButton(i)+i-channel);
			break;
		}
	}
	for(int i=channel-1; i>=0; --i){
		if(!isBroken(i)){
			ret=min(ret, pushButton(i)+channel-i);
			break;
		}
	}
	return ret;
}

int main(void){
	cin >> channel >> M;
	for(int i=0; i<M; ++i){
		int tmp;
		cin >> tmp;
		button[tmp]=-1;
	}
	int ret=solution();
	cout << ret << '\n';
}


