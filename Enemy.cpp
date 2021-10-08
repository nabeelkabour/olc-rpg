#include "Enemy.h"

Enemy::Enemy(int _max_hp, int _level, int _damage, int _gold_val, int _exp_val) : Lifeform{ _max_hp, _level, _damage }, gold_value{ _gold_val }, exp_val{ _exp_val } {}