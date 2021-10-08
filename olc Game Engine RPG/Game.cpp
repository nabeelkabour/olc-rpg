#include "Game.h"
#include "Gui.h"
#include "Startup.h"

Game::Game()
{
	sAppName = "Test RPG";
}

bool Game::OnUserCreate()
{
	_page_state = &PageState::main_menu;

	items_spritesheet = new olc::Sprite("./gfx/item_spritesheet.png");
	items_decal = new olc::Decal(items_spritesheet);

	player_sprite = new olc::Sprite("./gfx/crosshair.png");
	player_decal = new olc::Decal(player_sprite);

	skeleton_sprite = new olc::Sprite("./gfx/skeleton.png");
	skeleton_decal = new olc::Decal(skeleton_sprite);

	player_sprite = new olc::Sprite("./gfx/player.png");
	player_decal = new olc::Decal(player_sprite);

	player1 = new Player(10, 1, 1);
	player1->set_name("Adam");

	//Creating items
	items.push_back(Item("Rusty Sword", 1, 0, 0, 0, 1, { 0, 3 }));
	items.push_back(Item("Old Shield", 0, 1, 0, 0, 1, { 0, 7 }));
	items.push_back(Item("Health Potion", 0, 0, 1, 0, 1, { 0, 2 }));

	return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
	_page_state->update(this, fElapsedTime, player1);
	return true;
}

int fight_round(Lifeform* char1, int _char1_dmg, Lifeform* char2, int _char2_dmg)
{
	//get player input
	//player attack
	bool char2_dead = char2->take_damage(_char1_dmg);
	if (char2_dead)
	{
		//cout << char1.get_name() << " wins!" << endl;
		return FIGHT_EXIT_CH1_WIN;
	}
	//...
	//enemy attack
	bool char1_dead = char1->take_damage(_char2_dmg);
	if (char1_dead)
	{
		//cout << char2.get_name() << " wins!" << endl;
		return FIGHT_EXIT_CH2_WIN;
	}

	return 0;
}


int player_fight(Game* engine, Player* player, Lifeform* char2)
{
	while (true)
	{
		//fight_hud(player, char2);
		draw_inventory(engine, player);
		//display_actions();

		char player_input = get_player_input();
		int player_damage = 0;

		switch (player_input)
		{
		case 'x':
			player_damage = player->get_damage();
			break;

		case 'z':
			//cout << player.get_name() << " escapes the fight!" << endl;
			return FIGHT_EXIT_PLAYER_FLEE;

		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
			/*case '5':
			case '6':
			case '7':
			case '8':
			case '9':*/
			unsigned slot_val = player_input - 48 - 1;
			player->interact_item(slot_val);
			//display_inventory(player);
			break;
		}

		int fight_state = fight_round(player, player_damage, char2, char2->get_damage());

		if (fight_state > 0)
		{
			return fight_state;
		}
	}
}


char get_player_input()
{
	//char player_input;
	////cin >> player_input;
	//for (int i = 0; i < 20; ++i)
	//	//cout << endl << endl;
	//return player_input;
	return 'x';
}

//void handle_drops(Player* _player, Lifeform* _enemy)
//{
	//const int d_size = 2;
	//Items drops[d_size] = { Items::potion, Items::bow };

	//bool exit_flag = false;

	//while (true)
	//{
	//	//draw_inventory(_player);
	//	show_drops(drops, d_size);

	//	char player_input = get_player_input();

	//	if (player_input == 'x')
	//	{
	//		break;
	//	}

	//	player_input = player_input - 48 - 1;

	//	if (_player->inventory_gain_item(drops[player_input]))
	//	{
	//		drops[player_input] = Items::none;
	//	}

		//switch (player_input)
		//{
		//case '1':
		//	//gain drop1
		//	if (_player.inventory_gain_item(drop1))
		//	{
		//		//destroy item on ground
		//		drop1 = Items::none;
		//	}
		//	break;

		//case 'x':
		//	exit_flag = true;
		//	break;
		//}

		//if (exit_flag)
		//	break;
	//}
//}

//void weaponsmith(Player* _player)
//{
//#define NUM_SHOP_ITEMS 4
//
//	Items shop_items[NUM_SHOP_ITEMS] = { Items::sword, Items::bow, Items::arrows, Items::none };
//
//	for (int i = 0; i < NUM_SHOP_ITEMS; ++i)
//	{
//		//cout << "[" << i + 1 << "]";
//		display_item(shop_items[i]);
//		//cout << endl;
//	}
//
//	//cout << endl;
//	//cout << "[x]<-return" << endl << endl;
//
//	display_gold(_player);
//	//draw_inventory(_player);
//
//	char player_input = get_player_input();
//
//	switch (player_input)
//	{
//	case '1':
//	case '2':
//	case '3':
//	case '4':
//	case '5':
//		player_input += -48 - 1;
//
//		if (_player->get_gold() >= item_index[shop_items[player_input]][ItemInfo::price])
//		{
//			_player->inventory_gain_item(shop_items[player_input]);
//			_player->reduce_gold(item_index[shop_items[player_input]][ItemInfo::price]);
//		}
//
//		break;
//
//	case 'x':
//		return;
//		break;
//	}
//}

void armory(Player* _player)
{

}

void chemist(Player* _player)
{

}

void village(Player* _player)
{
	//weapons
	//armor
	//potions

	while (true)
	{
		/*cout << "[q] Weaponsmith" << endl;
		cout << "[w] Armory" << endl;
		cout << "[e] chemist" << endl;
		cout << endl;
		cout << "[x] Leave village" << endl << endl;*/

		//display_gold(_player);
		//draw_inventory(_player);

		//cout << endl;

		char player_input = get_player_input();
		bool exit_flag = false;

		switch (player_input)
		{
		case 'q':
			//weaponsmith(_player);
			break;

		case 'w':
			armory(_player);
			break;

		case 'e':
			chemist(_player);
			break;

		case 'x':
			exit_flag = true;
			break;
		}
		//save game

		if (exit_flag)
			break;
	}
}

void game_loop()
{
	//fight
	//village
}

//
//void process_player_input(char input)
//{
//	switch (input)
//	{
//	case 'x':
//		//deal damage to other character
//		break;
//	
//	case 'z':
//		//flee fight
//		break;
//	}
//}

//char get_player_input()
//{
//	cout << "-attack [x]";
//	char player_input;
//	cin >> player_input;
//
//	switch (player_input)
//	{
//	case 'x':
//		//deal damage to other character
//		break;
//	}
//}

//void interact_item(Game* engine, Player* player, int slot_no)
//{
//	switch (player->inventory[i])
//	{
//	case Item_ID::sword:
//		if(player->items_equipped)
//		break;
//	}
//}