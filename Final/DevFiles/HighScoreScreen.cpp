#include "stdafx.h"
#include "HighScoreScreen.h"
#include "highScores.h"
#include "Thor\Animations\Animator.hpp"

void HighScoreScreen::show(sf::RenderWindow& window, player& player1,HighScores& highScores) {
	while (window.isOpen()) {
	
	highScores.loadAllScores(highScores.openFile("highscores.txt"));
	highScores.sortPlayerinfo();

	int  num = 1;
	sf::Font myFont;
	myFont.loadFromFile("BillionaireMediumGrunge.ttf");
	sf::Text TitleText("HIGHSCORES", myFont, 80);
	TitleText.setPosition(350, 0);
	TitleText.setFillColor(sf::Color::Yellow);
	sf::Text continueText("press any key to continue", myFont, 50);
	continueText.setPosition(325, 650);
	

	sf::Texture mytexture;
	mytexture.loadFromFile("images/Backgroundstuff.png");
	sf::Sprite esprite;
	esprite.setTexture(mytexture);

	const float EMPTY_SPACE = 25.0;
	window.clear();
	

	sf::Vector2f NameCoordinates;
	NameCoordinates.x = 480;
	NameCoordinates.y = TitleText.getLocalBounds().height + EMPTY_SPACE*2;

	sf::Vector2f ScoreCoordinates;
	ScoreCoordinates.x = 750;
	ScoreCoordinates.y = TitleText.getLocalBounds().height + EMPTY_SPACE*2;

	sf::Vector2f RankCoordinates;
	RankCoordinates.x = 200;
	RankCoordinates.y = TitleText.getLocalBounds().height + EMPTY_SPACE * 2;

	while (!(highScores.highScoreList.empty())) {


		sf::Text PlayerNameText(highScores.highScoreList.back().playerName, myFont, 40);
		sf::Text ScoreText(highScores.highScoreList.back().Score, myFont, 40);
		sf::Text Rank(std::to_string(num), myFont, 40);
		
		PlayerNameText.setPosition(NameCoordinates);
		ScoreText.setPosition(ScoreCoordinates);
		Rank.setPosition(RankCoordinates);

		NameCoordinates.y += (PlayerNameText.getGlobalBounds().height+EMPTY_SPACE);
		ScoreCoordinates.y += (PlayerNameText.getGlobalBounds().height + EMPTY_SPACE);
		RankCoordinates.y += (PlayerNameText.getGlobalBounds().height + EMPTY_SPACE);
		
		highScores.highScoreList.pop_back();
		num++;

		

		window.draw(PlayerNameText);
		window.draw(ScoreText);
		window.draw(Rank);
		window.draw(continueText);
	}
	
		
	sf::Event event;

		
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::EventType::KeyPressed ||
					event.type == sf::Event::EventType::MouseButtonPressed ||
					event.type == sf::Event::EventType::Closed) {
					return;
				}
			}
			window.draw(esprite);
			window.draw(TitleText);
			window.display();
	

		
	}
}

