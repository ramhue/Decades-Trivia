#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "ButtonSprite.h"
#include <list>

class PauseScreen {

public:
	enum PauseResult {
		Nothing, Exit, Play
	};

	struct PauseItem {
	public:
		sf::Rect<int> rect;
		PauseResult action;
	};

	PauseResult Show(sf::RenderWindow& window);

private:
	PauseResult GetMenuResponse(sf::RenderWindow& window);
	PauseResult HandleChoice(int x, int y);
	std::list<PauseItem> _pauseItems;
};