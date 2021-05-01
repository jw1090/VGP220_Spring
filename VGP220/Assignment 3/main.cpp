#include <iostream>
#include "Inventory.h"

int main(int argc, char* argv[])
{
	Item hps{ "Healing Potion", 12, ItemType::Potion };
	Item poisonPotion{ "Poison Potion", 5, ItemType::Potion };
	Item sword{ "Excalibur", 1, ItemType::Weapon };
	Item shield{ "DragHorn Shield", 2, ItemType::Shield };
	Item armor{ "Heavy Plate", 1, ItemType::Armor };
	Item pick{ "Lock Pick", 20, ItemType::Utility };
	Item curse{ "Expansion", 1, ItemType::Charm };
	Item rope{ "Rope", 30, ItemType::Utility };
	Item test{ "Test", 45, ItemType::Utility };

	Inventory inventory_1; //Testing default constructor
	Inventory inventory_2(10); //Testing non default constructor
	//Testing same items add

	inventory_2.AddItem(hps);
	inventory_2.AddItem(hps);
	inventory_2.AddItem(hps);
	inventory_2.AddItem(hps);
	inventory_2.AddItem(hps);

	//inventory_2.ShowInventory();

	//Testing remove small quantity 
	inventory_2.RemoveItem("Healing Potion", 3);
	//Testing remove big quantity 
	inventory_2.RemoveItem("Healing Potion", 60);

	//inventory_2.ShowInventory();

	//Testing Copy Constructor
	Inventory inventory_3(inventory_2);
	//Testing move constructor
	Inventory inventory_4(std::move(inventory_3));

	Inventory inventory_5;
	//TODO: Testing copy assignment operator
	inventory_5 = inventory_2;
	//TODO: Testing move assignment operator
	inventory_5 = std::move(inventory_4);

	inventory_2.AddItem(poisonPotion);
	inventory_2.AddItem(sword);
	inventory_2.AddItem(shield);
	inventory_2.AddItem(armor);
	//Testing special case for expansion
	inventory_2.AddItem(curse);
	inventory_2.AddItem(rope);

	//TODO: Other tests that you want to make
	//inventory_2.ShowInventory();
}
