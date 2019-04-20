#include "stdafx.h"
#include "IncorrectScreen.h"

void IncorrectScreen::Show(sf::RenderWindow& window) {
	
	sf::Font myFont;
	myFont.loadFromFile("BillionaireMediumGrunge.ttf");
	sf::Text MyText("INCORRECT!", myFont, 200);
	float text_posX = (1024 - MyText.getLocalBounds().width) / 2;
	float text_posY = (768 - MyText.getLocalBounds().height) / 2;
	sf::Vector2f text_pos(text_posX, text_posX);
	MyText.setPosition(text_pos);
	

	sf::Event event;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::EventType::KeyPressed ||
				event.type == sf::Event::EventType::MouseButtonPressed ||
				event.type == sf::Event::EventType::Closed) {
				return;
			}
		}
		window.clear(sf::Color::Red);
		//window.draw(sprite);
		window.draw(MyText);
		window.display();
	}
}