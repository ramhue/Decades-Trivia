#include "stdafx.h"
#include "correctScreen.h"

/*********************************************************
NAME:corectScreen::Show
DESCRIPTION: THIS FUNCTION LOADS FONT AND ADJUSTS THE 
			 SCREEN TO SHOW THE TEXT CORRECT AND PLACES
			 IT IN THE CORRECT POSITION.THEN IT LOOPS 
			 AND POLLS THE EVENT TO SEE IF THE USE MOUSE 
			 CLICKED,KEYPRESSED, OR IF THE USER CLOSED THE 
			 WINDOW. IF THE EVENT IS TRUE, THEN THE FUNCTION 
			 RETURNS AND THE USER GOES BACK TO THE PLAYING 
			 SCREEN 
************************************************************/

void correctScreen::Show(sf::RenderWindow& window) {

	sf::Font myFont;
	myFont.loadFromFile("BillionaireMediumGrunge.ttf");
	sf::Text MyText("CORRECT!", myFont, 200);
	
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
\				
				return;
			}
		}
		window.clear(sf::Color(50, 205, 50,255));
		window.draw(MyText);
		window.display();
	}

}
