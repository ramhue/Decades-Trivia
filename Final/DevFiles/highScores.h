#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Player.h"

class HighScores
{
public:
	struct HighScorePlayer
	{
		std::string playerName;
		std::string Score;
	};
	std::vector<HighScorePlayer> highScoreList;

	std::fstream openFile(std::string);
	void loadAllScores(std::fstream);
	void sortPlayerinfo();
	void ShowScores();
	void convertPlayerInfo(player);
	void writeHighScores(std::fstream,player);
};

