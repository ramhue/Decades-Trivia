#include "stdafx.h"
#include "HighScores.h"
#include <string>
#include <fstream>

// Open score text file
std::fstream HighScores::openFile(std::string fileName){
	std::fstream loadFile;
	loadFile.open(fileName, std::fstream::in|std::fstream::out);
	return loadFile;
}

// load names and scores into a vector
void HighScores::loadAllScores(std::fstream loadFile){
	std::string line;
	std::vector <std::string> words;
	HighScorePlayer score;
	while (std::getline(loadFile, line, '|')){
		if (line[0] == '\n'||line[0] == '\r'){
			line.erase(line.begin());
		}
		words.push_back(line);
	}

	while (!words.empty()){
		
		score.Score = words.back();
		words.pop_back();

		score.playerName = words.back();
		words.pop_back();

		highScoreList.push_back(score);
	}

	loadFile.close();
}

// Sorts player scores so it displays highest first
void HighScores::sortPlayerinfo(){
	for (int i = 0; i < highScoreList.size() ; i++){
		for (int j = 0; j < highScoreList.size() - i - 1; j++){
			long long score1, score2;
			score1 =  std::stoi(highScoreList[j].Score);
			score2 = std::stoi(highScoreList[j + 1].Score);
			if (score1 > score2){
				std::swap(highScoreList[j + 1],highScoreList[j]);
			}
		}
	}
	while (highScoreList.size() > 10) {
		highScoreList.erase(highScoreList.begin());
	}
}
// Displays Scores for debugging purposes
void HighScores::ShowScores(){

	std::cout << "DISPLAY" << std::endl;
	sortPlayerinfo();
	for (int i = 0; i < highScoreList.size(); i++){
		std::cout << highScoreList[i].playerName << " ";
		std::cout << highScoreList[i].Score << std::endl;
	}
}

void HighScores::convertPlayerInfo(player P1) {
	HighScorePlayer P1_HighScore;
	P1_HighScore.playerName = P1.name;
	P1_HighScore.Score = std::to_string(P1.getScore());
	highScoreList.push_back(P1_HighScore);
	this->sortPlayerinfo();
	
}
void HighScores::writeHighScores(std::fstream loadFIle,player p1) {
	while (!highScoreList.empty()){
		std::string line = highScoreList.back().playerName + "|" +
			               highScoreList.back().Score + "|";
		loadFIle << line;
		highScoreList.pop_back();
		line.clear();
	}
	loadFIle.close();
}