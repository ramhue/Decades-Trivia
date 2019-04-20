#pragma once
#include "stdafx.h"
#include "questions.h"

class Game{

public:
	static void Start();
private:

	static bool IsExiting();
	static void GameLoop();
	static void ShowSplashScreen();
	static void ShowMenu();
	static void ShowPlay();
	static void ShowCorrect();
	static void ShowIncorrect();
	static void ShowPaused();
	static void ShowGameOver();
	static void ShowHighScores();
	static void ShowInput();
	static void ShowWinScreen();

	enum GameState {
		Uninitialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting , correct, 
		incorrect, GameOver, HighScores,input,WON
	};

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
	
};