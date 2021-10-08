#include "Player.h"
#include "olcPixelGameEngine.h"

//int item_index[olc::vi2d][ItemInfo::total_info] = {
//	/*Items::none*/ {0, 0, 0, 0},
//	/*Items::sword*/{2, 0, 0, 2},
//	/*Items::shield*/{0, 2, 0, 3},
//	/*Items::potion*/{0, 0, 5, 1},
//	/*Items::bow*/   {1, 0, 1, 3}
//};

Player::Player(int _max_hp, int _level, int _damage) : Lifeform{ _max_hp, _level, _damage }
{
	inventory[0] = Item_ID::sword;
	inventory[1] = Item_ID::shield;
	inventory[2] = Item_ID::potion;
	inventory[3] = Item_ID::sword;
	inventory[4] = Item_ID::potion;

	/*for (int i = 3; i < NUM_INVENTORY_SLOTS; ++i)
	{
		inventory[i] = Item_ID::none;
	}*/

	items_equipped[offensive] = UNEQUIPPED;
	items_equipped[defensive] = UNEQUIPPED;

	/*for (unsigned i = 1; i < NUM_INVENTORY_SLOTS; ++i)
	{
		equipped_array[i] = false;
		inventory[i] = "Empty";
	}*/
}

void Player::interact_item(int slot_val)
{
	int item = inventory[slot_val];

	switch (item)
	{
	case Item_ID::sword:
	case Item_ID::bow:
		if (items_equipped[offensive] == slot_val)
		{
			items_equipped[offensive] = UNEQUIPPED;
		}
		else
		{
			items_equipped[offensive] = slot_val;
		}
		break;

	case Item_ID::shield:
		if (items_equipped[defensive] == slot_val)
		{
			items_equipped[defensive] = UNEQUIPPED;
		}
		else
		{
			items_equipped[defensive] = slot_val;
		}
		break;

	case Item_ID::potion:
		//gain hp
		if(get_hp() < get_max_hp())
		{ 
			increase_hp(items.at(inventory[slot_val]).health);
			inventory[slot_val] = Item_ID::none;
		}
		break;
	}
}

int Player::get_damage()
{
	//return damage plus item_damage
	if (items_equipped[offensive] != UNEQUIPPED)
	{
		return Lifeform::get_damage() + items.at(inventory[items_equipped[offensive]]).damage;
	}

	return Lifeform::get_damage();
}

int Player::get_max_hp()
{
	if (items_equipped[defensive] != UNEQUIPPED)
	{
		return Lifeform::get_max_hp() + items.at(inventory[items_equipped[defensive]]).health;
	}

	return Lifeform::get_max_hp();

	//return 200;
}

bool Player::inventory_gain_item(int _item)
{
	for (int i = 0; i < NUM_INVENTORY_SLOTS; ++i)
	{
		if (inventory[i] == Item_ID::none)
		{
			inventory[i] = _item;
			return true;
		}
	}

	return false;
}

int Player::get_gold()
{
	return gold;
}

bool Player::reduce_gold(int _amount)
{
	gold -= _amount;

	if (gold < 0)
	{
		//cout << "NEGATIVE GOLD" << endl;
		return false;
	}

	return true;
}

//void Player::set_name(string _name)
//{
//	name = _name;
//}
//
//string Player::get_name()
//{
//	return name;
//}
//
//int Player::get_hp()
//{
//	return hp;
//}
//
//int Player::get_max_hp()
//{
//	return max_hp;
//}