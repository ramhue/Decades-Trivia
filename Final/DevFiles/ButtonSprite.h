#pragma once
#include "SFML\Graphics.hpp"


class ButtonSprite
{
	public:
	
		sf::Sprite getMenuButton();
		void setMenuText(std::string, int, int , int);
		sf::Text getMyText();
		void setMenuButton(int, int);
		
		 sf::Sprite MySprite;
		 sf::Text MyText;
		

};
