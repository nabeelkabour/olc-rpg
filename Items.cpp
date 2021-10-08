#include "Items.h"

std::vector<Item> items;

Item::Item(std::string _name, int _damage, int _defence, int _health, int _special, int _price, olc::vi2d _sprite_pos) : damage{ _damage }, 
	name{_name}, defence{ _defence }, health{ _health }, special{ _special }, price{ _price }, sprite_pos{ _sprite_pos } {}