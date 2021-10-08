#include "Lifeform.h"
#include <iostream>

Lifeform::Lifeform(int _max_hp, int _level, int _damage) : max_hp{ _max_hp }, damage{ _damage }
{
	hp = max_hp;

	level = _level;
}

void Lifeform::set_name(std::string _name)
{
	name = _name;
}

std::string Lifeform::get_name()
{
	return name;
}

int Lifeform::get_hp()
{
	return hp;
}

int Lifeform::get_max_hp()
{
	return max_hp;
}

int Lifeform::get_level()
{
	return level;
}

bool Lifeform::take_damage(int _damage)
{
	hp -= _damage;

	if (hp <= 0)
		return true;
	return false;
}

int Lifeform::get_damage()
{
	return damage;
}

void Lifeform::set_damage(int _damage)
{
	damage = _damage;
}

void Lifeform::increase_hp(unsigned _amount)
{
	hp += _amount;

	if (hp > get_max_hp())
	{
		hp = get_max_hp();
	}
}