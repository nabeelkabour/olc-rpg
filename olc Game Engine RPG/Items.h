#ifndef ITEMS_H
#define ITEMS_H

#include "Lifeform.h"
#include <string>
#include <unordered_map>
#include "olcPixelGameEngine.h"

#define NUM_INVENTORY_SLOTS 5
#define UNEQUIPPED -1

#define ITEM_WIDTH 34
#define ITEM_HEIGHT 34

class Item;

extern std::vector<Item> items;

enum Item_ID
{
	none = -1,
	sword,
	shield,
	potion,
	bow,
	arrows,
	total_item
};

//enum ItemInfo
//{
//	damage,
//	health,
//	special,
//	price,
//	total_info
//};

enum PlayerItem
{
	offensive,
	defensive
};

class Item
{
public:
	std::string name;
	int damage;
	int defence;
	int health;
	int special;
	int price;

	olc::vi2d sprite_pos;

	Item(std::string, int, int, int, int, int, olc::vi2d);
};

#endif

/*
what if you gave each item an int item_id ?
and you have a std::vector<ItemClass> items;

where ItemClass has the description(attack, defense, sprite) for that item and is indexed by the item_id
then you can have a std::map<olc::vi2d, std::vector<int>> locations; or similar, which tells you what items are at a given location
Then when you go to draw things, you can just iterate over everything in your locationsand lookup the item_id in your items vector.
The draw position comes from the locations key, and the sprite comes from looking up the item_id in your items vector

ItemClass would basically be "the things that describe and are common to every instance of this item"
like, every BroadSword has the same statsand sprite, but it there might be two with different map locations or weilded by two different characters.
*/