// triviaGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#pragma comment(lib,"user32.lib") 
#pragma comment(lib, "advapi32")
#include "Game.h"
#include "questions.h"

int main()
{

	Game::Start();
	
	return 0;
}

