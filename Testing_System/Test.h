#pragma once
#include "Question.h"

		/*		Represents File      */

class Test : public Question
{
private:
	int totalNumberOfQuestions;  // Set in FillTest() method

protected:
	map<int, Question> questions;  // int - id of question | Question - question itself

public:
	
	Test();


	//======================================================//


	void SetTotalNumberOfQuestions(int _num);
	int GetTotalNumberOfQuestions() const;


	//======================================================//



	// Adds 1 question to test
	// Used in FillTest() method
	void AddQuestion(int _pos);


	// Fills test with questions(totalNumberOfQuestions)
	// If number of questions is unknown asks user input
	// Main way to create test
	void FillTest();



	//======================================================//




	// For guest to take a test
	// Accepts test file name
	// --Answeres are shown 1 by 1
	// --Guest can move only forward through questions
	// --Correct answer is shown after answering question
	// --Shows number of correct answers at the end of the test
	// ADD: 1) Stop the test at any point
	//		2) Save stats at the end of test
	void GuestTakeTest(string _test_name);




	//======================================================//



	// Shows Test question with answers
	// Used only by admin
	void ShowTest();



	//======================================================//




	// Name of the test is Set by user (inside method)
	// Number of questions must be set before calling this method
	//
	// Writing sceme:
	//	1) (int)total number of questions(totalNumberOfQuestions)
	//  
	//	(loop)  
	//			2) (int)id of question (questions.first)
	//			3) (int)size of 'questionsStatement'(questions.second.questionStatement)
	//          4) (char*) question statement
	//          5) (int) total number of answers
	//
	//          (loop)
	//						6) (int) id of answers
	//						7) (int) size of answer
	//						8) (char*) answer
	//			(endloop)
	//			
	//			9) (int) number of correct answer
	//	(endloop)
	bool SaveTestToFile(string _path_to_directory);


	// Accepts name of the category + subject + name of test
	// Loads questions to questions map
	bool LoadTestFromFile(string _path_to_file);


};

