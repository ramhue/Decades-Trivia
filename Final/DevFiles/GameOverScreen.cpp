#include "stdafx.h"
#include "GameOverScreen.h"

void GameOverScreen::show(sf::RenderWindow& window) {
	sf::Texture GameOver;
	GameOver.loadFromFile("images/BackgroundStuff.png");
	sf::Sprite background;
	background.setTexture(GameOver);
	
	sf::Font myFont;
	myFont.loadFromFile("BillionaireMediumGrunge.ttf");
	
	sf::Texture pen;
	pen.loadFromFile("images/penDie.png");
	sf::Sprite sprite;
	sprite.setTexture(pen);
	sprite.setPosition((1024 - (sprite.getLocalBounds().width))/ 2,(768-(sprite.getLocalBounds().height))/2);
	
	
	
	sf::Text GameoverText("GAMEOVER", myFont, 200);
	sf::Event event;
	
	float text_posX = (1024 - GameoverText.getLocalBounds().width) / 2;
	float text_posY = (768 - GameoverText.getLocalBounds().height) / 4;
	
	sf::Vector2f text_pos(text_posX, text_posY);
	
	GameoverText.setPosition(text_pos);
	GameoverText.setFillColor(sf::Color::Red);
	
	sf::Texture button;
	button.loadFromFile("images/button.png");
	sf::Text Next("Next", myFont, 60);

	//creating the button sprite
	sf::Sprite MyExitbutton(button); //exit button

	float width = Next.getLocalBounds().width;
	float height = Next.getLocalBounds().height;
	width = (300 - width) / 2; //calculationg the the empty space from the left
	height = (100 - height) / 4; //calculating  the empty space from the top

	Next.setPosition(350 + width, 550 + height);

	MyExitbutton.setPosition(350, 550);

	
	while(window.isOpen()) {

		window.clear();
		window.draw(background);
		window.draw(GameoverText);
		window.draw(MyExitbutton);
		window.draw(Next);
		window.draw(sprite);
		window.display();

		while (window.pollEvent(event)){
			if (event.type == sf::Event::EventType::MouseButtonPressed) {
				if (event.mouseButton.x < 650 && event.mouseButton.x >350 &&
					event.mouseButton.y < 650 && event.mouseButton.y > 550) {
					return;

				}
			}
			
		
			
		}
		
	}
}