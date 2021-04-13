#include "Guest.h"

#pragma region Constructer


Guest::Guest()
{
	name = "";
	surname = "";
	patronymic = "";
	address = "";
	phoneNumber = "";
}


#pragma endregion


#pragma region Getters and Setters


void Guest::SetName(string _name)
{
	name = _name;
}

void Guest::SetSurname(string _surname)
{
	surname = _surname;
}

void Guest::SetPatronymic(string _patronymic)
{
	patronymic = _patronymic;
}

void Guest::SetAddress(string _address)
{
	address = _address;
}

void Guest::SetPhoneNumber(string _phoneNumber)
{
	phoneNumber = _phoneNumber;
}

void Guest::SetTestResults(map<string, int> _results)
{
	testResults = _results;
}


string Guest::GetName() const
{
	return name;
}

string Guest::GetSurname() const
{
	return surname;
}

string Guest::GetPatronymic() const
{
	return patronymic;
}

string Guest::GetAddress() const
{
	return address;
}

string Guest::GetPhoneNumber() const
{
	return phoneNumber;
}

map<string, int> Guest::GetTestTesults() const
{
	return testResults;
}


#pragma endregion



// Returns true if registration was successfull
// login and password is set before calling this method
// Adds name, surname, ...	
bool Guest::Register()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	system("cls");
	SetConsoleTextAttribute(hConsole, 12);
	cout << "\n\t\tRegister New guest\n\n";
	SetConsoleTextAttribute(hConsole, 15);

	
		/* Set name */
	cout << "Enter name: ";
	SetConsoleTextAttribute(hConsole, 14);
	getline(cin, name);
	SetConsoleTextAttribute(hConsole, 15);


		/* Set surname */
	cout << "Enter surname: ";
	SetConsoleTextAttribute(hConsole, 14);
	getline(cin, surname);
	SetConsoleTextAttribute(hConsole, 15);


		/* Set patronymic */
	cout << "Enter patronymic: ";
	SetConsoleTextAttribute(hConsole, 14);
	getline(cin, patronymic);
	SetConsoleTextAttribute(hConsole, 15);


		/* Set address */
	cout << "Enter address: ";
	SetConsoleTextAttribute(hConsole, 14);
	getline(cin, address);
	SetConsoleTextAttribute(hConsole, 15);



		/* Set phone number */
	cout << "Enter phone number: ";
	SetConsoleTextAttribute(hConsole, 14);
	getline(cin, phoneNumber);
	SetConsoleTextAttribute(hConsole, 10);

	cout << "\nGuest registration complete" << endl;
	SetConsoleTextAttribute(hConsole, 15);

	return true;
}



#pragma region Operator Overloading


// Used when sign up
Guest& Guest::operator= (const Guest& g)
{
	this->name = g.name;
	this->surname = g.surname;
	this->patronymic = g.patronymic;
	this->address = g.address;
	this->phoneNumber = g.phoneNumber;
	this->login = g.login;
	this->password = g.password;

	return *this;
}


#pragma endregion



#pragma region Working with Test Results


// Adds result to testResults
void Guest::AddResult(string _path_to_file, int _result)
{
	testResults.insert(std::make_pair(_path_to_file, _result));
}


// Shows all results by all guests in table format
void Guest::ShowAllResults() const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	
	
	if (testResults.size() == 0)
	{
		cout << "\n\n\t\t\t\t" << login << "\n\n";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\t\t\tNo tests done\n\n";
	}
	
	SetConsoleTextAttribute(hConsole, 15);

	cout << (char)201;
	for (int i = 0; i <= 114; i++)
	{
		if (i == 19 || i == 48 || i == 75 || i == 107 || i == 116)
			cout << (char)203;

		else
			cout << (char)205;
	}
	cout << (char)187;
	cout << "\n";


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j <= 116; j++)
		{

			if (i != 1)
			{
				if (j == 0 || j == 20 || j == 49 || j == 76 || j == 108 || j == 116)
				{
					cout << (char)186;
				}

				else
				{
					cout << " ";
				}
			}


			else
			{
				if (j == 7)
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "LOGIN";
					SetConsoleTextAttribute(hConsole, 15);
				}

				else if (j == 27)
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "CATEGORY";
					SetConsoleTextAttribute(hConsole, 15);
				}

				else if (j == 48)
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "SUBJECT";
					SetConsoleTextAttribute(hConsole, 15);
				}

				else if (j == 71)
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "TEST NAME";
					SetConsoleTextAttribute(hConsole, 15);
				}

				else if (j == 85)
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "GRADE";
					SetConsoleTextAttribute(hConsole, 15);
				}

				else if (j == 0 || j == 16 || j == 38 || j == 59 || j == 83 || j == 87)
				{
					cout << (char)186;
				}

				else if (j <= 87)
				{
					cout << " ";
				}
			}
		}

		//if (i != 1)
		cout << "\n";
	}



	for (auto t : testResults)
	{
	
		cout << (char)204;
		for (int j = 0; j <= 114; j++)
		{
			if (j == 19 || j == 48 || j == 75 || j == 107 || j == 116)
				cout << (char)206;

			else
				cout << (char)205;
		}
		cout << (char)185;
		cout << "\n";



		// Empty row
		for (int i = 0; i <= 116; i++)
		{
			if (i == 0 || i == 20 || i == 49 || i == 76 || i == 108 || i == 116)
			{
				cout << (char)186;
			}
			else
			{
				cout << " ";
			}
		}

		cout << "\n";




			//=============================================================================================

			// Show all info



		cout << (char)186 << " ";

		// login
		SetConsoleTextAttribute(hConsole, 14);
		cout << login;
		SetConsoleTextAttribute(hConsole, 15);
		for (int j = 0; j < 18 - login.length(); j++) cout << " ";
		cout << (char)186 << " ";



		int iii = 11;
		int c = 0;

		// category
		SetConsoleTextAttribute(hConsole, 14);
		
		for (iii; iii < t.first.length(); iii++)
		{
			if (t.first.at(iii) == '\\')
				break;

			else {
				cout << t.first.at(iii);
				c++;
			}
		}


		SetConsoleTextAttribute(hConsole, 15);
		for (int j = 0; j < 27 - c; j++) cout << " ";

		cout << (char)186 << " ";



		iii++;
		c = 0;

		// subject
		SetConsoleTextAttribute(hConsole, 14);

		for (iii; iii < t.first.length(); iii++)
		{
			if (t.first.at(iii) == '\\')
				break;

			else {
				cout << t.first.at(iii);
				c++;
			}
		}


		SetConsoleTextAttribute(hConsole, 15);
		for (int j = 0; j < 25 - c; j++) cout << " ";

		cout << (char)186 << " ";


		
		iii++;
		c = 0;

		// test
		SetConsoleTextAttribute(hConsole, 14);

		for (iii; iii < t.first.length(); iii++)
		{
			if (t.first.at(iii) == '\\')
				break;

			else {
				cout << t.first.at(iii);
				c++;
			}
		}


		SetConsoleTextAttribute(hConsole, 15);
		for (int j = 0; j < 30 - c; j++) cout << " ";

		cout << (char)186 << "  ";



		SetConsoleTextAttribute(hConsole, 11);
		cout << t.second;
		if (t.second < 10) cout << "    ";
		else if (t.second < 100) cout << "   ";
		SetConsoleTextAttribute(hConsole, 15);


		cout << (char)186;


		cout << "\n";

		


		// Empty row
		for (int i = 0; i <= 116; i++)
		{
			if (i == 0 || i == 20 || i == 49 || i == 76 || i == 108 || i == 116)
			{
				cout << (char)186;
			}
			else
			{
				cout << " ";
			}
		}

		cout << "\n";
	
	}


	SetConsoleTextAttribute(hConsole, 15);

	cout << (char)200;
	for (int i = 0; i <= 114; i++)
	{
		if (i == 19 || i == 48 || i == 75 || i == 107 || i == 116)
			cout << (char)202;

		else
			cout << (char)205;
	}
	cout << (char)188;
	cout << endl;
}



// Shows results of only chosen category in table format
void Guest::ShowCategoryReslts(string _path_to_category) const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);


	if (testResults.size() == 0)
	{
		cout << "\n\n\t\t\t\t" << login << "\n\n";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "\t\t\tNo tests done\n\n";
	}

	SetConsoleTextAttribute(hConsole, 15);

	cout << (char)201;
	for (int i = 0; i <= 114; i++)
	{
		if (i == 19 || i == 48 || i == 75 || i == 107 || i == 116)
			cout << (char)203;

		else
			cout << (char)205;
	}
	cout << (char)187;
	cout << "\n";


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j <= 116; j++)
		{

			if (i != 1)
			{
				if (j == 0 || j == 20 || j == 49 || j == 76 || j == 108 || j == 116)
				{
					cout << (char)186;
				}

				else
				{
					cout << " ";
				}
			}


			else
			{
				if (j == 7)
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "LOGIN";
					SetConsoleTextAttribute(hConsole, 15);
				}

				else if (j == 27)
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "CATEGORY";
					SetConsoleTextAttribute(hConsole, 15);
				}

				else if (j == 48)
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "SUBJECT";
					SetConsoleTextAttribute(hConsole, 15);
				}

				else if (j == 71)
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "TEST NAME";
					SetConsoleTextAttribute(hConsole, 15);
				}

				else if (j == 85)
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "GRADE";
					SetConsoleTextAttribute(hConsole, 15);
				}

				else if (j == 0 || j == 16 || j == 38 || j == 59 || j == 83 || j == 87)
				{
					cout << (char)186;
				}

				else if (j <= 87)
				{
					cout << " ";
				}
			}
		}

		//if (i != 1)
		cout << "\n";
	}



	for (auto t : testResults)
	{
		if (t.first.find(_path_to_category) != string::npos)
		{
			
			cout << (char)204;
			for (int j = 0; j <= 114; j++)
			{
				if (j == 19 || j == 48 || j == 75 || j == 107 || j == 116)
					cout << (char)206;

				else
					cout << (char)205;
			}
			cout << (char)185;
			cout << "\n";



			// Empty row
			for (int i = 0; i <= 116; i++)
			{
				if (i == 0 || i == 20 || i == 49 || i == 76 || i == 108 || i == 116)
				{
					cout << (char)186;
				}
				else
				{
					cout << " ";
				}
			}

			cout << "\n";




			//=============================================================================================

			// Show all info



			cout << (char)186 << " ";

			// login
			SetConsoleTextAttribute(hConsole, 14);
			cout << login;
			SetConsoleTextAttribute(hConsole, 15);
			for (int j = 0; j < 18 - login.length(); j++) cout << " ";
			cout << (char)186 << " ";



			int iii = 11;
			int c = 0;

			// category
			SetConsoleTextAttribute(hConsole, 14);

			for (iii; iii < t.first.length(); iii++)
			{
				if (t.first.at(iii) == '\\')
					break;

				else {
					cout << t.first.at(iii);
					c++;
				}
			}


			SetConsoleTextAttribute(hConsole, 15);
			for (int j = 0; j < 27 - c; j++) cout << " ";

			cout << (char)186 << " ";



			iii++;
			c = 0;

			// subject
			SetConsoleTextAttribute(hConsole, 14);

			for (iii; iii < t.first.length(); iii++)
			{
				if (t.first.at(iii) == '\\')
					break;

				else {
					cout << t.first.at(iii);
					c++;
				}
			}


			SetConsoleTextAttribute(hConsole, 15);
			for (int j = 0; j < 25 - c; j++) cout << " ";

			cout << (char)186 << " ";



			iii++;
			c = 0;

			// test
			SetConsoleTextAttribute(hConsole, 14);

			for (iii; iii < t.first.length(); iii++)
			{
				if (t.first.at(iii) == '\\')
					break;

				else {
					cout << t.first.at(iii);
					c++;
				}
			}


			SetConsoleTextAttribute(hConsole, 15);
			for (int j = 0; j < 30 - c; j++) cout << " ";

			cout << (char)186 << "  ";



			SetConsoleTextAttribute(hConsole, 11);
			cout << t.second;
			if (t.second < 10) cout << "    ";
			else if (t.second < 100) cout << "   ";
			SetConsoleTextAttribute(hConsole, 15);


			cout << (char)186;


			cout << "\n";




			// Empty row
			for (int i = 0; i <= 116; i++)
			{
				if (i == 0 || i == 20 || i == 49 || i == 76 || i == 108 || i == 116)
				{
					cout << (char)186;
				}
				else
				{
					cout << " ";
				}
			}

			cout << "\n";



		}
	}

	SetConsoleTextAttribute(hConsole, 15);

	cout << (char)200;
	for (int i = 0; i <= 114; i++)
	{
		if (i == 19 || i == 48 || i == 75 || i == 107 || i == 116)
			cout << (char)202;

		else
			cout << (char)205;
	}
	cout << (char)188;
	cout << endl;

}



#pragma endregion

