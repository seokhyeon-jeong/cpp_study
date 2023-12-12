#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m,A,B;
	scanf("%d %d\n%d",&A,&B,&m);
	unsigned sum=0;
	for(int i=m-1; i>=0; --i){
		int tmp;
		scanf("%d",&tmp);
		sum += tmp*pow(A,i);
	}
	stack<int> stk;
	while(sum!=0){
		stk.push(sum%B);
		sum /= B;
	}
	while(!stk.empty()){
		printf("%d ",stk.top());
		stk.pop();
	}
}
