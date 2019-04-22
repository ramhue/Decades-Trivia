#include "stdafx.h"
#include "questions.h"
/*******************************************************************
FUNCTION NAME: QUESTIONS (DEFAULT CONSTRUCTOR
PARAMETERS:NONE
OUTPUT:NONE
DESCRIPTION: THIS IS A DEFUALT CONSTRUCTOR THAT ALLOWS THE STRINGS AND 
			 THE DECADE STRINGS TO BE MADE.
********************************************************************/
questions::questions() {
	DecadeFiles temp;
	//temp.decade = "80s";
	//temp.file = "80s_questions.txt";
	//this->questionFiles.push_back(temp);
	temp.decade = "90s";
	temp.file = "90s_questions.txt";
	this->questionFiles.push_back(temp);
	temp.decade = "00S-09S";
	temp.file = "2000-2009questions.txt";
	this->questionFiles.push_back(temp);
}
/******************************************************************
FUNCTION NAME: OPENFILE
PARAMETERS: A SIMPLE STRING THAT REPREESETNS THE NAME OF THE TEXT 
			FILE TO BE READ 
OUTPUT: RETURNS THE FILE HANDLE USED TO OPEN THE FILE

DESCRIPTION:THIS FUCTION IS A HELPER FUNCTION THAT OPENS A FILE FOR
			THIS DATABASE CLASS THAT IS GOING TO BE READ AND THENN
			RETUNRS THE FILE HANDLER SO THAT OTHER FUCTIONS CAN USE T
			HE FILE
*******************************************************************/
std::fstream questions::openFile(std::string fileName) {
	std::fstream loadFile(fileName);
	return loadFile;
}
/******************************************************************
FUNCTIONM NAME:LOADALLQUESTONS
PARAMETERS:A FILE HANDLE OF A FILE THAT HAS BEEN OPENED AND IS READY
		   TO BE READ FROM 
OUTPUT: NONE

DESCRIPTION:THIS FUCTION LOADS THE FILE FROM THE FILE HANDLE THAT IS 
			PASSED INTO THE FUNCTION. FUNCTION PARSES EACEH LINE 
			BY THE "|" AS A DELIMENATOR AND THEN PUSHES IT INTO A 
			VECTOR CALLED WORDS. THEN WE ARRANGE THE DATA INTO THE 
			MYQUESTION OBJECT AND THEN LOADS THAT OBJECT INTO THE 
			QUESTIONS VECTOR. FINALLY THE QUESTIONS VECTOR IS THEN 
			SHUFFLED TO PRODUCE RANDOMNESS IN THE QUESTIONS.
*******************************************************************/
void questions::loadAllQuestions(std::fstream loadFile) {
	std::string line;
	MyQuestion single_question;
	std::vector <std::string> words;
	while (std::getline(loadFile, line, '|')) {
		if (line[0] == '\n') {
			line.erase(line.begin());
		}

		words.push_back(line);
	}
	while (!words.empty()) {
		single_question.correctAnswer = words.back();
		words.pop_back();
		for (int i = 0; i < 4; i++) {
			single_question.answers.push_back(words.back());
			words.pop_back();
		}
		std::random_shuffle(single_question.answers.begin(), single_question.answers.end());
		single_question.question = words.back();
		words.pop_back();
		allQuestions.push_back(single_question);
		single_question.answers.clear();
	}
	std::random_shuffle(allQuestions.begin(), allQuestions.end());
	loadFile.close();
}
/*******************************************************************
FUNCTION NAME: QUESTIONSFILERESET
PARAMETERS:NONE
OUTPUT:NONE
DESCRIPTION:THIS FUNCTION ACTUALLY RESETS THE VECTOR WITH THE FILES 
			FOR THE QUESTIONS FOR EACH DECADE. THIS IS CALLED IN THE 
			CASE THAT THE PLAYER EXITS THE GAMEAND WISHES TO RETURN 
			TO THE GAME FROM THE PAUSE SCREEN OR FROM GETTING A 
			GAMEOVER SCREEN
********************************************************************/
void questions::questionFileReset() {
	this->questionFiles.clear();
	DecadeFiles temp;
	temp.decade = "80s";
	temp.file = "80s_questions.txt";
	this->questionFiles.push_back(temp);
	temp.decade = "90s";
	temp.file = "90s_questions.txt";
	this->questionFiles.push_back(temp);
	temp.decade = "00S-09S";
	temp.file = "2000-2009questions.txt";
	this->questionFiles.push_back(temp);
}
void questions::showAllQuestions() {
	for (int i = 0; i < allQuestions.size(); i++) {
		std::cout << allQuestions[i].question << std::endl;
		for ( int j = 0; j < allQuestions[i].answers.size();j++){
			std::cout << allQuestions[i].answers[j] << std::endl;
		}
		std::cout << "Correct answer" << std::endl 
				  << allQuestions[i].correctAnswer << std::endl;
	}
}