#include "Test.h"

#pragma region Constructer


Test::Test()
{
	totalNumberOfQuestions = 0;
}


#pragma endregion



#pragma region Getters and Setters


void Test::SetTotalNumberOfQuestions(int _num)
{
	totalNumberOfQuestions = _num;
}

int Test::GetTotalNumberOfQuestions() const
{
	return totalNumberOfQuestions;
}


#pragma endregion



#pragma region To Add Questiions


// Adds 1 question to test
// Used in FillTest() method
void Test::AddQuestion(int _pos)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	Question question;

		/* Set question statement */
	string q;
	cout << "Enter question statement: ";
	SetConsoleTextAttribute(hConsole, 14);
	getline(cin, q);
	SetConsoleTextAttribute(hConsole, 15);

	question.SetQuestionStatement(q);



		/* Set number of answers */
	int num;
	cout << "\nEnter number of answers in question: ";
	SetConsoleTextAttribute(hConsole, 14);
	cin >> num;
	SetConsoleTextAttribute(hConsole, 15);

	question.SetTotalNumberOfAnswers(num);



		/* Set answers */
	string ans;
	cin.ignore();
	cout << "\n\tNow enter answers\n\n";
	for (int i = 0; i < question.GetTotalNumberOfAnswers(); i++)
	{
		
		cout << "Enter Answer: " << i + 1 << ") ";
		SetConsoleTextAttribute(hConsole, 14);
		getline(cin, ans);
		SetConsoleTextAttribute(hConsole, 15);

		question.AddAnswer(i + 1, ans);
	}



		/* Set correct answer number */
	cout << "\nEnter number of correct answer: ";
	SetConsoleTextAttribute(hConsole, 14);
	cin >> num;
	SetConsoleTextAttribute(hConsole, 15);

	question.SetNumberOfCorrectAnswer(num);



		/* Adding question to question map */
	questions.insert(std::make_pair(_pos, question));

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\nQuestion Added\n";
	SetConsoleTextAttribute(hConsole, 15);
	system("pause");
	cin.ignore();
}


// Fills test with questions(totalNumberOfQuestions)
// If number of questions is unknown asks user input
void Test::FillTest()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	int key;

	// Possible user choice 
	bool add = true;
	bool exit = false;
	system("cls");


	SetConsoleTextAttribute(hConsole, 12);
	cout << "\n\t\tAdding new test\n\n";
	SetConsoleTextAttribute(hConsole, 15);


	if (totalNumberOfQuestions == 0)
	{
		cout << "Enter number of questions in test: ";
		SetConsoleTextAttribute(hConsole, 14);
		cin >> totalNumberOfQuestions;
		SetConsoleTextAttribute(hConsole, 15);
		cin.ignore();
	}

	for (int i = 0; i < totalNumberOfQuestions; i++)
	{
		system("cls");
	

		SetConsoleTextAttribute(hConsole, 12);
		cout << "\n\t\tAdding new test\n\n";
		SetConsoleTextAttribute(hConsole, 15);
		
		cout << "\tQuestion #";
		SetConsoleTextAttribute(hConsole, 12);
		cout << i + 1 << "\n\n";
		SetConsoleTextAttribute(hConsole, 15);


		AddQuestion(i + 1);
	}
}


#pragma endregion



#pragma region To take a test

// For guest to take a test
// For more info look at Test.h
void Test::GuestTakeTest(string _test_name)
{
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int number_of_correct_questions = 0;

	for (auto q : questions)
	{
			/* Intro */

		SetConsoleTextAttribute(hConsole, 12);
		cout << "\n\t\t" << _test_name << "\n\n";
		SetConsoleTextAttribute(hConsole, 15);
		
		cout << "\tQuestion #";
		SetConsoleTextAttribute(hConsole, 12);
		cout << q.first << "\n\n";
		SetConsoleTextAttribute(hConsole, 15);



			/* Question content */

		q.second.ShowQuestionForGuest();
		

			/* Taking user input(answer) */

		int a;
		cout << "\nEnter correct answer: ";
		SetConsoleTextAttribute(hConsole, 14);
		cin >> a;
		SetConsoleTextAttribute(hConsole, 15);

		
		// user answer was correct
		if (a == q.second.GetNumberOfCorrectAnswer())
		{
			SetConsoleTextAttribute(hConsole, 10);
			cout << "\nCorrect!\n";
			SetConsoleTextAttribute(hConsole, 15);
			number_of_correct_questions++;
		}

		// user answer was incorrect
		else
		{
			SetConsoleTextAttribute(hConsole, 12);
			cout << "\nIncorrect!\n";
			SetConsoleTextAttribute(hConsole, 15);
			cout << "Correct answer: ";
			SetConsoleTextAttribute(hConsole, 12);
			cout << q.second.GetNumberOfCorrectAnswer() << "\n";
			SetConsoleTextAttribute(hConsole, 15);

		}

		system("pause");
		system("cls");
	}

	system("cls");


		/* Display results */
	SetConsoleTextAttribute(hConsole, 12);
	cout << "\n\t\tResults\n\n";

	// number of correct questions
	SetConsoleTextAttribute(hConsole, 15);
	cout << "Number of correct questions: ";
	SetConsoleTextAttribute(hConsole, 11);
	cout << number_of_correct_questions << "/" << totalNumberOfQuestions << "\n";


	// % of corrct questions
	SetConsoleTextAttribute(hConsole, 15);
	cout << "% of correct questions: ";
	SetConsoleTextAttribute(hConsole, 11);
	cout << ((float)number_of_correct_questions / (float)totalNumberOfQuestions) * 100 << "%" << "\n";


	// Grade
	SetConsoleTextAttribute(hConsole, 15);
	cout << "Grade: ";
	SetConsoleTextAttribute(hConsole, 11);
	cout << (round)(12.0 * ((float)number_of_correct_questions / (float)totalNumberOfQuestions)) << "\n";
	SetConsoleTextAttribute(hConsole, 15);
	system("pause");
}

#pragma endregion



#pragma region To Show Test(For admin)


// Shows Test question with answers
void Test::ShowTest()
{
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	cout << "\n\t\tTest content\n\n";
	SetConsoleTextAttribute(hConsole, 15);

	int i = 0;
	for (auto e : questions)
	{
		cout << "\t" << e.first << ") ";
		e.second.ShowQuestion();
		cout << "\n";
		i++;
	}
}


#pragma endregion



#pragma region To load and Save test


// Read more info in Test.h
bool Test::SaveTestToFile(string _path_to_directory)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	//cin.ignore();

	string test_save_name;
	

	cout << "\nEnter test name: ";
	SetConsoleTextAttribute(hConsole, 14);
	getline(cin, test_save_name);
	SetConsoleTextAttribute(hConsole, 15);

	_path_to_directory += test_save_name;


	fstream file(_path_to_directory, ios::out | ios::binary | ios::app);
	try
	{
		if (!file) throw "File not open for write";



		//===================================================================

		int length;

		// 1) writing total number of questions
		file.write((char*)&totalNumberOfQuestions, sizeof(totalNumberOfQuestions));


		for (auto q : questions)
		{
			// 2) writing id of question 
			file.write((char*)&q.first, sizeof(q.first));


			// 3) writing size of question statement
			string q_s = q.second.GetQuestionStatement();
			length = q_s.length();
			file.write((char*)&length, sizeof(length));


			// 4) writing question statement 
			file.write(q_s.c_str(), length * sizeof(char));


			// 5) writing total number of answers
			int t_a = q.second.GetTotalNumberOfAnswers();
			file.write((char*)&t_a, sizeof(t_a));



			for (auto a : q.second.GetAnswers())
			{

				// 6) writing id of an answer
				file.write((char*)&a.first, sizeof(a.first));

		
				// 7) writing size of answer
				string ans = a.second;
				length = ans.length();
				file.write((char*)&length, sizeof(length));


				// 8) writing answer
				file.write(ans.c_str(), length * sizeof(char));
			}


			// 9) writing number of correct answer
			int c_a = q.second.GetNumberOfCorrectAnswer();
			file.write((char*)&c_a, sizeof(c_a));

		}


		//===================================================================


		file.close();
		return true;
	}


	catch (const char* c)
	{
		cout << "Error: " << c << endl;
		return false;
	}


	return false;
}


// Read more info in Test.h
bool Test::LoadTestFromFile(string _path_to_file)
{
	fstream file(_path_to_file, ios::in | ios::binary);
	try
	{

		if (!file) throw "Unable to open file for read";


		// 1) Read total number of questions
		file.read((char*)&totalNumberOfQuestions, sizeof(int));


		for (int i = 0; i < totalNumberOfQuestions; i++)
		{
			Question q;
			int q_id;  // id of question

			int size;
			char* q_s;  // question statement


			// 2) Read id of question
			file.read((char*)&q_id, sizeof(int));


			// 3) Read size of question statement
			file.read((char*)&size, sizeof(int));
			q_s = new char[size + 1];


			try
			{
				if (!q_s) throw "Memory allocation error";

				// 4) Read question statement
				file.read(q_s, size * sizeof(char));
				q_s[size] = '\0';
				q.SetQuestionStatement(q_s);
			}
			catch (const char* c)
			{
				cout << "Error: " << c << endl;
				return false;
			}
			
			int t_a;  // total number of answers
			
			// 5) Read total number of answers
			file.read((char*)&t_a, sizeof(int));
			q.SetTotalNumberOfAnswers(t_a);


			for (int j = 0; j < t_a; j++)
			{
				char* a;
				int a_id;
				
				// 6) Read Id of answer
				file.read((char*)&a_id, sizeof(int));


				// 7) Read size of answer
				file.read((char*)&size, sizeof(int));
				a = new char[size + 1];

				try
				{
					if (!a) throw "Memory allocation error";

					// 8) Read answer
					file.read(a, size * sizeof(char));
					a[size] = '\0';
					q.AddAnswer(a_id, a);
				}
				catch (const char* c)
				{
					cout << "Error: " << c << endl;
					return false;
				}

			}


			// 9) Read number of correct answer
			int c_a;  // number of correct answer
			file.read((char*)&c_a, sizeof(int));
			q.SetNumberOfCorrectAnswer(c_a);

			questions.insert(std::make_pair(q_id, q));
		}


		return true;

	}
	catch (const char* c)
	{
		cout << "Error: " << c << endl;
		return false;
	}

	return false;
}


#pragma endregion

