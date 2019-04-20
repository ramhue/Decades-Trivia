#pragma once
#include <string>
#include "SFML\Graphics.hpp"
#include "questions.h"

class showText
{
public:
	std::string question;
	std::string answer;
	sf::Text setText(std::string);


private:

};

sf::Text showText::setText(std::string s) {
	sf::Font myfont;
	myfont.loadFromFile("BillionaireMediumGrunge.ttf");
	sf::Text text(s,myfont);
	text.setPosition(50, 350);
	return text;
}