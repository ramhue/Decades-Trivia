#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "ButtonSprite.h"
#include <list>

class MenuMain {

public:
	enum MenuResult {
		Nothing, Exit, Play, Highscores
	};

	struct MenuItem {
	public:
		sf::Rect<int> rect;
		MenuResult action;
	};

	MenuResult Show(sf::RenderWindow& window);

private:
	MenuResult GetMenuResponse(sf::RenderWindow& window);
	MenuResult HandleChoice(int x, int y);
	std::list<MenuItem> _menuItems;
};