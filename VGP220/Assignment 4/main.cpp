#include <iostream>
#include "LinkedList.h"
#include "Queue.h"


//TESTS
int main(int argc, char* argv[])
{
	LinkedList<int> myList;
	Queue<int> myQueue;

	//Linked List Test
	myList.Insert(1);
	myList.Insert(2);
	myList.Insert(3);
	myList.Insert(4);
	myList.Insert(5);
	myList.Insert(6);
	myList.Insert(7);
	myList.Insert(8);
	myList.Insert(9);
	myList.Insert(10);

	myList.DisplayList();
	myList.DisplayReverseList();
	myList.ModifyContent(5, 30);
	myList.DisplayList();
	myList.ClearList();
	myList.DisplayList();

	
	//Queue test
	myQueue.Enqueue(1);
	myQueue.Enqueue(2);
	myQueue.Enqueue(3);
	myQueue.Enqueue(4);
	myQueue.Enqueue(5);
	myQueue.DisplayQueue();

	int removedElement = 0;
	if (myQueue.Daqueue(removedElement))
	{
		std::cout << "Element " << removedElement << " removed.\n";
	}
	myQueue.DisplayQueue();

	//TODO_OPTIONAL: Run more tests for your data structures.*/
}