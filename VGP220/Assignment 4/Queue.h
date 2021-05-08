#pragma once

//TODO: 5 - Implement a Queue class from scratch
//Remember that your queue should follow the FIFO standard (First In First Out)

template<typename T>
class Queue
{
public:
	Queue()
		: mCurrentSize(0)
		, mCapacity(10)
	{
		mData = new T[mCapacity];
	}

	~Queue()
	{
		delete[] mData;
		mData = nullptr;
	}

	//Inserts the data in the queue.
	void Enqueue(T data)
	{
		if (mCurrentSize == mCapacity)
		{
			std::cout << "Queue is full!" << std::endl;
			return;
		}

		mData[mCurrentSize] = data;

		if (isEmpty())
		{
			front = 0;
		}

		++mCurrentSize;
		rear = mCurrentSize - 1;
	}

	//Removes an element from the queue and returns this element in the output parameter
	//Also it returns true if the object was removed and false if the Queue is empty
	bool Daqueue(T& output)
	{
		if (isEmpty())
		{
			return false;
		}

		for (int i = 0; i < mCurrentSize - 1; i++)
		{
			mData[i] = mData[i + 1];
		}

		--mCurrentSize;
		rear = mCurrentSize - 1;

		return true;
	}

	//Returns true if queue is empty, false otherwise
	bool isEmpty()
	{
		return mCurrentSize == 0;
	}

	//Display all the elements in the queue:
	//Example, lets suppose you inserted 1, 2, 3, 4, 5
	//Display should print: "front->1, 2, 3, 4, 5<-rear"
	void DisplayQueue()
	{
		for (int i = 0; i < mCurrentSize; i++)
		{
			if (i == front)
			{
				std::cout << "front->" << mData[i] << ", ";
			}
			else if (i == rear)
			{
				std::cout << mData[i] << "<-rear";
			}
			else
			{
				std::cout << mData[i] << ", ";
			}
		}

		std::cout << "\n";
	}

private:
	int front;
	int rear;
	int mCurrentSize;
	int mCapacity;
	T* mData;
};