#include "stdafx.h"
#include "Game.h"
#include "MenuMain.h"
#include "SplashScreen.h"
#include "questions.h"
#include "showText.h"
#include "playingScreen.h"
#include "IncorrectScreen.h"
#include "correctScreen.h"
#include "PauseScreen.h"
#include "Player.h"
#include "GameOverScreen.h"
#include "HighScoreScreen.h"
#include "highScores.h"
#include "InputScreen.h"
#include "WinScreen.h"

questions Decade00_09;
player player1;
HighScores highScores;

void Game::Start(void) {
	if (_gameState != Uninitialized)
		return;
	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Decades Trivia!");
	_gameState = Game::ShowingSplash;

	while(!IsExiting()){
		GameLoop();
	}
	_mainWindow.close();
}

bool Game::IsExiting() {
	if (_gameState == Game::Exiting) {
		return true;
	}
	else{
		return false;
	}
}

void Game::GameLoop() {
		switch (_gameState) {
			case Game::ShowingMenu: {
				ShowMenu();
				break;
			}
			case Game::ShowingSplash: {
				ShowSplashScreen();
				break;
			}
			case Game::Playing: {
				sf::Event currentEvent;
				// While in playing state this 
				while (_mainWindow.pollEvent(currentEvent)) {
					ShowPlay();
					

					if (currentEvent.type == sf::Event::Closed) {
						_gameState = Game::Exiting;
					}
					if (currentEvent.type == sf::Event::KeyPressed) {
						if (currentEvent.type == sf::Keyboard::Escape) {
							//ShowMenu();
						}
					}
				}
			break;
			}
			case Game::correct:{
				player1.updateScore(100);
				ShowCorrect();
				break;
			}
			case Game::incorrect:{
				ShowIncorrect();
				player1.updateLives();
				if (player1.getlives() == 0)
				{
					_gameState = Game::GameOver;
				}
				break;
			}
			case Game::Paused: {
				ShowPaused();
				break;
			}
			case Game::GameOver: {
				ShowGameOver();
				break;
			}
			case Game::HighScores: {
				ShowHighScores();
				break;
			}
			case Game::input: {
				ShowInput();
				break;
			}
			case Game::WON: {
				ShowWinScreen();
				break;
			}
		
		}
}
void Game::ShowHighScores() {
	HighScoreScreen highscore_Screen;
	if (highScores.highScoreList.empty()) {
		highScores.loadAllScores(highScores.openFile("highscores.txt"));
		std::cout << "" << std::set_new_handler;
	}
	highscore_Screen.show(_mainWindow, player1,highScores);
	_gameState = Game::ShowingMenu;
}
void Game::ShowSplashScreen() {
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = Game::ShowingMenu;
}
void Game::ShowPlay() {
	playingScreen playingScreen;

	if (Decade00_09.allQuestions.empty() && !Decade00_09.questionFiles.empty()) {
		Decade00_09.loadAllQuestions(Decade00_09.openFile(Decade00_09.questionFiles.back().file));
		Decade00_09.currentDecade = Decade00_09.questionFiles.back().decade;
		Decade00_09.questionFiles.pop_back();
	}
	else if (Decade00_09.allQuestions.empty() && Decade00_09.questionFiles.empty()) {
		_gameState = Game::WON;
		return;
	}
	playingScreen::AnswerResult result = playingScreen.showPlayingScreen(_mainWindow,Decade00_09,player1);
	switch (result)
	{
	case playingScreen::pause:
		_gameState = Game::Paused;
		break;
	case playingScreen::correct:
		_gameState = correct;
		break;
	case playingScreen::incorrect:
		_gameState = incorrect;
		break;
	/*default:w(9
		_gameState = Game::Playing;
		break;*/
	}
	
}
void Game::ShowMenu()
{
	MenuMain mainMenu;
	MenuMain::MenuResult result = mainMenu.Show(_mainWindow);
	switch (result)
	{
	case MenuMain::Exit:
		_gameState = Game::Exiting;
		break;
	case MenuMain::Play:
		_gameState = Game::Playing;
		break;
	case MenuMain::Highscores:
		_gameState = Game::HighScores;
		break;
	}
}
void Game::ShowGameOver() {
	GameOverScreen GameoverScreen;
	GameoverScreen.show(_mainWindow);
	_gameState = Game::input;
}
void Game::ShowIncorrect() {
	IncorrectScreen incorrectScreen;
	incorrectScreen.Show(_mainWindow);
	_gameState = Game::Playing;
}
void Game::ShowWinScreen() {
	WinScreen winScreen;
	winScreen.show(_mainWindow);
	Decade00_09.questionFileReset();
	_gameState = Game::input;
}
void Game::ShowCorrect(){
	correctScreen CorrectScreen;
	CorrectScreen.Show(_mainWindow);
	_gameState = Game::Playing;
}
void Game::ShowPaused() {
	PauseScreen pauseScreen;
	PauseScreen::PauseResult result = pauseScreen.Show(_mainWindow);
	switch (result)
	{
	case PauseScreen::Exit:
		Decade00_09.allQuestions.clear();
		Decade00_09.questionFiles.clear();
		Decade00_09.questionFileReset();
		player1.resetPlayer();
		_gameState = Game::ShowingMenu;
		break;
	case PauseScreen::Play:
		_gameState = Game::Playing;
		break;
	}
}
void Game::ShowInput() {
	InputScreen inputScreen;
	inputScreen.show(_mainWindow, player1);
	highScores.loadAllScores(highScores.openFile("highscores.txt"));
	highScores.convertPlayerInfo(player1);
	highScores.writeHighScores(highScores.openFile("highscores.txt"), player1);
	player1.resetPlayer();
	_gameState = Game::HighScores;
}
Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;

