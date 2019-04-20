#include "stdafx.h"
#include "MenuMain.h"
#include "ButtonSprite.h"

MenuMain::MenuResult MenuMain::Show(sf::RenderWindow& window) {
	
	
	//loading the font in from a file
	sf::Font MyFont;
	MyFont.loadFromFile("BillionaireMediumGrunge.ttf");

	//testing background for title
	sf::Texture backTest;
	backTest.loadFromFile("images/Q_button.png");
	sf::Sprite backButton(backTest);
	backButton.setPosition(50, 100);

	//loading the background texture and reating a sprite
	sf::Texture texture;
	texture.loadFromFile("images/Backgroundstuff.png");
	sf::Sprite sprite(texture);

	//Title text intialization and porsitioning
	sf::Text TitleText("Decades Trivia!", MyFont, 180);
	TitleText.setPosition(120, 70);

	//loading the button texture
	sf::Texture button;
	button.loadFromFile("images/button.png");

	//creating the button sprite
	sf::Sprite Mybutton(button); //play button
	sf::Sprite MyExitbutton(button); //exit button
	sf::Sprite HighScoreButton(button);
	
	//setting the button positions
	Mybutton.setPosition(350, 350);
	MyExitbutton.setPosition(350, 600);
	HighScoreButton.setPosition(350, 475);
	
	//creating the text objects for the menu buttons 
	sf::Text PlayButtonText;
	sf::Text ExitButtonText;
	sf::Text HighScoreText;
	
	//setting the font for the text
	PlayButtonText.setFont(MyFont); //setting the playbutton font
	ExitButtonText.setFont(MyFont); //setting exit button font
	HighScoreText.setFont(MyFont); //setting the font for High score button

	//setting the size for the play button text and exit button text and Title text
	PlayButtonText.setCharacterSize(60);
	ExitButtonText.setCharacterSize(60);
	HighScoreText.setCharacterSize(60);
	
	//setting the text from string
	PlayButtonText.setString("PLAY");
	ExitButtonText.setString("EXIT");
	HighScoreText.setString("HIGHSCORES");
	
	//getting the width and height of the text
	float width = PlayButtonText.getLocalBounds().width;
	float height = PlayButtonText.getLocalBounds().height;
	
	//calculating the middle of the button to draw text in the middle of button
	width = (300 - width)	/ 2; //calculationg the the empty space from the left
	height = (100 - height) / 4; //calculating  the empty space from the top
	
	//setting the position of the play button text by adding the the empty space to the start of the button 
	PlayButtonText.setPosition(350 + width , 350 + height );

	//using the same method as above for the exit button
	width = ExitButtonText.getLocalBounds().width;
	height = ExitButtonText.getLocalBounds().height;
	
	width = (300 - width) / 2;
	height = (100 - height) / 4;
	
	//setting the position of the exit button text
	ExitButtonText.setPosition(350 + width, 600 + height);
	
	//getting the bounds for height and width of the highscore text;
	width = HighScoreText.getLocalBounds().width;
	width = (300 - width) / 2;

	height = HighScoreText.getLocalBounds().height;
	height = (100 - height) / 4;

	//setting the position of the high Score text
	HighScoreText.setPosition(350 + width, 475 + height);

	MenuItem playButton;
	playButton.rect.top = 350;
	playButton.rect.height = 450;
	playButton.rect.left = 350;
	playButton.rect.width = 650;
	playButton.action = Play;
	
	MenuItem exitButton;
	exitButton.rect.left = 350;
	exitButton.rect.top = 600;
	exitButton.rect.width = 650;
	exitButton.rect.height = 700;
	exitButton.action = Exit;

	MenuItem highscorebutton;
	highscorebutton.rect.left = 350;
	highscorebutton.rect.width = 650;
	highscorebutton.rect.top = 475;
	highscorebutton.rect.height = 575;
	highscorebutton.action = Highscores;

	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);
	_menuItems.push_back(highscorebutton);
	
	window.clear();
	window.draw(sprite);
	window.draw(backButton);
	window.draw(TitleText);
	window.draw(Mybutton);
	window.draw(MyExitbutton);
	window.draw(HighScoreButton);
	window.draw(PlayButtonText);
	window.draw(ExitButtonText);
	window.draw(HighScoreText);

	window.display();

	return GetMenuResponse(window);
}

MenuMain::MenuResult MenuMain::HandleChoice(int x, int y) {
	
	std::list<MenuItem>::iterator it;
	for (it = _menuItems.begin(); it != _menuItems.end(); it++) {
		sf::Rect<int> menuItemRect = (*it).rect;
		if ( menuItemRect.height > y
			&& menuItemRect.top < y
			&& menuItemRect.left < x
			&& menuItemRect.width > x) {
				return (*it).action;
		}
	}
	return Nothing;
}

MenuMain::MenuResult MenuMain::GetMenuResponse(sf::RenderWindow& window) {
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
