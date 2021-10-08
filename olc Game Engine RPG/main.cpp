#include "olcPixelGameEngine.h"
#include "Game.h"
#include "Startup.h"
#include "Player.h"

int main()
{
	Game game;

	if (game.Construct(480, 270, 2, 2))
		game.Start();

	return 0;
}