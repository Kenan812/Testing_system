#include "Question.h"

#pragma region Constructer


Question::Question()
{
	totalNumberOfAnswers = 0;
	questionStatement = "";
}


#pragma endregion


#pragma region Getters and Setters


void Question::SetTotalNumberOfAnswers(int _numberOfAnswers)
{
	totalNumberOfAnswers = _numberOfAnswers;
}

void Question::SetQuestionStatement(string _questionStatement)
{
	questionStatement = _questionStatement;
}

void Question::SetNumberOfCorrectAnswer(int _numberOfAnswer)
{
	numberOfCorrectAnswer = _numberOfAnswer;
}



int Question::GetTotalNumberOfAnswers() const
{
	return totalNumberOfAnswers;
}

string Question::GetQuestionStatement() const
{
	return questionStatement;
}

int Question::GetNumberOfCorrectAnswer() const
{
	return numberOfCorrectAnswer;
}

map<int, string> Question::GetAnswers() const
{
	return answers;
}


#pragma endregion


#pragma region To Add Answers


void Question::AddAnswer(int _pos, string _ans)
{
	answers.insert(std::make_pair(_pos, _ans));
}


// Has all needed user inputs inside
// Used for testing
void Question::FillQuestionWithAnswers()
{
	if (totalNumberOfAnswers == 0)
	{
		cout << "\nEnter number of answers: ";
		cin >> totalNumberOfAnswers;
	}

	string ans;
	cout << "Now enter answers:\n";
	getline(cin, ans);
	for (int i = 0; i < totalNumberOfAnswers; i++)
	{
		cout << "Enter Answer: ";
		getline(cin, ans);
		answers.insert(std::make_pair(i + 1, ans));
	}
}


#pragma endregion


#pragma region To Show Question


// To show question for admin
void Question::ShowQuestion() const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);

	cout << questionStatement << "\n";
	SetConsoleTextAttribute(hConsole, 15);

	for (auto e : answers)
	{
		cout << e.first << ") " << e.second << "\n";
	}

	cout << "Correct answer: " << numberOfCorrectAnswer << "\n";
	cout << endl;
}


// No correct answer
void Question::ShowQuestionForGuest() const
{
	 //question statement
	cout << questionStatement << "\n\n";
		
	// answers
	for (auto a : answers)
	{
		cout << a.first << ") " << a.second << "\n";
	}
}


#pragma endregion

