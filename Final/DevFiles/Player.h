#pragma once
#include <string>

class player
{
public:
	std::string name;

	player();

	
	
	void updateScore(int score);
	int getScore();
	int getlives();
	void updateLives();
	void setName(std::string);
	void resetPlayer();

private:
	int numOfLives;
	int score;
};
