#pragma once

#include <iostream>
#include <map>
#include <direct.h>
#include <time.h>
#include <string>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <IO.h>

using std::cout;
using std::cin;
using std::string;
using std::ios;
using std::fstream;
using std::map;
using std::endl;

//for conio
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13
#define ESC 27

// for printf
#define ARROW_LEFT 282
#define ARROW_DOWN 281
#define ARROW_UP 280

class Question
{
protected:
	int totalNumberOfAnswers;
	int numberOfCorrectAnswer;
	string questionStatement;
	map<int, string> answers;  // first - id of answer(starts from 1) | second - answer statement

public:

	Question();


	// =======================================================//



	void SetTotalNumberOfAnswers(int _numberOfAnswers);
	void SetNumberOfCorrectAnswer(int _numberOfAnswer);
	void SetQuestionStatement(string _questionStatement);

	int GetTotalNumberOfAnswers() const;
	int GetNumberOfCorrectAnswer() const;
	string GetQuestionStatement() const;
	map<int, string> GetAnswers() const;



	// =======================================================//

		/* To Add Answers */


	// Adds 1 answer
	// _pos = id of answer
	// Used in Test::AddQuestion() method
	void AddAnswer(int _pos, string _ans);

	// Has all needed user inputs inside
	// Used for testing
	void FillQuestionWithAnswers();



	// =======================================================//


	// To show question for admin
	void ShowQuestion() const;


	// Same as for admin, but no correct answer
	void ShowQuestionForGuest() const;




};
