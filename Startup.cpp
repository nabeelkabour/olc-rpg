#include "Startup.h"
#include "Enemy.h"
#include "Gui.h"
#include "Game.h"
#include "olcPixelGameEngine.h"

void startup(Game* engine)
{ 
	std::string temp;
	int text_scale = 1;
	olc::vi2d text_size;

	text_scale = 2;
	temp = "Welcome to the game";
	text_size = engine->GetTextSize(temp) * text_scale;
	engine->DrawString(engine->ScreenWidth() * 0.5 - text_size.x * 0.5, engine->ScreenHeight() * 0.5 - text_size.y * 0.5, temp, olc::RED, text_scale);

	text_scale = 1;
	temp = "press Enter to continue...";
	text_size = engine->GetTextSize(temp) * text_scale;
	engine->DrawString(engine->ScreenWidth() * 0.5 - text_size.x * 0.5, engine->ScreenHeight() * 0.8 - text_size.y * 0.5, temp, olc::RED, text_scale);

	////Test:
	////Tutorial
	//cout << "An enemy approaches..." << endl;
	//cout << "Get ready to fight!!" << endl << endl;
	//Enemy enemy1{ 5, 1, 1, 2, 3 };
	//enemy1.set_name("Minion");

	////fight function
	//int fight_result = player_fight(player1, enemy1);

	//if (fight_result != FIGHT_EXIT_PLAYER_WIN)
	//{
	//	cout << player1.get_name() << " has been defeated" << endl;

	//	while (true);

	//}
	//else if (fight_result == FIGHT_EXIT_PLAYER_WIN)
	//{
	//	handle_drops(player1, enemy1);
	//}

	////Continue game
	////go to village (shops, upgrades, etc; like swords and sandals)
	//village(player1);
}

void set_player_name(Game* engine)
{
	int text_scale = 1;
	std::string temp;
	olc::vi2d text_size;

	temp = "Please enter player name: ";
	text_size = engine->GetTextSize(temp) * text_scale;
	engine->DrawString(engine->ScreenWidth() * 0.5 - text_size.x * 0.5, engine->ScreenHeight() * 0.5 - text_size.y * 0.5, temp, olc::RED, text_scale);

	std::string player_name;
	player_name = "Adam";//std::cin >> player_name;

	temp = "Welcome " + player_name + " " + "to the game.";
	text_size = engine->GetTextSize(temp) * text_scale;
	engine->DrawString(engine->ScreenWidth() * 0.5 - text_size.x * 0.5, engine->ScreenHeight() * 0.75 - text_size.y * 0.5, temp, olc::RED, text_scale);

	temp = "press Enter to enter the world";
	text_size = engine->GetTextSize(temp) * text_scale;
	engine->DrawString(engine->ScreenWidth() * 0.5 - text_size.x * 0.5, engine->ScreenHeight() * 0.9 - text_size.y * 0.5, temp, olc::RED, text_scale);
}