#include "Gui.h"
#include <iostream>
#include "Player.h"
#include "olcPixelGameEngine.h"
#include "Game.h"

void fight_hud(Game* engine, Lifeform* char1, Lifeform* char2)
{
	int screen_width = engine->ScreenWidth();
	int screen_height = engine->ScreenHeight();

	std::string temp1 = char1->get_name() + ": \n"; 
	temp1 += "Level: " + std::to_string(char1->get_level()) + "\n";
	temp1 += "HP: " +  std::to_string(char1->get_hp()) + "/" + std::to_string(char1->get_max_hp()) + "\n";
	temp1 += "Dmg: " + std::to_string(char1->get_damage());

	engine->DrawString(screen_width * 0.1f, screen_height * 0.1f, temp1);

	olc::vi2d text_size = engine->GetTextSize("vs") * 3;
	engine->DrawString(screen_width / 2 - text_size.x / 2, screen_height / 2 - text_size.y / 2, "vs", olc::GREY, 3);

	std::string temp2 = char2->get_name() + ": \n";
	temp2 += "Level: " + std::to_string(char2->get_level()) + "\n";
	temp2 += "HP: " +  std::to_string(char2->get_hp()) + "/" + std::to_string(char2->get_max_hp());
	temp1 += "Dmg: " + std::to_string(char2->get_damage()) + "\n";
	engine->DrawString(screen_width * 0.7f, screen_height * 0.1f, temp2);
}

void display_actions()
{
	//cout << "-Attack [x]  " << "-Flee [z]" << endl;
}

void draw_item(Game* engine, int draw_x, int draw_y, olc::vi2d v)
{
	engine->DrawPartialSprite(draw_x, draw_y, engine->items_spritesheet, v.x * 34, v.y * 34, 34, 34);
}

void draw_inventory(Game* engine, const Player* player)
{
	//bool item_equipped = false;

	int inventory_width = NUM_INVENTORY_SLOTS * ITEM_WIDTH;
	int inventory_height = ITEM_HEIGHT;

	int screen_width = engine->ScreenWidth();
	int screen_height = engine->ScreenHeight();

	for (unsigned i = 0; i < NUM_INVENTORY_SLOTS; ++i)
	{
		int x_pos = screen_width / 2 - inventory_width / 2 + i * ITEM_WIDTH;
		int y_pos = screen_height * 0.8f;
		engine->DrawString(x_pos + ITEM_WIDTH / 2, y_pos - ITEM_HEIGHT / 2, std::to_string(i));

		if (player->inventory[i] != Item_ID::none)
		{
			draw_item(engine, x_pos, y_pos, items.at(player->inventory[i]).sprite_pos);
		}

		if (player->items_equipped[offensive] == i or player->items_equipped[defensive] == i)
		{
			//item_equipped = true;

			engine->DrawRect(x_pos, y_pos, ITEM_WIDTH, ITEM_HEIGHT, olc::RED);
		}   
	}

	for (unsigned i = 0; i < NUM_INVENTORY_SLOTS; ++i)
	{
		int x_pos = screen_width / 2 - inventory_width / 2 + i * ITEM_WIDTH;
		int y_pos = screen_height * 0.8f;

		if (player->items_equipped[offensive] == i or player->items_equipped[defensive] == i)
		{
			//item_equipped = true;
			engine->DrawRect(x_pos, y_pos, ITEM_WIDTH, ITEM_HEIGHT, olc::RED);
		}
	}
	//cout << endl << endl;
}



void display_gold(Player* _player)
{
	//cout << "gold: " << _player.get_gold();
}
