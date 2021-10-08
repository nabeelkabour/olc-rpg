#ifndef UI_H
#define UI_H

#include "Game.h"

namespace UI
{
	class MouseButton
	{
		int x_pos;
		int y_pos;
		int width;
		int height;

	public:
		MouseButton();
		MouseButton(int _x, int _y, int _width, int _height);

		bool check_pressed(Game* engine);
		void draw(Game* engine);
	};
}

#endif
