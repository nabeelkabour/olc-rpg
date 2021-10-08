#include "UI.h"

UI::MouseButton::MouseButton(int _x, int _y, int _width, int _height) : x_pos { _x },
		y_pos{ _y }, width{ _width }, height{ _height }
{}

UI::MouseButton::MouseButton() {}

bool UI::MouseButton::check_pressed(Game* engine)
{
	if (engine->GetMouse(0).bPressed)
	{
		int mouse_x = engine->GetMouseX();
		int mouse_y = engine->GetMouseY();

		if (mouse_x >= x_pos and mouse_x <= (x_pos + width) and mouse_y >= y_pos and mouse_y <= (y_pos + height))
		{
			return true;
		}
	}
	
	return false;
}

void UI::MouseButton::draw(Game* engine)
{
	engine->FillRect(x_pos, y_pos, width, height);
}