#ifndef GUI_H
#define GUI_H

#include "Lifeform.h"
#include "Player.h"
#include "olcPixelGameEngine.h"
#include "Game.h"

void fight_hud(Game*, Lifeform*, Lifeform*);
//void display_actions();
void draw_inventory(Game* engine, const Player*);
//void show_drops(Items[], int);
void draw_item(Game*, int, int, olc::vi2d);
//void display_gold(Player*);

#endif 


