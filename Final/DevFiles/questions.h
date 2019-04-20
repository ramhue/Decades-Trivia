#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class questions
{
public:
	struct MyQuestion{
		std::string question;
		std::vector <std::string> answers;
		std::string correctAnswer;
	};
	struct DecadeFiles {
		std::string decade;
		std::string file;
	};
	void showAllQuestions(); // only for debugging purposes
	void loadAllQuestions(std::fstream);
	std::fstream openFile(std::string);
	void questionFileReset();
	
	std::vector <MyQuestion> allQuestions;
	std::vector<DecadeFiles> questionFiles;
	std::string currentDecade;
	
	
	
	questions();

};

