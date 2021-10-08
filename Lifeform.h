#ifndef LIFEFORM_H
#define LIFEFORM_H

#include <string>

class Lifeform
{
	std::string name;
	int max_hp;
	int hp;
	int level;
	int damage;
	int armor;

public:
	Lifeform(int, int, int);

	void set_name(std::string);
	std::string get_name();
	int get_hp();
	void increase_hp(unsigned);
	virtual int get_max_hp();
	int get_level();
	bool take_damage(int);
	virtual int get_damage();
	void set_damage(int);
};

#endif 