#include "Pages.h"
#include "Startup.h"
#include "Enemy.h"
#include "Game.h"
#include "Gui.h"

MainPage PageState::main_menu = MainPage();
NamePage PageState::name_page = NamePage();
IntroPage PageState::intro = IntroPage();
FightPage PageState::fight = FightPage();


MainPage::MainPage() : button1(50, 50, 50, 50)
{
	
}

void MainPage::update(Game* engine, float fElapsedTime, Player* player)
{
	startup(engine);

	if (engine->GetKey(olc::Key::ENTER).bPressed)
	{
		//engine->DrawString(50, 50, "we are here");
		engine->_page_state = &PageState::name_page;
		engine->Clear(olc::BLACK);
	}

	button1.draw(engine);

	if (button1.check_pressed(engine))
	{
		//engine->DrawString(50, 50, "we are here");
		engine->_page_state = &PageState::name_page;
		engine->Clear(olc::BLACK);
	}
}

void MainPage::draw(Game* engine, float fElapsedTime, Player* player)
{

}

void NamePage::update(Game* engine, float fElapsedTime, Player* player)
{
	set_player_name(engine);

	if (engine->GetKey(olc::Key::ENTER).bPressed)
	{
		//engine->DrawString(50, 50, "we are here");
		engine->_page_state = &PageState::intro;
		engine->Clear(olc::BLACK);
	}
}

void NamePage::draw(Game* engine, float fElapsedTime, Player* player)
{

}

IntroPage::IntroPage()
{
	skeleton = new Enemy(5, 1, 1, 2, 3);
	skeleton->set_name("Skeleton");
}

void IntroPage::update(Game* engine, float fElapsedTime, Player* player)
{
	engine->Clear(olc::BLACK);

	int screen_width = engine->ScreenWidth();
	int screen_height = engine->ScreenHeight();

	int text_scale = 1;
	std::string temp;
	olc::vi2d text_size;
	olc::Pixel color;

	temp = "An enemy approaches, prepare for battle!";
	text_size = engine->GetTextSize(temp) * text_scale;
	color = olc::Pixel(255, 0, 0, int(text_alpha));
	engine->DrawString(screen_width * 0.5 - text_size.x * 0.5, screen_height * 0.5 - text_size.y * 0.5, temp, color, text_scale);

	if (text_alpha > 0)
	{
		text_alpha -= 255.0f / 1.5f * fElapsedTime;
	}
	else
	{
		//engine->DrawDecal({ screen_width * 0.25f - sprite_width / 2.0f, screen_height / 2.0f - sprite_height / 2.0f }, engine->player_decal);

		engine->SetDrawTarget(nullptr);

		fight_hud(engine, player, skeleton);

		engine->DrawString(screen_width * 0.1f, screen_height * 0.75f, "[x] Attack\n\n[z] Flee", olc::WHITE, 1);


		static bool attack = false;

		if (engine->GetKey(olc::Key::X).bPressed)
		{
			player_turn = true;
			attack = true;
		}
		
		if (attack)
		{
			if (player_turn)
			{
				static bool flag = false;
				static float x_anim = 0;
				static float time_passed = 0.0f;

				if (!flag)
				{
					//time_passed += fElapsedTime;
					x_anim += float(screen_width) * fElapsedTime;
					if (x_anim >= screen_width / 2)
					{
						skeleton->take_damage(player->get_damage());

						time_passed = 0.0f;
						flag = true;
					}
				}
				else
				{
					//time_passed += fElapsedTime;
					x_anim -= float(screen_width) * fElapsedTime;
					if (x_anim <= 0)
					{
						time_passed = 0.0f;
						flag = false;
						player_turn = false;
					}
				}
				engine->SetDrawTarget(engine->skeleton_sprite);
				int sprite_width = engine->GetDrawTargetWidth();
				int sprite_height = engine->GetDrawTargetHeight();

				engine->DrawDecal({ screen_width * 0.75f - sprite_width / 2.0f, screen_height / 2.0f - sprite_height / 2.0f }, engine->skeleton_decal);

				engine->SetDrawTarget(engine->player_sprite);
				sprite_width = engine->GetDrawTargetWidth();
				sprite_height = engine->GetDrawTargetHeight();

				engine->DrawDecal({ screen_width * 0.25f - sprite_width / 2.0f + x_anim, screen_height / 2.0f - sprite_height / 2.0f }, engine->player_decal);

			}
			else
			{
				static bool flag = false;
				static float x_anim = 0;
				static float time_passed = 0.0f;
				if (!flag)
				{
					//time_passed += fElapsedTime;
					x_anim -= float(screen_width) * fElapsedTime;
					if (x_anim <= -screen_width / 2)
					{
						player->take_damage(skeleton->get_damage());

						time_passed = 0.0f;
						flag = true;
					}
				}
				else
				{
					//time_passed += fElapsedTime;
					x_anim += float(screen_width) * fElapsedTime;
					if (x_anim >= 0)
					{
						time_passed = 0.0f;
						flag = false;
						player_turn = true;
						attack = false;
					}
				}

				engine->SetDrawTarget(engine->skeleton_sprite);
				int sprite_width = engine->GetDrawTargetWidth();
				int sprite_height = engine->GetDrawTargetHeight();

				engine->DrawDecal({ screen_width * 0.75f - sprite_width / 2.0f + x_anim, screen_height / 2.0f - sprite_height / 2.0f }, engine->skeleton_decal);

				engine->SetDrawTarget(engine->player_sprite);
				sprite_width = engine->GetDrawTargetWidth();
				sprite_height = engine->GetDrawTargetHeight();

				engine->DrawDecal({ screen_width * 0.25f - sprite_width / 2.0f, screen_height / 2.0f - sprite_height / 2.0f }, engine->player_decal);
			}
		}
		else
		{
			engine->SetDrawTarget(engine->skeleton_sprite);
			int sprite_width = engine->GetDrawTargetWidth();
			int sprite_height = engine->GetDrawTargetHeight();

			engine->DrawDecal({ screen_width * 0.75f - sprite_width / 2.0f, screen_height / 2.0f - sprite_height / 2.0f }, engine->skeleton_decal);

			engine->SetDrawTarget(engine->player_sprite);
			sprite_width = engine->GetDrawTargetWidth();
			sprite_height = engine->GetDrawTargetHeight();

			engine->DrawDecal({ screen_width * 0.25f - sprite_width / 2.0f, screen_height / 2.0f - sprite_height / 2.0f }, engine->player_decal);
		}

	}

		engine->SetDrawTarget(nullptr);

		if (engine->GetKey(olc::Key::K0).bPressed)
		{
			player->interact_item(0);
		}
		else if (engine->GetKey(olc::Key::K1).bPressed)
		{
			player->interact_item(1);
		}
		else if (engine->GetKey(olc::Key::K2).bPressed)
		{
			player->interact_item(2);
		}
		else if (engine->GetKey(olc::Key::K3).bPressed)
		{
			player->interact_item(3);
		}
		else if (engine->GetKey(olc::Key::K4).bPressed)
		{
			player->interact_item(4);
		}


		draw_inventory(engine, player);
		//engine->_page_state = &PageState::fight;
}

void IntroPage::draw(Game* engine, float fElapsedTime, Player* player)
{

}

FightPage::FightPage()
{
	skeleton = new Enemy(5, 1, 1, 2, 3);
}

void FightPage::update(Game* engine, float fElapsedTime, Player* player)
{
	//player_fight(engine, player, skeleton);
	engine->Clear(olc::BLACK);

	int screen_width = engine->ScreenWidth();
	int screen_height = engine->ScreenHeight();

	engine->DrawDecal({ screen_width * 0.1f, screen_height * 0.5f }, engine->player_decal);

	engine->SetDrawTarget(engine->skeleton_sprite);
	int width = engine->GetDrawTargetWidth();
	int height = engine->GetDrawTargetHeight();
	engine->SetDrawTarget(nullptr);

	engine->DrawDecal({ screen_width * 0.9f - width * 0.5f, screen_height * 0.5f - height * 0.5f }, engine->skeleton_decal);
}

void FightPage::draw(Game* engine, float fElapsedTime, Player* player)
{

}

void ShopPage::update(Game* engine, float fElapsedTime, Player* player)
{

}