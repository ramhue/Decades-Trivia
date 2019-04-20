#include "stdafx.h"
#include "SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow& renderWindow){
	sf::Texture splash;
	if (!(splash.loadFromFile("images/SplashScreen2.jpg"))) {
		return;
	}
	
	sf::Sprite sprite(splash);

	sf::Event event;
	while (renderWindow.isOpen()){
		while (renderWindow.pollEvent(event)) {
			if (event.type == sf::Event::EventType::KeyPressed ||
				event.type == sf::Event::EventType::MouseButtonPressed ||
				event.type == sf::Event::EventType::Closed) {
				//renderWindow.close();
				return;
			}
		}
		renderWindow.clear();
		renderWindow.draw(sprite);
		renderWindow.display();
	}

}