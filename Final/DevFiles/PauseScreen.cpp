#include "stdafx.h"
#include "PauseScreen.h"

PauseScreen::PauseResult PauseScreen::Show(sf::RenderWindow& window) {
	
	//loading the font in from a file
	sf::Font MyFont;
	MyFont.loadFromFile("BillionaireMediumGrunge.ttf");

	//loading the background texture and reating a sprite
	sf::Texture texture;
	texture.loadFromFile("images/Backgroundstuff.png");
	sf::Sprite sprite(texture);

	//Title text intialization and positioning
	sf::Text TitleText("PAUSE", MyFont, 150);
	float Pausewidth = (1024 - TitleText.getLocalBounds().width)/2;
	float PausedHeight = (768 - TitleText.getLocalBounds().height) / 4;
	TitleText.setPosition(Pausewidth,  PausedHeight);

	//loading the button texture
	sf::Texture button;
	button.loadFromFile("images/button.png");

	//creating the button sprite
	sf::Sprite Mybutton(button); //play button
	sf::Sprite MyExitbutton(button); //exit button

									 //setting the button positions
	Mybutton.setPosition(350, 400);
	MyExitbutton.setPosition(350, 550);

	//creating the text objects for the menu buttons 
	sf::Text PlayButtonText;
	sf::Text ExitButtonText;

	//setting the font for the text
	PlayButtonText.setFont(MyFont); //setting the playbutton font
	ExitButtonText.setFont(MyFont); //setting exit button font

	//setting the size for the play button text and exit button text and Title text
	PlayButtonText.setCharacterSize(60);
	ExitButtonText.setCharacterSize(60);
	

	//setting the text from string
	PlayButtonText.setString("RESUME");
	ExitButtonText.setString("EXIT");

	//setting the positiion of the title
//	TitleText.setPosition(205, 125);

	//getting the width and height of the text
	float width = PlayButtonText.getLocalBounds().width;
	float height = PlayButtonText.getLocalBounds().height;

	//calculating the middle of the button to draw text in the middle of button
	width = (300 - width) / 2; //calculationg the the empty space from the left
	height = (100 - height) / 4; //calculating  the empty space from the top

								 //setting the position of the play button text by adding the the empty space to the start of the button 
	PlayButtonText.setPosition(350 + width, 400 + height);

	//using the same method as above for the exit button
	width = ExitButtonText.getLocalBounds().width;
	height = ExitButtonText.getLocalBounds().height;

	width = (300 - width) / 2;
	height = (100 - height) / 4;

	//setting the position of the exit button
	ExitButtonText.setPosition(350 + width, 550 + height);

	PauseItem playButton;
	playButton.rect.top = 400;
	playButton.rect.height = 500;
	playButton.rect.left = 350;
	playButton.rect.width = 650;
	playButton.action = Play;

	PauseItem exitButton;
	exitButton.rect.left = 350;
	exitButton.rect.top = 550;
	exitButton.rect.width = 650;
	exitButton.rect.height = 650;
	exitButton.action = Exit;

	_pauseItems.push_back(playButton);
	_pauseItems.push_back(exitButton);

	window.clear();
	window.draw(sprite);
	window.draw(TitleText);
	window.draw(Mybutton);
	window.draw(MyExitbutton);
	window.draw(PlayButtonText);
	window.draw(ExitButtonText);
	window.display();

	return GetMenuResponse(window);
}

PauseScreen::PauseResult PauseScreen::HandleChoice(int x, int y) {

	std::list<PauseItem>::iterator it;
	for (it = _pauseItems.begin(); it != _pauseItems.end(); it++) {
		sf::Rect<int> pauseItemRect = (*it).rect;
		if (pauseItemRect.height > y
			&& pauseItemRect.top < y
			&& pauseItemRect.left < x
			&& pauseItemRect.width > x) {
			return (*it).action;
		}
	}
	return Nothing;
}

PauseScreen::PauseResult PauseScreen::GetMenuResponse(sf::RenderWindow& window) {
	sf::Event menuEvent;
	while (true) {
		while (window.pollEvent(menuEvent)) {
			if (menuEvent.type == sf::Event::MouseButtonPressed) {
				return HandleChoice(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
			if (menuEvent.type == sf::Event::Closed) {
				return Exit;
			}
		}
	}
}
