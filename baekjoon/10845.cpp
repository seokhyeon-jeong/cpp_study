#include <bits/stdc++.h>
using namespace std;

class Queue
{
	public:
		Queue(const int initCap = SPARE_CAPACITY)
			:theSize{0}, theCapacity{SPARE_CAPACITY}, f{0}, b{0}
		{	theArray = new int[initCap];	}

		void push(const int x)
		{
			if(theSize==theCapacity)
				resize(theCapacity*2);

			theArray[b++] = x;
			b -= theCapacity*(b>=theCapacity);
			++theSize;
		}

		int pop()
		{
			if(empty())
				return -1;
			int retVal = theArray[f++];
			f -= theCapacity*(f>=theCapacity);
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
			return theArray[b];
		}
		void resize(int newSize)
		{
			int* newArray = new int[newSize];
			for(int i=0; i<theCapacity; ++i)
				newArray[i] = theArray[i];
			std::swap(newArray,theArray);
			delete[] newArray;
			theCapacity = newSize;
		}
		
		void print() const
		{
			if(empty())
				cout << "EMPTY QUEUE\n";
			for(int i=0; i<theCapacity; ++i)
				cout << theArray[i] << '\t';
			cout << '\n';
			cout << "f : " << f << "b : " << b << '\n';
			cout << "---------------------------------------\n";
		}
	private:
		int* theArray;
		int theSize;
		int theCapacity;
		int f; //where to dequeue;
		int b; //where to enqueue;

		static const int SPARE_CAPACITY = 4;
};

void run()
{
	int op, pushVal;
	Queue q;
	cout << "(1) push X, (2) pop, (3) size, (4)empty, (5)front, (6)back\n";
	cout << "op : ";
	
	while(true)
	{
		cin >> op;
		switch(op)
		{
			case 1:
				cin >> pushVal;
				q.push(pushVal);
				break;
			case 2:
				cout <<  "popped value : " <<  q.pop() << endl;
				break;
			case 3:
				cout << "size : " << q.size() << endl;
				break;
			case 4:
				cout << "is Empty? : " <<q.empty() << endl;
				break;
			case 5:
				cout << "front Value : " << q.front() << endl;
				break;
			case 6:
				cout << "back Value : " << q.back() << endl;
				break;
			default:
				break;
		}
		q.print();
		if(op==0)
			break;
	}
}

int main()
{
	run();
}
