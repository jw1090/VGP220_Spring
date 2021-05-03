#pragma once

#include <iostream>
#include "Item.h"


class Inventory
{
public:
	Inventory()
		: mMaxSlots(5)
		, mSlotsOccupied(0)
	{
		//TODO: Implement a default constructor for the Inventory class where the max number of slots
		// is 5 and all the slots are free (They are not occupied).

		mInventory = new Item[mMaxSlots];
	}
	Inventory(uint32_t capacity)
		: mMaxSlots(capacity)
		, mSlotsOccupied(0)
	{
		//TODO: Implement a non default constructor for the Inventory class where 
		//all the slots are free (They are not occupied).

		mInventory = new Item[capacity];
	}
	Inventory(const Inventory& other)
	{
		//TODO: Implement a copy constructor for this class. Avoid shallow copy.

		mSlotsOccupied = other.mSlotsOccupied;
		mMaxSlots = other.mMaxSlots;

		mInventory = new Item[other.mMaxSlots];

		for (auto i = 0; i < other.mSlotsOccupied; ++i)
		{
			mInventory[i] = other.mInventory[i];
		}
	}
	Inventory(Inventory&& other)
	{
		//TODO: Implement a move constructor for this class. Reset to a default state the other inventory.
		
		mSlotsOccupied = other.mSlotsOccupied;
		other.mSlotsOccupied = 0;

		mMaxSlots = other.mMaxSlots;
		other.mMaxSlots = 0;

		delete[] mInventory;
		mInventory = nullptr;

		mInventory = other.mInventory;
		other.mInventory = nullptr;
	}
	~Inventory()
	{
		//TODO: Implement a destructor for this class.
		
		delete[] mInventory;
		mInventory = nullptr;
	}


	//ERROR: -2. If the elements are equal you don't assign.
	//TODO: Implement a copy assignment operator
	Inventory& operator=(const Inventory& rhs)
	{
		mSlotsOccupied = rhs.mSlotsOccupied;
		mMaxSlots = rhs.mMaxSlots;

		mInventory = new Item[rhs.mMaxSlots];

		for (auto i = 0; i < rhs.mSlotsOccupied; ++i)
		{
			mInventory[i] = rhs.mInventory[i];
		}

		return *this;
	}

	//ERROR: -2. If the elements are equal, you don't move.
	//TODO: Implement a move assignment operator
	Inventory& operator=(Inventory&& rhs)
	{
		mSlotsOccupied = rhs.mSlotsOccupied;
		rhs.mSlotsOccupied = 0;

		mMaxSlots = rhs.mMaxSlots;
		rhs.mMaxSlots = 0;

		delete[] mInventory;
		mInventory = nullptr;

		mInventory = rhs.mInventory;
		rhs.mInventory = nullptr;

		return *this;
	}

	void AddItem(Item newItem)
	{
		//TODO: Implement AddItem Method. This method adds a new item to the inventory. 
		//First it searches for this item to see if the item exists, and if the item exists 
		//it checks the quantity, because the max quantity allowed per slot is 50.
		//So, for example, if you have 50 healing potions in your inventory, and you want to add one more, this potion
		//should occupy a new slot. Pay attention that the SearchItem function already does this quantity check for you.
		//The extra check that you should do is for the accumulated quantity. So your function should check
		//how many items this current slot has and if you add this new item quantity, how many items you will have.
		//If it's greater than 50, you should make the quantity of one slot 50 and add the remainder quantity to a new slot.
		//For example:
		//[ HP 48 ] [  ] [  ] [  ] [  ] Inventory has a HP(healing potions) with 48 as quantity and you want to add more 5 HP
		//[ HP 50 ] [HP 3] [  ] [  ] [  ] Inventory after you added 5 HP

		//If the Inventory is full, return a message to the user that the inventory is full and the items will be discarted.
		//Use the method IsFullForItem;

		//If after you insert the item your inventory becomes full for the remainder, Print a message to the user with how many
		//items will be discarted;

		std::cout << "Adding " << newItem.quantity << " " << newItem.name << " in inventory." << "\n";

		//SPECIAL CASE: If the user adds an item of type charm with the name "Expansion" your inventory
		//should expand adding 5 more empty slots for the user.


		//Expansion
		if (newItem.type == Charm && newItem.name == "Expansion")
		{
			CharmExpansion();
		}

		//Can work with inventory
		if (isFullForItem(&newItem) == false)
		{
			//Available spot in inventory that's less than 50
			if (SearchItemByNameLessThan50(newItem.name) != -1)
			{
				int index = SearchItemByNameLessThan50(newItem.name);

				if (newItem.quantity + mInventory[index].quantity <= 50)
				{
					mInventory[index].quantity += newItem.quantity;
				}
				else
				{
					int quantityHolder = 50 - mInventory[index].quantity;
					mInventory[index].quantity += quantityHolder;
					newItem.quantity -= quantityHolder;

					InsertIntoFreeSlot(newItem);
				}
			}

			else
			{
				InsertIntoFreeSlot(newItem);
			}

		}
		else
		{
			std::cout << "Inventory is full." << newItem.quantity << "items have been discarded.\n";
		}
	}

	//COMMENT: It works fine but you overcomplicated this part. So many unecessary if statements. Pay attention 
	//on this next time, to optimize a little bit more your code.
	void RemoveItem(std::string itemName, int quantity)
	{
		//TODO: Implement RemoveItem method
		//RemoveItem, should remove a quantity from the slot with the item. If the whole slot 
		//is empty, you should shift all the other items of the inventory;
		//If you try to remove more than what you have in one slot, just make the slot empty.
		//For example:
		//[ HP 50 ] [ HP 30 ] [  ] [  ] [  ] //You tried to remove 80 HP from the inventory
		//[ HP 30 ] [  ] [  ] [  ] [  ] //You just remove from one slot.

		std::cout << "Removing " << quantity << " " << itemName << " from inventory." << "\n";

		//SPECIAL CASE: If the user removes the charm Expansion from the inventory, your inventory 
		//should reduce the number of slots in 5, discarting all the items from the removed slots.

		//Reduction
		if (SearchItemByName(itemName) != 1 && itemName == "Expansion")
		{
			CharmReduction();
		}
		if (SearchItemByName(itemName) != -1)
		{
			int index = SearchItemByName(itemName);

			if (mInventory[index].quantity > quantity)
			{
				mInventory[index].quantity -= quantity;
			}
			else
			{
				while (quantity > 0 && index != -1)
				{

					if (quantity >= mInventory[index].quantity)
					{
						quantity -= mInventory[index].quantity;

						mInventory[index].name = "";
						mInventory[index].quantity = 0;
						
						--mSlotsOccupied;

						Shift(index);
						
					}
					else
					{
						mInventory[index].quantity -= quantity;
					}

					index = SearchItemByName(itemName);
				}
			}
		}
	}

	Item* UseItem(std::string itemName)
	{
		// TODO: Search for the item and if it exists, return this item and remove one from the inventory
		// otherwise, return nullptr.
		// The user is just allowed to use the Types: Posion and Utility.
		std::cout << "Using " << itemName << "\n";

		if (SearchItemByName(itemName) != -1)
		{
			int index = SearchItemByName(itemName);

			mInventory[index].quantity--;

			if (mInventory[index].quantity > 0)
			{
				return &mInventory[index];
			}
			else
			{
				mInventory[index].name = "";
				mInventory[index].quantity = 0;

				--mSlotsOccupied;

				Shift(index);
			}
		}
		else {
			std::cout << "You do not have " << itemName << " in your inventory!" << std::endl;
		}

		return nullptr;
	}

	void ShowInventory()
	{
		std::cout << "\n\n";

		for (int i = 0; i < mMaxSlots; ++i)
		{
			if (mInventory[i].quantity < 100)
			{
				std::cout << "[" << mInventory[i].name << " x "
					<< mInventory[i].quantity << " ] ";
			}
			else
			{
				std::cout << "[ ] ";
			}

			if ((i + 1) % 5 == 0 && i != 0)
			{
				std::cout << "\n";
			}
		}
	}

private:
	//Array of Items
	Item* mInventory;
	Item* emptyInventorySlot;
	//This variable tracks the capacity of the inventory
	uint32_t mMaxSlots;
	//This variable tracks how many slots are occupied.
	uint32_t mSlotsOccupied;


	//This method seaches for the item inside the Inventory and if it finds the item with less than
	//50 as quantity, it returns the index of the item inside the inventory array, otherwise, returns -1.
	int SearchItemByNameLessThan50(std::string target) const
	{
		int index = -1;
		for (int i = 0; i < mSlotsOccupied; i++)
		{
			if (target.compare(mInventory[i].name) == 0 && mInventory[i].quantity < 50)
			{
				index = i;
				break;
			}
		}

		return index;
	}

	//Returns the index of the item if it exists and -1 if it doesn't.
	int SearchItemByName(std::string target) const
	{
		int index = -1;
		for (int i = 0; i < mSlotsOccupied; i++)
		{
			if (target.compare(mInventory[i].name) == 0)
			{
				index = i;
				break;
			}
		}
		return index;
	}

	//If you don't have the item inside the inventory and all the slots are occupied - True
	//If you have the item in the inventory with max capacity and all the other slots are occupied - True
	//Otherwise - False.
	bool isFullForItem(Item* item) const
	{
		int index = SearchItemByNameLessThan50((*item).name);
		if (index == -1 && mSlotsOccupied == mMaxSlots)
		{
			return true;
		}
		if (index != -1 && mInventory[index].quantity >= 50 && mSlotsOccupied == mMaxSlots)
		{
			return true;
		}
		return false;
	}

	//Checks if space a slot is available
	//Inserts the new item into next available slot.
	//Incrases occupied slot tracker.
	void InsertIntoFreeSlot(Item newItem)
	{
		if (mSlotsOccupied < mMaxSlots)
		{
			mInventory[mSlotsOccupied] = newItem;			
			++mSlotsOccupied;
		}
		else
		{
			std::cout << "Inventory is full. " << newItem.quantity << " items have been discarded.\n";
		}
	}

	void CharmExpansion()
	{
		Item* temp = mInventory;

		mInventory = new Item[mMaxSlots];

		mInventory = new Item[mMaxSlots + 5];
		mMaxSlots += 5;

		for (int i = 0; i < mSlotsOccupied; ++i)
		{
			mInventory[i] = temp[i];
		}

		delete[] temp;
		temp = nullptr;
	}

	void CharmReduction()
	{
		Item* temp = mInventory;

		mInventory = new Item[mMaxSlots];

		mInventory = new Item[mMaxSlots - 5];
		mMaxSlots - 5;

		for (int i = 0; i < mSlotsOccupied || i < mMaxSlots; ++i)
		{
			mInventory[i] = temp[i];
		}

		delete[] temp;
		temp = nullptr;
	}
	
	//Shift all items right of empty slot to the left.
	void Shift(int index)
	{
		for (int i = index; i < mMaxSlots - 1; i++)
		{
			mInventory[i] = mInventory[i + 1];
		}
	}

};