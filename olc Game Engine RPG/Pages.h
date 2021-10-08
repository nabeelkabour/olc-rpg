#ifndef PAGES_H
#define PAGES_H

#include "Enemy.h"
#include "UI.h"

class MainPage;
class NamePage;
class IntroPage;
class FightPage;

class PageState
{
public:
	static MainPage	main_menu;
	static NamePage name_page;
	static IntroPage intro;
	static FightPage fight;

	virtual ~PageState() {};
	virtual void update(Game* engine, float fElapsedTime, Player* player = nullptr) {};
	virtual void draw(Game* engine, float fElapsedTime, Player* player = nullptr) {};
};

class MainPage : public PageState
{
	UI::MouseButton button1;

public:
	MainPage();

	void update(Game* engine, float fElapsedTime, Player* player = nullptr) override;
	void draw(Game* engine, float fElapsedTime, Player* player = nullptr) override;
};

class NamePage : public PageState
{
public:
	void update(Game* engine, float fElapsedTime, Player* player = nullptr) override;
	void draw(Game* engine, float fElapsedTime, Player* player = nullptr) override;
};

class IntroPage : public PageState
{
	float text_alpha = 255;
	bool player_turn = true;
	Enemy* skeleton = nullptr;

public:
	IntroPage();

	void update(Game* engine, float fElapsedTime, Player* player = nullptr) override;
	void draw(Game* engine, float fElapsedTime, Player* player = nullptr) override;
};

class FightPage : public PageState
{
	Enemy* skeleton = nullptr;

public:
	FightPage();

	void update(Game* engine, float fElapsedTime, Player* player = nullptr) override;
	void draw(Game* engine, float fElapsedTime, Player* player = nullptr) override;
};

class ShopPage : public PageState
{
public:
	void update(Game* engine, float fElapsedTime, Player* player = nullptr) override;
	void draw(Game* engine, float fElapsedTime, Player* player = nullptr) override;
};

#endif
