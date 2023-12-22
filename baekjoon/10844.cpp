#include <bits/stdc++.h>
using namespace std;

const vector<unsigned> generateInput(unsigned n, unsigned a, unsigned b){
	vector<unsigned> ret(n);
	ret[0]=1983;
	for(unsigned i=1; i<n; ++i)
		ret[i]=((ret[i-1]*(long long)a)+b)%20090711;
	return ret;
}

unsigned median(const vector<unsigned>& v){
	priority_queue<unsigned> maxHeap;
	priority_queue<unsigned,vector<unsigned>,greater<unsigned>> minHeap;
	//12345 + 678910 maxHeap+minHeap
	unsigned ret=0;

	for(const auto ele : v){
		//처음 maxHeap 부터 채움
		if(maxHeap.empty()){
			maxHeap.push(ele);
		}
		//minHeap 비어있으면 minHeap 채움. 
		//mimHeap 안 비어있어도 maxHeap의 top 값보다 작은 값이 들어가면 안됨;
		else if(minHeap.empty()){
			if(ele >= maxHeap.top())
				minHeap.push(ele);
			else if(ele < maxHeap.top()){
				minHeap.push(maxHeap.top());
				maxHeap.pop();
				maxHeap.push(ele);
			}
			else
				;
		}
		//이제 모든 힙은 한 개 이상의 원소를 갖고있음.
		//heap의 size를 비교하고 heap 의 top 원소와 ele 를 비교하여 양쪽에 같은 개수로 채움
		else if(maxHeap.size()==minHeap.size()){
			if(ele >= maxHeap.top())
				minHeap.push(ele);
			else
				maxHeap.push(ele);
		}
		else if(maxHeap.size() > minHeap.size()){
			//maxHeap 크기 더 큰데 거기에 또 원소 넣어야하는 경우
			//maxHeap.top()을 빼서 minHeap에 삽입 후 원소를 넣는다.
			if(maxHeap.top() > ele){
				minHeap.push(maxHeap.top());
				maxHeap.pop();
				maxHeap.push(ele);
			}
			else{
				minHeap.push(ele);
			}
		}
		else if(maxHeap.size() < minHeap.size()){
			//minHeap 크기 더 큰데 거기에 또 원소 넣어야 하는 경우
			//minHeap.top()을 빼서 maxHeap에 삽입 후 원소를 넣는다.
			if(ele >= maxHeap.top()){
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(ele);
			}
			else
				maxHeap.push(ele);
		}
		else
			;

		if(maxHeap.size()==minHeap.size())
			ret += (maxHeap.top() <=minHeap.top()) ? maxHeap.top():minHeap.top();
		else
			ret += (maxHeap.size() > minHeap.size()) ? maxHeap.top():minHeap.top();
		ret %= 20090711;
	}
	return ret;
}

int main()
{
	int C,N,a,b;
	scanf("%d",&C);
	while(C--){
		scanf("%d %d %d",&N,&a,&b);
		auto ret=generateInput(N,a,b);
		printf("%u\n",median(ret));
	}
}
