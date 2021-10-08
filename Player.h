#ifndef PLAYER_H
#define PLAYER_H

#include "Items.h"
#include "olcPixelGameEngine.h"

//extern int item_index[Items::total_item][ItemInfo::total_info];

class Player : public Lifeform
{
	//Stats
	int gold = 5;
	int exp = 0;
	//Inventory

public:
	Player(int, int, int);

	//unordered_map<string, Items> inventory;
	int inventory[5];
	/*int offensive_equip = UNEQUIPPED;
	int defensive_equip = UNEQUIPPED;*/

	int items_equipped[2];

	//array<bool, 10> equipped_array;
	void interact_item(int);
	bool inventory_gain_item(int);
	int get_damage() override;
	int get_max_hp() override;
	int get_gold();
	bool reduce_gold(int);
	//int get_damage();
};

#endif