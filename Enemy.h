#ifndef ENEMY_H
#define ENEMY_H

#include "Lifeform.h"
#include <string>

class Enemy : public Lifeform
{
	int gold_value;
	int exp_val;
	//int damage;

public:
	Enemy(int, int, int, int, int);
};

#endif