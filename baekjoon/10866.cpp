#include <bits/stdc++.h>
using namespace std;

class Deque
{
	public:
		Deque(const int initSize = SPARE_CAPACITY)
			:theSize{0},theCapacity{0},f{0},b{0}
		{	theArray = new int[initSize];	}

		void push_front(const int x)
		{
			if(theSize==theCapacity)
				resize(theCapacity*2);
			theArray[f--] = x;
			f += theCapacity*(f<0);
			++theSize;
		}
		void push_back(const int x)
		{
			if(theSize==theCapacity)
				resize(theCapacity*2);
			theArray[b++] = x;
			b -= theCapacity*(b>=theCapacity);
			++theSize;
		}
		int pop_front()
		{
			if(empty())
				return -1;
			int retVal = theArray[f++];
			f -= theCapacity*(f>=theCapacity);
			--theSize;
			return retVal;
		}
		int pop_back()
		{
			if(empty())
				return -1;
			int retVal = theArray[b--];
			b += theCapacity*(b<0);
			--theSize;
			return retVal;
		}
		int size() const
		{	return theSize;	}
		bool empty() const
		{	return theSize==0;	}
		int front() const
		{
			if(empty())
				return -1;
			return theArray[f];
		}
		int back() const
		{
			if(empty())
				return -1;
			if(b==0)
				return theArray[theCapacity-1];
			return theArray[b-1];
		}
		void print() const
		{
			for(int i=0; i<theCapacity; ++i)
				cout << theArray[i] << '\t';
			cout << '\n';
			cout << "f : " << f << ", b : " << b << '\n';
			cout << "------------------------------------------\n";
		}
	private:
		int* theArray;
		int theSize;
		int theCapacity;
		int f;
		int b;

		static const int SPARE_CAPACITY=4;
};

void run()
{
	cout << "(1)push_front (2)push_back (3)pop_front (4)pop_back (5)size (6)empty (7)front (8)back\n";
	cout << "(9)print\n";

	int op;
	int pushVal;
	Deque dq;
	while(true)
	{
		cin >> op;
		if(op==0)
			break;
		switch(op)
		{
			case 1:
				cin >> pushVal;
				dq.push_front(pushVal);
				break;
			case 2:
				cin >> pushVal;
				dq.push_back(pushVal);
				break;
			case 3:
				cout << "Popped Val = " << dq.pop_front() << endl;
				break;
			case 4:
				cout << "Popped Val = " << dq.pop_back() << endl;
				break;
			case 5:
				cout << "Size = " << dq.size() << endl;
				break;
			case 6:
				cout << "is empty : " << dq.empty() << endl;
				break;
			case 7:
				cout << "front val = " << dq.front() << endl;
				break;
			case 8:
				cout << "back val = " << dq.back() << endl;
				break;
			default :
				break;
		}
	}
}
