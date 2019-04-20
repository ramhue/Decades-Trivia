#include "stdafx.h"
#include "Player.h"

player::player()
{
	numOfLives = 3;
	score = 0;
	name = "TOM";
}
void player::updateScore(int points) {
	score += points;
}

int player::getScore() {
	return score;
}
int player::getlives() {
	return numOfLives;
}
void player::updateLives() {
	numOfLives--;
}
void player::setName(std::string myName) {
	name = myName;
}
void player::resetPlayer() {
	numOfLives = 3;
	score = 0;
	name = "TOM";
}