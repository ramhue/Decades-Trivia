#include "stdafx.h"
#include "InputScreen.h"

void InputScreen::show(sf::RenderWindow& window, player& P1) {

	std::string str;
	sf::Text text;

	sf::Sprite MySprite;
	sf::Texture Mytexture;
	Mytexture.loadFromFile("images/BackgroundStuff.png");
	MySprite.setTexture(Mytexture);
	
	sf::Event event;
	sf::Font myFont;
	myFont.loadFromFile("BillionaireMediumGrunge.ttf");
	sf::Text title("Please Enter your name", myFont, 130);
	title.setPosition(100, 80);
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

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
	
			if (event.type == sf::Event::TextEntered) {
				if (event.text.unicode < 128 && event.text.unicode != 8) {
					
					if (str.size() == 8) {
						str.pop_back();
						str += static_cast<char>(event.text.unicode);
						text.setString(str);
						text.setFont(myFont);
						text.setPosition(350, 300);
						text.setCharacterSize(120);
						text.setFillColor(sf::Color::Yellow);
					}
					else {
						str += static_cast<char>(event.text.unicode);
						text.setString(str);
						text.setFont(myFont);
						text.setPosition(350, 300);
						text.setCharacterSize(120);
						text.setFillColor(sf::Color::Yellow);
					}
				}
				if (event.text.unicode == 8 && !str.empty()) {
					str.pop_back();
					text.setString(str);
					text.setFont(myFont);
					text.setPosition(350, 300);
					text.setCharacterSize(120);
					text.setFillColor(sf::Color::Yellow);
					window.clear();
					window.draw(MySprite);
					window.draw(title);
					window.draw(text);
					window.draw(MyExitbutton);
					window.draw(Next);
					window.display();

				}

				
			}
			
			window.clear();
			window.draw(MySprite);
			window.draw(title);
			window.draw(text);
			window.draw(MyExitbutton);
			window.draw(Next);
			window.display();
			if (event.type == sf::Event::EventType::MouseButtonPressed && !str.empty() ) {
				if (event.mouseButton.x < 650 && event.mouseButton.x >350 &&
					event.mouseButton.y < 650 && event.mouseButton.y > 550) {
					P1.setName(str);
					return;

				}
			}
			
		}
	}
}