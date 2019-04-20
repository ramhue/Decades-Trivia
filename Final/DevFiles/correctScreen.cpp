#include "stdafx.h"
#include "correctScreen.h"

void correctScreen::Show(sf::RenderWindow& window) {
	/*sf::Texture splash;
	if (!(splash.loadFromFile("images/image.png"))) {
		return;
	}*/
	sf::Font myFont;
	myFont.loadFromFile("BillionaireMediumGrunge.ttf");
	sf::Text MyText("CORRECT!", myFont, 200);
	
	float text_posX = (1024 - MyText.getLocalBounds().width) / 2;
	float text_posY = (768 - MyText.getLocalBounds().height) / 2;
	sf::Vector2f text_pos(text_posX, text_posX);
	MyText.setPosition(text_pos);
	//sf::Sprite sprite(splash);

	sf::Event event;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::EventType::KeyPressed ||
				event.type == sf::Event::EventType::MouseButtonPressed ||
				event.type == sf::Event::EventType::Closed) {
				//renderWindow.close();
				
				return;
			}
		}
		window.clear(sf::Color(50, 205, 50,255));
		//window.draw(sprite);
		window.draw(MyText);
		window.display();
	}

}
