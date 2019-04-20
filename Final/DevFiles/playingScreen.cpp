/********************************************************************************
NAME: playingScreen.cpp
DATE:3/27/18
AUTHORS: RAMIRO HUERTA, AARON XAYMOUNTRY
PURPOSE: THIS CLASS AIDS THE GAME CLASS. THIS CLASS HANDLES ALL THE 
		 FEFATURES AND GRAPHICS FOR THE PLAYING STATE. THESE 
		 FEATURES ARE:
			-HANDLING OF LIVES SPRITES
			-LOADING IN FONT FOR TEXT
			-HANDLING OF BUTTONS FOR ANSWER CHOICES
			-HANDLING MOUSE CLICKS OF ANSWER CHOICES
			-FINDING POSITION OF MOUSE CLICKS
			-LOADING THE SCORE TEXT
			
*********************************************************************************/


#include "stdafx.h"
#include "playingScreen.h"
#include <string>
#include <vector>

/********************************************************************************
FUNCTION NAME: showPlayingScreen
AUTHORS: RAMIRO HUERTA, AARON XAYMOUNTRY
PARAMETERS: -A RENDER WINDOW OBJECT FROM THE NAMESPACE SF FROM THE SFML LIBRARY 
			 THAT RENDERS THE VIEW WINDOW TO DRAW ON.
			-A QUESTION OBJECT THAT CONTAINS THE QUESTIONS BEING ASKED AND DISPLAYED
			 AND THE ANSWERS TO THE QUESTIONS
			-A PLAYER OBJECT THAT CONTAINS THE PLAYERS SCORE, LIVES AND NAME 
OUTPUT: thIS FUNCTION RETURNS A ANSWERRESULT OBJECT

PURPOSE: THIS FUNCTION IS TO DISPLAY THE ANSWER BUTTONS, DISPLAY LIVES, DISPLAY 
		 SCORE, AND THE TEXT. IT RETURNS THE  
********************************************************************************/
playingScreen::AnswerResult playingScreen::showPlayingScreen(sf::RenderWindow& window, questions& Decade00_09, player player1) {
	//setting the font for everything
	sf::Font myFont;
	myFont.loadFromFile("BillionaireMediumGrunge.ttf");
	
	

	//heart (lives) sprite
	sf::Sprite HeartSprite;
	sf::Texture heart_texture;
	heart_texture.setSmooth(true);
	heart_texture.loadFromFile("images/heart_sprite.png");
	HeartSprite.setTexture(heart_texture);
	float heartSpritewidth = 43;

	//Lives text
	sf::Text LivesText("LIVES: ", myFont, 40);
	LivesText.setPosition(50, 30);
	LivesText.setFillColor(sf::Color::Red);

	sf::Sprite MySprite;
	sf::Texture Mytexture;
	Mytexture.loadFromFile("images/BackgroundStuff.png");
	MySprite.setTexture(Mytexture);

	//questions Decade00_09;
//	if (Decade00_09.allQuestions.empty()) {
//		DecaAde00_09.loadAllQuestions(Decade00_09.openFile("2000-2009questions.txt"));
	//}
	std::string question = Decade00_09.allQuestions.back().question;

 	

	sf::Text text(question, myFont, 60);
	text.setPosition(20, 100);
	sf::Text answer1, answer2, answer3, answer4;
	sf::Text Decade("DECADE: " + Decade00_09.currentDecade, myFont, 40);
	Decade.setPosition(350, 25);
	

	answer1.setString(Decade00_09.allQuestions.back().answers[0]);
	answer2.setString(Decade00_09.allQuestions.back().answers[1]);
	answer3.setString(Decade00_09.allQuestions.back().answers[2]);
	answer4.setString(Decade00_09.allQuestions.back().answers[3]);

	int answerIndex = playingScreen::findCorrectAnswer(Decade00_09);

	answer1.setFont(myFont);
	answer2.setFont(myFont);
	answer3.setFont(myFont);
	answer4.setFont(myFont);

	answer1.setCharacterSize(40);
	answer2.setCharacterSize(40);
	answer3.setCharacterSize(40);
	answer4.setCharacterSize(40);


	float width = answer1.getLocalBounds().width;
	width = (300 - width) / 2;
	
	answer1.setPosition(150 + width, 425);
	
	width = answer2.getLocalBounds().width;
	width = (300 - width) / 2;
	answer2.setPosition(600 + width, 425);

	width = answer3.getLocalBounds().width;
	width = (300 - width) / 2;
	answer3.setPosition(150 + width, 550);

	width = answer4.getLocalBounds().width;
	width = (300 - width) / 2;
	answer4.setPosition(600 + width, 550);


	window.clear();
	window.draw(MySprite);

	answerchoice answer_1;
	answerchoice answer_2;
	answerchoice answer_3;
	answerchoice answer_4;
	answerchoice paused;

	answer_1.rect.left = 150;
	answer_1.rect.width = 450;
	answer_1.rect.top = 400;
	answer_1.rect.height = 500;

	if (answerIndex == 1) {
		answer_1.action = correct;
	}
	else
		answer_1.action = incorrect;

	answer_2.rect.left = 600;
	answer_2.rect.width = 900;
	answer_2.rect.top = 400;
	answer_2.rect.height = 500;

	if (answerIndex == 2) {
		answer_2.action = correct;
	}
	else
		answer_2.action = incorrect;

	answer_3.rect.left = 150;
	answer_3.rect.width = 450;
	answer_3.rect.top = 525;
	answer_3.rect.height = 625;
	
	if (answerIndex == 3) {
		answer_3.action = correct;
	}
	else
		answer_3.action = incorrect;
	
	answer_4.rect.top = 525;
	answer_4.rect.height = 625;
	answer_4.rect.left = 600;
	answer_4.rect.width = 900;

	if (answerIndex == 4) {
		answer_4.action = correct;
	}
	else
		answer_4.action = incorrect;

	_answerItems.push_back(answer_1);
	_answerItems.push_back(answer_2);
	_answerItems.push_back(answer_3);
	_answerItems.push_back(answer_4);

	sf::Texture answerButton;
	answerButton.loadFromFile("images/button.png");
	
	sf::Texture questionBackground;
	questionBackground.loadFromFile("images/Q_button.png");

	sf::Sprite ButtonSprite(answerButton);
	ButtonSprite.setPosition(150, 400);

	sf::Sprite QuestionSprite(questionBackground);
	QuestionSprite.setPosition(59,99);

	//drawing temporary buttun for pause
	sf::Texture pauseButton;
	pauseButton.loadFromFile("images/button_Pause.png");
	sf::Sprite pauseSprite(pauseButton);
	pauseSprite.setPosition(900,30);
	
	paused.rect.top = 30;
	paused.rect.height = 70;
	paused.rect.left = 900;
	paused.rect.width = 950;
	paused.action = pause;
	_answerItems.push_back(paused);

	std::string score = std::to_string (player1.getScore());
	sf::Text Score("SCORE: " + score, myFont,40);
	Score.setPosition(650, 25);
	Score.setFillColor(sf::Color::Cyan);
	
	//drawing all answer buttons and updating locations
	window.draw(MySprite);
	window.draw(QuestionSprite);
	window.draw(Decade);
	window.draw(ButtonSprite);
	window.draw(pauseSprite);
	ButtonSprite.setPosition(150, 525);
	window.draw(text);
	window.draw(ButtonSprite);
	ButtonSprite.setPosition(600, 400);
	window.draw(ButtonSprite);
	ButtonSprite.setPosition(600, 525);
	window.draw(ButtonSprite);
	window.draw(Score);
	


	window.draw(answer1);
	window.draw(answer2);
	window.draw(answer3);
	window.draw(answer4);
	window.draw(LivesText);
	for (int i = 0; i < player1.getlives(); i++) {
		HeartSprite.setPosition(heartSpritewidth*i+40+LivesText.getLocalBounds().width,40);
		window.draw(HeartSprite);
		
	}
	
	window.display();
	
	if (Decade00_09.allQuestions.empty()) {
		std::cout << "Im Empty" << std::endl;
	}
	AnswerResult result = GetMenuResponse(window);
	if (result != Nothing && result != pause) {
		Decade00_09.allQuestions.pop_back();
	}
	return result;
}
/**********************************************************************************
FUNCTION NAME: HandleChoice
PARAMETERS: -INT X WHICH CORRESPONSEDS WITH THE X-COORDINATE WHERE THE USER CLICKED
			 THIER MOUSES IN THE CORRESPONDING 2-D SPACE
			-INT Y WHICH CORRESPONSEDS TO THE Y-COMPONENET WHERE THE USER CLICKED 
			 THIER MOUSE IN A 2-D SPACE
OUTPUT: THIS FUNCTION RETURNS A ANSWER THAT 

**********************************************************************************/
playingScreen::AnswerResult playingScreen::HandleChoice(int x, int y) {
	std::list<answerchoice>::iterator it;
	for (it = _answerItems.begin(); it != _answerItems.end(); it++) {
		sf::Rect<int> answerItemRect = (*it).rect;
		if (answerItemRect.height > y
			&& answerItemRect.top < y
			&& answerItemRect.left < x
			&& answerItemRect.width > x) {
			
			return (*it).action;
		}
	}
	return Nothing;
}
/******************************************************************************************
FUNCTION NAME:GetMenuResponse
PARAMETERS: A RENDERWINDOW OBJECT 
OUTPUT: ANSWERRESULT FROM THE PLAYINGSCREEN CLASS. 
PURPOSE: THE PURPOSE OF THIS FUNCTION IS TO GET THE RESPONSE TO SEND TO THE GAME TO DETERMINE 
		 WHICH STATE TO GO TO NEXT. THIS FUNCTION IS CALLED WHEN A MOUSE BUTTON IS PRESSED
******************************************************************************************/

playingScreen::AnswerResult playingScreen::GetMenuResponse(sf::RenderWindow& window) {
	sf::Event answerEvent;
	while (true) {
		while (window.pollEvent(answerEvent)) {
			if (answerEvent.type == sf::Event::MouseButtonPressed) {
				return HandleChoice(answerEvent.mouseButton.x,answerEvent.mouseButton.y);
			}
		}
	}
}
/**********************************************************************************************
FUNCTION NAME: findCorrectAnswer
PARAMETERS: a QUESTIONS OBJECT THAT HOLDS ALL THE QUESTIONS
OUTOUT: RETURNS AN INT THAT CORRESPONDING ANSWER TO CHECK AGAINST THE CORRECT ANSWERER.
PURPOSE: TO FIND OUT WHICH ANSWER IS THE CORRECT ANSWER TO THE QUESTION SO THAT WE CAN CHECK IT
		 TO SEE IF THE USER CORRECTLY CHOSE THE CORRECT RESPONSE 
***********************************************************************************************/
int playingScreen::findCorrectAnswer(questions Myquestions) {

	if (Myquestions.allQuestions.back().answers[0] == Myquestions.allQuestions.back().correctAnswer) {
		return 1;
	}
	if (Myquestions.allQuestions.back().answers[1] == Myquestions.allQuestions.back().correctAnswer) {
		return 2;
	}
	if (Myquestions.allQuestions.back().answers[2] == Myquestions.allQuestions.back().correctAnswer) {
		return 3;
	}
	if (Myquestions.allQuestions.back().answers[3] == Myquestions.allQuestions.back().correctAnswer) {
		return 4;
	}
	
}