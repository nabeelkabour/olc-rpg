#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Lifeform.h"
#include "Player.h"
#include "Pages.h"
#include "olcPixelGameEngine.h"

#define FIGHT_EXIT_PLAYER_WIN 1
#define FIGHT_EXIT_CH1_WIN 1
#define FIGHT_EXIT_CH2_WIN 2
#define FIGHT_EXIT_PLAYER_FLEE 3

class Game;

void game_loop();
void fight_loop();
int player_fight(Game*, Player*, Lifeform*);
int fight_round(Lifeform*, int, Lifeform*, int);
char get_player_input();
void process_player_input(char);
//void handle_drops(Player*, Lifeform*);

//Levels
void village(Player*);
//void weaponsmith(Player*);
void armory(Player*);
void chemist(Player*);

class PageState;

class Game : public olc::PixelGameEngine
{
	Player* player1 = nullptr;
	
public:
	olc::Sprite* player_sprite = nullptr;
	olc::Decal* player_decal = nullptr;
	olc::Sprite* skeleton_sprite = nullptr;
	olc::Decal* skeleton_decal = nullptr;

	olc::Sprite* items_spritesheet = nullptr;  //476 x 510 pixels  34 x 34 items 
	olc::Decal* items_decal = nullptr;

	/*void DrawItem(int,int, olc::vi2d);*/
	
	PageState* _page_state = nullptr;

	Game();
	bool OnUserCreate() override;
	bool OnUserUpdate(float) override;
};

#endif
