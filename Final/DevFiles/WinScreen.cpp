#include "stdafx.h"
#include "WinScreen.h"

void WinScreen::show(sf::RenderWindow& window) {
	
		sf::Texture back;
		back.loadFromFile("images/BackgroundStuff.png");
		sf::Sprite background;
		background.setTexture(back);


		sf::Font myFont;
		myFont.loadFromFile("BillionaireMediumGrunge.ttf");

		sf::Text WinText("Congratulations", myFont, 200);
		sf::Text Wintext2("You have answered all the questions", myFont, 80);

		float text_posX = (1024 - WinText.getLocalBounds().width) / 2;
		float text_posY = (768/4);
		float text_posY2;
		sf::Vector2f text_pos(text_posX, text_posY);
		
		WinText.setPosition(text_pos);
		WinText.setFillColor(sf::Color::Cyan);

		text_posY2 = 100;
		sf::Vector2f text_pos2(text_posX, text_posY2);

		Wintext2.setPosition(text_pos2);
		Wintext2.setFillColor(sf::Color::Yellow);

		while (window.isOpen()) {
		
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::EventType::KeyPressed ||
				event.type == sf::Event::EventType::MouseButtonPressed ||
				event.type == sf::Event::EventType::Closed) {
				return;
			}
		}
		window.clear();
		window.draw(background);
		window.draw(WinText);
		window.draw(Wintext2);
		window.display();


	}
}