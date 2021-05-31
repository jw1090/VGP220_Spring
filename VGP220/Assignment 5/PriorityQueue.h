#pragma once

//Assignment 5: Implement a templatized priority queue, using a Max Heap for operations 
//like Enqueue and Daqueue

template<typename T>
class PriorityQueue
{

public:

	struct Data
	{
		int priority;
		T data;
	};

	PriorityQueue(Data emptyValue)
		: mCapacity(10)
		, mSize(0)
	{
		//TODO_1: Implement the constructor of this priority queue
		//Look to do this, look at the member variables that you have.
		//You can default initiliaze your capacity with 10 elements.

		mDataArray = new Data[10];
	}

	~PriorityQueue()
	{
		//TODO_2: Implement the destructor of this priority queue
		//Remember that whatever you "new" you have to "delete"

		delete[] mDataArray;
		mDataArray = nullptr;
	}

	void Enqueue(Data data)
	{
		//TODO_3: Implement an Enqueue method for this priority queue.
		//This enqueue should follow the same insertion method that
		//a max heap has.
		
		//Remember:
		//Heaps Insertion: Place the element at the end of the array,
		//In a loop, check yourself against you parent.priority. 
		//If yours is bigger, swap;

		if (mSize == mCapacity)
		{
			std::cout << "Heap is full.\n";
			return;
		}

		mDataArray[mSize] = data;
		int i = mSize;
		++mSize;

		while (i != 0 && mDataArray[GetParent(i)].priority > mDataArray[i].priority)
		{
			Swap(&mDataArray[GetParent(i)], &mDataArray[i]);
			i = GetParent(i);
		}

		return;

	}

	Data Dequeue()
	{
		//TODO_4: Implement a Dequeue method for this priority queue.
		//This Dequeue should follow the same RemoveMax method that
		//a max heap has.
		
		//Remember:
		//Heaps RemoveMax: Make the first element to receive the last
		//element from your array. After this, Heapfy.
		//If the queue is empty, return mEmptyValue

		if (mSize == 0)
		{
			return mEmptyValue;
		}

		--mSize;

		Data temp = mDataArray[0];

		if (mSize > 0)
		{
			mDataArray[0] = mDataArray[mSize];
			mDataArray[mSize] = mEmptyValue;

			Heapfy(0);
		}

		return temp;
	}

	int GetSize() const
	{
		return mSize;
	}

private:
	int GetParent(int index) const
	{
		return (index - 1) / 2;
	}

	int GetLeft(int index) const
	{
		return (index * 2) + 1;
	}

	int GetRight(int index) const
	{
		return (index * 2) + 2;
	}

	void Swap(Data* a, Data* b)
	{
		
		Data temp = *a;
		*a = *b;
		*b = temp;
		
	}

	void Heapfy(int index)
	{
		//TODO_5: Implement Heapfy
		//
		//Remember:
		//Heapfy: In a loop, checks which one is bigger in priority between left and right. and select.
		//Then compares with it's priority. If parent priority is smaller, Swap.

		int leftIndex = GetLeft(index);
		int rightIndex = GetRight(index);
		int smallest = index;

		if (leftIndex < mSize - 1 && mDataArray[leftIndex].priority < mDataArray[smallest].priority)
		{
			smallest = leftIndex;
		}

		if (rightIndex < mSize - 1 && mDataArray[rightIndex].priority < mDataArray[smallest].priority)
		{
			smallest = rightIndex;
		}

		if (smallest != index)
		{
			Swap(&mDataArray[index], &mDataArray[smallest]);
			Heapfy(smallest);
		}
	}

	Data* mDataArray;
	int mCapacity;
	int mSize;
	Data mEmptyValue;
};
