#pragma once
#include "SFML\Graphics.hpp"
#include "questions.h"
#include "Player.h"
#include <list>


class playingScreen
{
public:
	enum AnswerResult {
		Nothing,correct,incorrect,pause
	};
	struct answerchoice {
	public:
		sf::Rect<int> rect;
		AnswerResult action;
	};

	AnswerResult showPlayingScreen(sf::RenderWindow&, questions& Decade00_09,player player);

private:
	AnswerResult GetMenuResponse(sf::RenderWindow& window);
	AnswerResult HandleChoice(int,int);
	std::list<answerchoice> _answerItems;
	int findCorrectAnswer(questions);
	//questions Decade00_09;
};