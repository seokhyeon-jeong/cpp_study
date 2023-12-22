#include <bits/stdc++.h>
using namespace std;

class Deque
{
	public:
		Deque(const int initSize = SPARE_CAPACITY)
			:theSize{0},theCapacity{initSize},f{-1},b{initSize}
		{	theArray = new int[initSize];	}

		void push_front(const int x)
		{
			if(theSize==theCapacity)
				resize(theCapacity*2);
			f += theCapacity*(f==0);
			theArray[--f] = x;
			++theSize;
		}
		void push_back(const int x)
		{
			if(theSize==theCapacity)
				resize(theCapacity*2);
			b -= theCapacity*(b==theCapacity);
			theArray[++b] = x;
			++theSize;
		}
		int pop_front()
		{
			if(empty())
				return -1;
			return theArray[++f];
		}
		int pop_back()
		{
			if(empty())
				return -1;
			return theArray[--b];
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
			return theArray[b];
		}
		void resize(int newSize)
		{
			int* newArray = new int[newSize];
			for(int i=0; i<theCapacity; ++i)
				newArray[i] = theArray[i];
			std::swap(newArray, theArray);
			delete[] newArray;
			theCapacity = newSize;
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
		cout << "op : ";
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
			case 9:
				dq.print();
				break;
			default :
				break;
		}
	}
}

int main()
{
	run();
}
