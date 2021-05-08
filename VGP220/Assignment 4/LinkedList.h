#pragma once
#include <iostream>

template<typename T>
class LinkedList
{
	struct Node
	{
		T data;
		Node* next = nullptr;
	};

public:
	LinkedList()
		: mHead(nullptr)
	{}

	~LinkedList()
	{
		if (IsEmpty())
		{
			return;
		}

		if (mHead->next == nullptr)
		{
			delete mHead;
			mHead = nullptr;
			return;
		}

		Node* previous = mHead;
		Node* current = mHead->next;

		while (current != nullptr)
		{
			delete previous;
			previous = current;
			current = current->next;
		}

		delete previous;
		mHead = nullptr;
		previous = nullptr;
	}

	void Insert(T data)
	{
		Node* newNode = CreateNode(data);
		if (IsEmpty())
		{
			mHead = newNode;
			return;
		}

		Node* currentNode = mHead;
		while (currentNode != nullptr)
		{
			if (currentNode->next == nullptr)
			{
				currentNode->next = newNode;
				currentNode = nullptr;
				break;
			}
			currentNode = currentNode->next;
		}
	}

	void Remove(T data)
	{
		if (IsEmpty())
		{
			std::cout << "The list is empty.\n";
			return;
		}

		if (mHead->data == data)
		{
			Node* temp = mHead->next;
			delete mHead;
			mHead = temp;
			temp = nullptr;
			return;
		}

		Node* currentNode = mHead->next;

		while (currentNode->next->data != data && currentNode != nullptr)
		{
			currentNode = currentNode->next;
		}

		if (currentNode == nullptr)
		{
			std::cout << "The element is not in the list.\n";
			return;
		}
		Node* temp = currentNode->next;
		currentNode->next = temp->next;
		delete temp;
		temp = nullptr;

	}

	bool IsEmpty()
	{
		return mHead == nullptr;
	}

	//Displays all the elements of the linked list
	void DisplayList()
	{
		// TODO: 1
		if (IsEmpty())
		{
			std::cout << "List is empty.\n";
			return;
		}

		Node* tempNode = mHead;
		bool first = true;

		while (tempNode != nullptr)
		{
			if (first)
			{
				std::cout << tempNode->data;
				first = false;
			}
			else
			{
				std::cout << ", " << tempNode->data;
			}
			tempNode = tempNode->next;
		}
		std::cout << "\n";
	}

	//Displays all the elements of the linked list in reverse order
	void DisplayReverseList()
	{
		// TODO: 2
		if (IsEmpty())
		{
			std::cout << "List is empty.\n";
			return;
		}
		Node* tempNode = mHead;
		int listSize = 0;
		bool first = true;

		//Find the size of the linked list.
		while (tempNode != nullptr)
		{
			++listSize;
			tempNode = tempNode->next;
		}

		for (int i = listSize; i > 0; i--)
		{
			tempNode = mHead;

			//Move tempNode to the correct spot
			for (int j = 1; j < i; j++)
			{
				tempNode = tempNode->next;
			}

			//Printing
			if (first)
			{
				std::cout << tempNode->data;
				first = false;
			}
			else
			{
				std::cout << ", " << tempNode->data;
			}
		}
		std::cout << "\n";
	}

	//This function allows the user to modify an existance data
	//Returns true if the conten was modified and false if it wasn't.
	bool ModifyContent(T content, T newContent)
	{
		// TODO: 3
		Node* tempNode = mHead;
		bool changes = false;

		if (mHead != nullptr)
		{
			while (tempNode != nullptr)
			{
				if (tempNode->data == content)
				{
					tempNode->data = newContent;

					changes = true;
				}
				tempNode = tempNode->next;
			}
		}
		return changes;
	}

	//Clear all the data from the linked list
	void ClearList()
	{
		// TODO: 4

		if (IsEmpty())
		{
			std::cout << "List is empty.\n";
			return;
		}

		Node* tempNode = mHead;

		while (mHead->next != nullptr)
		{
			tempNode = mHead;
			mHead = mHead->next;
			delete tempNode;
			tempNode = nullptr;
		}

		delete mHead;
		mHead = nullptr;
	}

private:
	Node* mHead;

	Node* CreateNode(T data)
	{
		Node* newNode = new Node();
		newNode->data = data;
		return newNode;
	}
};
