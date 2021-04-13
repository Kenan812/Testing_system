#include "TestSystem.h"


#pragma region Constructer


// Checks if there was an admin
// If there was no admin Register a new one
// If admin exists automatically loads login and password from "admin.txt" file
TestSystem::TestSystem()
{
		/* To check if Admin exits */
		/* If doesn't register new admin */
	fstream file("admin.txt", ios::in | ios::binary);

	try
	{
		if (!file) throw "No admin exists";
		file.close();

			/* If admin exists */
			/* Get admin Login and Password */

		systemAdmin.GetAdminInfo();

			/* Load guests */
		LoadGuestsInfo();
	}
	catch (const char* c)
	{
		cout << c << "\n\n";
		system("pause");
		systemAdmin.Register();
		systemAdmin.SaveAdminInfo();
		totalNumberOfGuests = 0;

		string name = "Categories";
		_mkdir(name.c_str());
	}

	is_admin = false;
	is_guest = false;

	mainPath = "Categories\\";
}


#pragma endregion



#pragma region Using Test System


// Lets Use TestSystem
// Contains all possible admin and guest actions
void TestSystem::Use()
{
	if (is_admin)
		UseAdmin();
	else if (is_guest)
		UseGuest();
	else
		cout << "\nOOPS! Something went wrong\n";
}



// Lets use TestSystem as Admin
// Comtains all possible admin actions
void TestSystem::UseAdmin()
{
	while (true)
	{

		system("cls");
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 15);

		int num;  // user choice

		num = DoChoice("Admin", "(1) Manage categories", "(2) Manage guests", "(3) Show statistics", "(4) Change login and password", "(5) Exit");

		switch (num)
		{
		case 1:
			ManageCategories();
			system("pause");
			break;

		case 2:
			ManageGuests();
			system("pause");
			break;

		case 3:
			ManageStatistics();
			system("pause");
			break;


		case 4:
			cin.ignore();
			systemAdmin.ChangeLoginAndPassword();
			break;


		case 5:
			exit(0);
			break;

		default:
			break;
		}
	}
}



// Lets use TestSystem as Guest
// Contains all possible guest actions
void TestSystem::UseGuest()
{
	while (true)
	{
		system("cls");
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 15);

		int num;  // user choice

		num = DoChoice("Guest", "(1) Take a new test", "(2) Show tests results", "(3) Exit(To save progress)");


		bool is_found;  // Used to find path to desirable test

		switch (num)
		{
		case 1:
			
			is_found = FindTest();

			// if test was found
			if (is_found)
			{
				TakeNewTest(mainPath);
			}

			// test not found
			else  // return to the wery beginning
			{
				mainPath = "Categories\\";
			}
			
			break;

		case 2:
			system("cls");
			currentGuest.ShowAllResults();
			system("pause");
			break;


		case 3:
			// in case if new guest was added
			OverrideGuests();

			exit(0);

		default:
			break;
		}

	}


}



#pragma endregion



#pragma region Admin Options


// Allows to add, see categories, add subjects, add tests
void TestSystem::ManageCategories()
{
	while (true)
	{
		system("cls");
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 12);


		int num = 0;  // user choice
		int num_of_slash = CountChar(mainPath, '\\');  // To define where user is




		//===================================================================
	
				/*  User is in Categories directory   */


		if (num_of_slash == 1)
		{

			while (num != 3 && num != 2)
			{
				/*
					(1) Add new Category
					(2) Go to Category
					(3) Exit
				*/


				system("cls");	
				SetConsoleTextAttribute(hConsole, 15);

				num = DoChoice("You are in Categories", "(1) Add new category", "(2) Go to category", "(3) Exit");


				switch (num)
				{
				case 1:
					Add();
					break;

				case 2:
					int n;
					Show();
					cout << "Enter number of category: ";
					cin >> n;
					{
						bool is_goto = GoTo(n);
						if (!is_goto)
						{
							SetConsoleTextAttribute(hConsole, 12);
							cout << "Unable to perform operation\n";
							SetConsoleTextAttribute(hConsole, 15);
							GoBack();
						}
					}
					system("pause");
					break;

				case 3:
					return;

				default:
					break;
				}
			}
		}



		//===================================================================




		//===================================================================

				/*  User is in particular categorie   */


		else if (num_of_slash == 2)
		{
			/*
					(1) Add new subject
					(2) Go to subject
					(3) Go back - returns back to categories directory
			*/

			while (num != 3 && num!= 2)
			{
				system("cls");
				SetConsoleTextAttribute(hConsole, 15);

				num = DoChoice(1, "You are in categorie: ", GetLastDir(mainPath), "(1) Add new subject", "(2) Go to subject", "(3) Exit");

				switch (num)
				{
				case 1:
					Add();
					break;

				case 2:
					int n;
					Show();
					cout << "Enter number of subject: ";
					cin >> n;
					{
						bool is_goto = GoTo(n);
						if (!is_goto) 
						{
							SetConsoleTextAttribute(hConsole, 12);
							cout << "Unable to perform operation\n";
							SetConsoleTextAttribute(hConsole, 15);
							GoBack();
						}
					}
					system("pause");
					break;

				case 3:
					GoBack();
					break;

				default:
					break;
				}
			}
		}



		//===================================================================




		//===================================================================

				/*  User is in particular subject   */


		else if (num_of_slash == 3)
		{
			while (num != 4 && num != 3)
			{
				system("cls");
				SetConsoleTextAttribute(hConsole, 15);

				num = DoChoice(1, "You are in subject: ", GetLastDir(mainPath), "(1) Add new test", "(2) Show All tests", "(3) Show test content", "(4) Go back");

				Subject* s;
				Test* t;

				switch (num)
				{
				case 1:
					s = new Subject;
					s->AddTest(mainPath);
					if (s) delete s;
					break;

				case 2:
					Show();
					cout << "\n";
					system("pause");
					break;

				case 3:
					t = new Test;

					Show();



					/* Go to file */

					//=======================================================
					
					{
						int n;
						cout << "\nChoose test number: ";
						cin >> n;

						bool to_show = ChooseTest(n);


						if (!to_show) 
						{
							system("cls");
							SetConsoleTextAttribute(hConsole, 12);
							cout << "No such test\n";
							SetConsoleTextAttribute(hConsole, 15);
							system("pause");
						}
						else 
						{
							t->LoadTestFromFile(mainPath);
							t->ShowTest();
							system("pause");
						}
						
						if (t) delete t;

					}
					
					//=======================================================
					

					GoBack();
					break;

				case 4:
					GoBack();
					system("pause");
					break;

				default:
					break;
				}
			}
		}



		//===================================================================
	}
}



// To add delete modify guests
void TestSystem::ManageGuests()
{
	while (true)
	{
		system("cls");
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hConsole, 15);

		int num;  // user choice

		num = DoChoice("Managing guests", "(1) Add new guest", "(2) Modify guest info", "(3) Delete guest", "(4) Show all guests", "(5) Exit(To save all changes)");

		switch (num)
		{
		case 1:
			cin.ignore();
			RegisterNewGuest();
			system("pause");
			break;


		case 2:

			system("cls");
			SetConsoleTextAttribute(hConsole, 12);

			cout << "\n\tModify guest info\n\n";

			cout << "Warning! ";
			SetConsoleTextAttribute(hConsole, 15);
			cout << "You can not modify guest login or password\n\n";
			
			ShowAllGuests();
			ModifyGuestInfo();
			system("pause");

			break;

		case 3:

			system("cls");
			SetConsoleTextAttribute(hConsole, 12);

			cout << "\n\tDeleting guest\n\n";

			ShowAllGuests();
			DeleteGuest();
			system("pause");

			break;


		case 4:
			system("cls");
			ShowAllGuests();
			system("pause");
			break;

		case 5:

			// to save all changes
			OverrideGuests();

			return;

		
		default:
			break;
		}


	}

}



// To show statistics
void TestSystem::ManageStatistics()
{
	while (true)
	{
		system("cls");
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hConsole, 15);

		int num;  // user choice


		num = DoChoice("Statistics", "(1) Show stats by category", "(2) Show stats by subject", "(3) Show stats by guests", "(4) Exit");

		switch (num)
		{

		case 1:

			Show();

			int n;
			cout << "Enter number of category: ";
			cin >> n;
			{
				bool is_goto = GoTo(n);
				if (!is_goto)
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "Unable to perform operation\n";
					SetConsoleTextAttribute(hConsole, 15);
				}
				else
				{
					system("cls");
					for (auto g : allGuests)
					{		
						g.second.ShowCategoryReslts(mainPath);
						cout << "\n\n";
					}
				}
			}

			GoBack();

			system("pause");
			break;
		

		case 2:

			Show();

			int i;
			cout << "Enter number of category: ";
			cin >> i;
			{
				bool is_goto = GoTo(i);
				if (!is_goto)
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "Unable to perform operation\n";
					SetConsoleTextAttribute(hConsole, 15);
				}
				else
				{
					Show();

					cout << "Enter number of subject: ";
					cin >> i;
					{
						bool is_goto = GoTo(i);
						if (!is_goto)
						{
							SetConsoleTextAttribute(hConsole, 12);
							cout << "Unable to perform operation\n";
							SetConsoleTextAttribute(hConsole, 15);
						}
						else
						{
							system("cls");
							for (auto g : allGuests)
							{
								g.second.ShowCategoryReslts(mainPath);
								cout << "\n\n";
							}
						}
					}

					GoBack();
				}
			}

			GoBack();

			system("pause");
			break;


		case 3:
			system("cls");

			for (auto g : allGuests)
			{
				SetConsoleTextAttribute(hConsole, 12);
				cout << "\n\n\t\t\t\t\tTest results\n\n\n"; 
				g.second.ShowAllResults();
				SetConsoleTextAttribute(hConsole, 15);
				cout << "\n\n";
			}
			
			system("pause");
			break;

		case 4:
			return;
		
		default:
			break;

		}


	}
}




#pragma endregion



#pragma region Guest Options


// _path is path to test file
// For guest to take a new test
void TestSystem::TakeNewTest(string _path_to_file)
{
	Test t;

		/* Load test */
	t.LoadTestFromFile(_path_to_file);


		/* Get test name */
	string test_name = "";
	for (int i = _path_to_file.length() - 1; i >= 0; i--)
	{
		if (_path_to_file.at(i) == '\\') break;
		test_name += _path_to_file.at(i);
	}

	for (int i = 0; i < test_name.length() / 2; i++)
	{
		char tmp = test_name.at(i);
		test_name.at(i) = test_name.at(test_name.length() - i - 1);
		test_name.at(test_name.length() - i - 1) = tmp;
	}



		/* Take test */
	// resuls shown;
	int test_result = t.GuestTakeTest(test_name);
	

		/* Add guest result */
	for (auto g : allGuests)
	{
		if (g.first == currentGuest.GetLogin())
		{
			map<string, Guest>::iterator find_guest = allGuests.find(g.first);
			find_guest->second.AddResult(_path_to_file, test_result);

			currentGuest.AddResult(_path_to_file, test_result);
		}
	}

}



// Used by guest to find test in categories
// modifies mainPath to lead to test
bool TestSystem::FindTest()
{
	while (true)
	{
		system("cls");
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 12);


		int num = 0;  // user choice
		int num_of_slash = CountChar(mainPath, '\\');  // To define where user is


		//===================================================================

				/*  User is in Categories directory   */


		if (num_of_slash == 1)
		{

			while (num != 2 && num != 1)
			{
				/*
					(1) Go to Category
					(2) Go back
				*/
				system("cls");
				SetConsoleTextAttribute(hConsole, 12);
				cout << "\n\t\t\tChoosing test\n\n";
				cout << "\n\t\tYou are in Categories\n\n";
				cout << "\tAll categories:\n";
				SetConsoleTextAttribute(hConsole, 15);

				Show();

				SetConsoleTextAttribute(hConsole, 12);
				cout << "\n\tChoose an option\n";
				SetConsoleTextAttribute(hConsole, 15);


				cout << "(1) Go to category\n"
					<< "(2) Go back\n\n";


				cout << "Enter choice: ";
				SetConsoleTextAttribute(hConsole, 14);
				cin >> num;
				SetConsoleTextAttribute(hConsole, 15);


				switch (num)
				{

				case 1:
					int n;
					cout << "Enter number of category: ";
					cin >> n;
					{
						bool is_goto = GoTo(n);
						if (!is_goto)
						{
							SetConsoleTextAttribute(hConsole, 12);
							cout << "Unable to perform operation\n";
							SetConsoleTextAttribute(hConsole, 15);
							GoBack();
						}
					}
				

					system("pause");
					break;

				case 2:
					return false;

				default:
					break;
				}
			}
		}



		//===================================================================



		//===================================================================

				/*  User is in particular categorie   */


		else if (num_of_slash == 2)
		{
			/*
					(1) Go to subject
					(2) Go back - returns back to categories directory
			*/

			while (num != 1 && num != 2)
			{
				system("cls");
				SetConsoleTextAttribute(hConsole, 12);
				cout << "\n\t\t\tChoosing test\n\n";
				SetConsoleTextAttribute(hConsole, 15);
				cout << "\n\t\tYou are in categorie: ";
				SetConsoleTextAttribute(hConsole, 12);
				cout << GetLastDir(mainPath) << "\n\n";
				SetConsoleTextAttribute(hConsole, 15);

				Show();

				SetConsoleTextAttribute(hConsole, 12);
				cout << "\n\tChoose an option\n";
				SetConsoleTextAttribute(hConsole, 15);


				cout << "(1) Go to subject\n"
					<< "(2) Go back\n\n";


				cout << "Enter choice: ";
				SetConsoleTextAttribute(hConsole, 14);
				cin >> num;
				SetConsoleTextAttribute(hConsole, 15);

				switch (num)
				{
				case 1:
					int n;
					cout << "Enter number of subject: ";
					cin >> n;
					{
						bool is_goto = GoTo(n);
						if (!is_goto)
						{
							SetConsoleTextAttribute(hConsole, 12);
							cout << "Unable to perform operation\n";
							SetConsoleTextAttribute(hConsole, 15);
							GoBack();
						}
					}
					system("pause");
					break;

				case 2:
					GoBack();
					system("pause");
					break;

				default:
					break;
				}
			}
		}



		//===================================================================





		//===================================================================

				/*  User is in particular subject   */


		else if (num_of_slash == 3)
		{
			while (num != 1 && num != 2)
			{
				system("cls");
				SetConsoleTextAttribute(hConsole, 12);
				cout << "\n\t\t\tChoosing test\n\n";
				SetConsoleTextAttribute(hConsole, 15);
				cout << "\n\t\tYou are in subject: ";

				SetConsoleTextAttribute(hConsole, 12);
				cout << GetLastDir(mainPath) << "\n\n";
				SetConsoleTextAttribute(hConsole, 15);

				cout << "(1) Choose test\n"
					<< "(2) Go back\n\n";


				cout << "Enter choice: ";
				SetConsoleTextAttribute(hConsole, 14);
				cin >> num;
				SetConsoleTextAttribute(hConsole, 15);

				switch (num)
				{

				case 2:
					GoBack();
					system("pause");
					break;

				case 1:


					Show();


					/* Go to file */

					{
						int n;
						cout << "\nChoose test number: ";
						cin >> n;

						bool to_show = ChooseTest(n);
												




						if (!to_show) 
						{
							system("cls");
							SetConsoleTextAttribute(hConsole, 12);
							cout << "No such test\n";
							SetConsoleTextAttribute(hConsole, 15);
							system("pause");
						}
						else 
						{
							system("pause");
							return true;
						}

					}

					GoBack();
					return false;


				default:
					break;
				}
			}
		}



	}
	



	return false;
}



#pragma endregion



#pragma region Sign In(Guest and Admin) and Register Guest


// Must be done before using TestSystem
bool TestSystem::SignInSystem()
{
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	int key;

	// Possible user choice 
	bool admin = true;
	bool guest = false;

	bool is_sign_in_successful = false;



	// Choose between admin and guest
	while (true)
	{
		SetConsoleTextAttribute(hConsole, 12);
		printf("\n\t\tSign In\n\n");
		SetConsoleTextAttribute(hConsole, 15);

		printf("\tUse\n'%c' to move up\n'%c' to move down\n", ARROW_UP, ARROW_DOWN);
		printf("Press 'ENTER' to chose an option\n\n");

		if (admin)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("%c Admin\n", ARROW_LEFT);
		}
		else if (!admin)
		{
			SetConsoleTextAttribute(hConsole, 15);
			printf("  Admin\n", ARROW_LEFT);
		}

		if (guest)
		{
			SetConsoleTextAttribute(hConsole, 14);
			printf("%c Guest\n", ARROW_LEFT);
		}
		else if (!guest)
		{
			SetConsoleTextAttribute(hConsole, 15);
			printf("  Guest\n", ARROW_LEFT);
		}

		SetConsoleTextAttribute(hConsole, 15);

		key = _getch();

		if (key == KEY_DOWN && admin)
		{
			admin = false;
			guest = true;
		}
		else if (key == KEY_UP && guest)
		{
			admin = true;
			guest = false;
		}
		else if (key == ENTER && admin)
		{
			system("cls");
			is_sign_in_successful = systemAdmin.SignInAdmin();
			break;
		}
		else if (key == ENTER && guest)
		{
			break;
		}
		system("cls");
	}





	// The program is used by admin 
	if (is_sign_in_successful && admin)
	{
		is_admin = true;
		return true;
	}

	// The program is used by guest
	else if (guest)
	{
		system("cls");
		bool si = true;  // Sign in
		bool su = false;  // Sign up

		//==================================================
		// Choose to sign in or sign up
		while (true)
		{
			SetConsoleTextAttribute(hConsole, 12);
			printf("\n\t\tSign In\n\n");
			SetConsoleTextAttribute(hConsole, 15);

			printf("\tUse\n'%c' to move up\n'%c' to move down\n", ARROW_UP, ARROW_DOWN);
			printf("Press 'ENTER' to chose an option\n\n");

			if (si)
			{
				SetConsoleTextAttribute(hConsole, 14);
				printf("%c Sign In\n", ARROW_LEFT);
			}
			else if (!si)
			{
				SetConsoleTextAttribute(hConsole, 15);
				printf("  Sign In\n", ARROW_LEFT);
			}

			if (su)
			{
				SetConsoleTextAttribute(hConsole, 14);
				printf("%c Sign Up\n", ARROW_LEFT);
			}
			else if (!su)
			{
				SetConsoleTextAttribute(hConsole, 15);
				printf("  Sign Up\n", ARROW_LEFT);
			}

			SetConsoleTextAttribute(hConsole, 15);

			key = _getch();

			if (key == KEY_DOWN && si)
			{
				si = false;
				su = true;
			}
			else if (key == KEY_UP && su)
			{
				si = true;
				su = false;
			}
			else if (key == ENTER && si)
			{
				system("cls");
				is_sign_in_successful = SignInGuest();
				break;
			}
			else if (key == ENTER && su)
			{
				system("cls");
				RegisterNewGuest();
				is_sign_in_successful = true;
				break;
			}
			system("cls");
		}




		//=======================================================





		if (is_sign_in_successful)
		{
			is_guest = true;
			return true;
		}
	}



	return false;
}



// Automatically adds guest to guests map and saves in file
void TestSystem::RegisterNewGuest()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	Guest new_guest;

	string login_tmp;
	string password_tmp;

	bool flag = true;

	// Set Guest login
	while (flag)
	{
		system("cls");
		SetConsoleTextAttribute(hConsole, 12);
		cout << "\n\t\tRegister New Guest\n\n";
		SetConsoleTextAttribute(hConsole, 15);

		try
		{

			cout << "Create login: ";

			SetConsoleTextAttribute(hConsole, 14);
			getline(cin, login_tmp);

			SetConsoleTextAttribute(hConsole, 15);

			for (auto g : allGuests)
			{
				if (login_tmp == g.first)
					throw "This login exists";

			}

			new_guest.SetLogin(login_tmp);
			flag = false;
		}
		catch (const char* c)
		{
			SetConsoleTextAttribute(hConsole, 12);
			cout << "Error: " << c << "\n";
			SetConsoleTextAttribute(hConsole, 15);
			system("pause");
		}
	}

	system("cls");
	SetConsoleTextAttribute(hConsole, 12);
	cout << "\n\t\tRegister New Guest\n\n";
	SetConsoleTextAttribute(hConsole, 15);

	cout << "Create pasword: ";
	SetConsoleTextAttribute(hConsole, 14);
	getline(cin, password_tmp);
	SetConsoleTextAttribute(hConsole, 15);
	
	new_guest.SetPassword(password_tmp);

	new_guest.Register();

	totalNumberOfGuests++;

	allGuests.insert(make_pair(new_guest.GetLogin(), new_guest));


	// If guest signed up set guest info to current guest
	if (!is_admin)
	{
		currentGuest = new_guest;
	}

	SetConsoleTextAttribute(hConsole, 12);
	cout << "Exit to save\n";
	SetConsoleTextAttribute(hConsole, 15);
	system("pause");
}


// Sings in guest and sets him to currentGuest
bool TestSystem::SignInGuest()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	string login_input;
	string password_input;

	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(hConsole, 12);
		printf("\n\t\tSign In Guest\n\n");
		SetConsoleTextAttribute(hConsole, 15);

		cout << "Enter login: ";
		SetConsoleTextAttribute(hConsole, 14);
		getline(cin, login_input);
		SetConsoleTextAttribute(hConsole, 15);

		cout << "Enter password: ";
		SetConsoleTextAttribute(hConsole, 14);
		getline(cin, password_input);


		// to check password
		for (auto g : allGuests)
		{

			if (login_input == g.first)
			{
				if (password_input == g.second.GetPassword())
				{
					SetConsoleTextAttribute(hConsole, 10);
					cout << "\nSign in successful" << endl;
					SetConsoleTextAttribute(hConsole, 15);
					
					// to load current guest
					currentGuest.SetLogin(g.first);
					currentGuest.SetPassword(g.second.GetPassword());
					currentGuest.SetName(g.second.GetName());
					currentGuest.SetSurname(g.second.GetSurname());
					currentGuest.SetPatronymic(g.second.GetPatronymic());
					currentGuest.SetAddress(g.second.GetAddress());
					currentGuest.SetPhoneNumber(g.second.GetPhoneNumber());
					currentGuest.SetTestResults(g.second.GetTestTesults());

					return true;
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "\nIncorrect login or password" << endl;
					SetConsoleTextAttribute(hConsole, 15);
					system("pause");
					break;
				}
			}
		}

		SetConsoleTextAttribute(hConsole, 12);
		cout << "\nIncorrect login or password" << endl;
		SetConsoleTextAttribute(hConsole, 15);
		system("pause");
	}

	return false;

}



#pragma endregion



#pragma region Move Chrough Categories, Subjects 



// Show all categories, all subjects, tests by using mainPath  
void TestSystem::Show()
{
	mainPath += "*";

	_finddata_t* fileinfo = new _finddata_t;
	long done = _findfirst(mainPath.c_str(), fileinfo);
	int isReadable = done;
	int count = 0;

	cout << "\n";
	while (isReadable != -1)
	{
		if (fileinfo->name[0] != '.')
		{
			count++;
			cout << "(" << count << ") " << fileinfo->name << "  " << endl;

		}
		isReadable = _findnext(done, fileinfo);
	}

	_findclose(done);
	delete fileinfo;

	if (count == 0)
	{
		cout << "Nothing to Show\n";
	}

	mainPath.pop_back();
}


// Modifies main path
// Goes to categories, subjects by mainPath  
bool TestSystem::GoTo(int num)
{
	bool is_goto = false;
	
	mainPath += "*";


	_finddata_t* fileinfo = new _finddata_t;
	long done = _findfirst(mainPath.c_str(), fileinfo);
	int isReadable = done;
	int count = 0;

	cout << "\n";
	while (isReadable != -1)
	{
		if (fileinfo->name[0] != '.')
		{
			count++;

			if (count == num)
			{
				mainPath.pop_back();
				mainPath += fileinfo->name;
				mainPath += "\\";
				is_goto = true;
			}
		}
		isReadable = _findnext(done, fileinfo);
	}

	_findclose(done);
	delete fileinfo;

	if (is_goto) return true;
	return false;
}


// Modifies mainPath by deleting last directory
void TestSystem::GoBack()
{

	mainPath.pop_back();
	
	for (int i = mainPath.length() - 1; i >= 0; i--)
	{
		if (mainPath.at(i) == '\\')
		{
			break;
		}

		mainPath.pop_back();
	}

}



#pragma endregion



#pragma region Save and Load Guests


// Saves 1 Guest info
// Used after registration
void TestSystem::SaveGuestInfo(string login, Guest g)
{
	string encrypted_login = User::Encrypt(login);
	string encrypted_password = User::Encrypt(g.GetPassword());

	int size;

	fstream file("guests.txt", ios::out | ios::binary | ios::app);

	try
	{
		if (!file) throw "Unable to open the file for write";

		size = encrypted_login.length();
		file.write((char*)&size, sizeof(size));
		file.write(encrypted_login.c_str(), size * sizeof(char));

		size = encrypted_password.length();
		file.write((char*)&size, sizeof(size));
		file.write(encrypted_password.c_str(), size * sizeof(char));

		size = g.GetName().length();
		file.write((char*)&size, sizeof(size));
		file.write(g.GetName().c_str(), size * sizeof(char));

		size = g.GetSurname().length();
		file.write((char*)&size, sizeof(size));
		file.write(g.GetSurname().c_str(), size * sizeof(char));

		size = g.GetPatronymic().length();
		file.write((char*)&size, sizeof(size));
		file.write(g.GetPatronymic().c_str(), size * sizeof(char));

		size = g.GetAddress().length();
		file.write((char*)&size, sizeof(size));
		file.write(g.GetAddress().c_str(), size * sizeof(char));

		size = g.GetPhoneNumber().length();
		file.write((char*)&size, sizeof(size));
		file.write(g.GetPhoneNumber().c_str(), size * sizeof(char));

		// saving test results

		// writing number of solved tests
		size = g.GetTestTesults().size();
		file.write((char*)&size, sizeof(size));

		for (auto elem : g.GetTestTesults())
		{
			// writing path to file
			size = elem.first.length();
			file.write((char*)&size, sizeof(size));
			file.write(elem.first.c_str(), size * sizeof(char));

			// writing result
			file.write((char*)&elem.second, sizeof(elem.second));
		}

		cout << "Save successful\n";

		file.close();
	}
	catch (const char* c)
	{
		cout << "Error: " << c << endl;
	}
}



// Sets all guests to allGuests
void TestSystem::LoadGuestsInfo()
{
	fstream file("guests.txt", ios::in | ios::binary);

	string encrypted_login;
	string encrypted_password;

	char* enc_login, * enc_password;
	char* n, * s, * p, * a, * p_n;
	int size;



	try
	{

		if (!file) throw "No guests available";




		//==========================================================

		while (file.read((char*)&size, sizeof(int)))
		{

			totalNumberOfGuests++;
			Guest new_guest;

			// Read login
			enc_login = new char[size + 1];

			try
			{
				if (!enc_login) throw "Memory allocation error";

				file.read(enc_login, size * sizeof(char));
				enc_login[size] = '\0';

				encrypted_login = enc_login;

			}
			catch (const char* c)
			{
				cout << c << "\n";
			}


			// Read password
			file.read((char*)&size, sizeof(int));
			enc_password = new char[size + 1];

			try
			{
				if (!enc_password) throw "Memory allocation error";

				file.read(enc_password, size * sizeof(char));
				enc_password[size] = '\0';
				encrypted_password = enc_password;
			}
			catch (const char* c)
			{
				cout << c << "\n";
			}
			

			// Read name
			file.read((char*)&size, sizeof(int));
			n = new char[size + 1];

			try
			{
				if (!n) throw "Memory allocation error";

				file.read(n, size * sizeof(char));
				n[size] = '\0';
				new_guest.SetName(n);
			}
			catch (const char* c)
			{
				cout << c << "\n";
			}


			// Read surname
			file.read((char*)&size, sizeof(int));
			s = new char[size + 1];

			try
			{
				if (!s) throw "Memory allocation error";

				file.read(s, size * sizeof(char));
				s[size] = '\0';
				new_guest.SetSurname(s);
			}
			catch (const char* c)
			{
				cout << c << "\n";
			}


			// Read patronymic
			file.read((char*)&size, sizeof(int));
			p = new char[size + 1];

			try
			{
				if (!p) throw "Memory allocation error";

				file.read(p, size * sizeof(char));
				p[size] = '\0';
				new_guest.SetPatronymic(p);
			}
			catch (const char* c)
			{
				cout << c << "\n";
			}



			// Read address
			file.read((char*)&size, sizeof(int));
			a = new char[size + 1];

			try
			{
				if (!a) throw "Memory allocation error";

				file.read(a, size * sizeof(char));
				a[size] = '\0';
				new_guest.SetAddress(a);
			}
			catch (const char* c)
			{
				cout << c << "\n";
			}



			// Read phoneNumber
			file.read((char*)&size, sizeof(int));
			p_n = new char[size + 1];

			try
			{
				if (!p_n) throw "Memory allocation error";

				file.read(p_n, size * sizeof(char));
				p_n[size] = '\0';
				new_guest.SetPhoneNumber(p_n);
			}
			catch (const char* c)
			{
				cout << c << "\n";
			}



			// Reading test result
			int n_of_solved_tests, r;
			char* path_to_file;

			file.read((char*)&n_of_solved_tests, sizeof(int));

			for (int ii = 0; ii < n_of_solved_tests; ii++)
			{
				file.read((char*)&size, sizeof(int));

				path_to_file = new char[size + 1];

				file.read(path_to_file, size * sizeof(char));
				path_to_file[size] = '\0';

				// result
				file.read((char*)&r, sizeof(int));

				new_guest.AddResult(path_to_file, r);

				if (path_to_file) delete[] path_to_file;
			}



			if (enc_login) delete[] enc_login;
			if (enc_password) delete[] enc_password;
			if (n) delete[] n;
			if (s) delete[] s;
			if (p) delete[] p;
			if (a) delete[] a;
			if (p_n) delete[] p_n;


			string decrypted_login = User::Decrypt(encrypted_login);
			string decrypted_password = User::Decrypt(encrypted_password);

			new_guest.SetLogin(decrypted_login);
			new_guest.SetPassword(decrypted_password);


			allGuests.insert(std::make_pair(new_guest.GetLogin(), new_guest));

			cout << "Guest " << totalNumberOfGuests << " loaded\n";
		}



		


		//==========================================================


	}
	catch (const char* c)
	{
		cout << "Error: " << c << endl;
	}

	system("pause");

}                                           




// Overrides guests.txt
void TestSystem::OverrideGuests()
{
	string path = "guests.txt";

	if (remove(path.c_str()) != 0)
	{
		cout << "Error..." << endl;
	}
	else
	{
		cout << "Complete..." << endl;
	}

	for (auto g2 : allGuests)
	{
		SaveGuestInfo(g2.first, g2.second);
	}



}



#pragma endregion



#pragma region Auxiliary admin options




// Adds category to Categories directory
void TestSystem::Add()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);

	cin.ignore();

	system("cls");

	if (CountChar(mainPath, '\\') == 1)
		cout << "\n\t\tAdding category\n\n";
	else
		cout << "\n\t\tAdding subject\n\n";
	SetConsoleTextAttribute(hConsole, 15);

	string name = mainPath;
	string name_tmp;

	cout << "Enter name: ";
	SetConsoleTextAttribute(hConsole, 14);
	getline(cin, name_tmp);
	SetConsoleTextAttribute(hConsole, 15);

	name += name_tmp;

	if (_mkdir(name.c_str()) == -1)
		cout << "Error...\n";
	else
		cout << "Completed...\n";

	system("pause");
}



void TestSystem::ShowAllGuests() const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	
	cout << "\n\t\t\t\t\t\tAll Guests\n\n\n";
	SetConsoleTextAttribute(hConsole, 15);

	int id = 1;



	
	cout << (char)201;
	for (int i = 0; i <= 114; i++)
	{
		if (i == 5 || i == 23 || i == 39 || i == 55 || i == 71 || i == 99 || i == 116)
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
				if (j == 0 || j == 6 || j == 24 || j == 40 || j == 56 || j == 72 || j == 100 || j == 116)
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
				if (j == 2)
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "ID";
					SetConsoleTextAttribute(hConsole, 15);
				}

				else if (j == 12)
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "LOGIN";
					SetConsoleTextAttribute(hConsole, 15);
				}

				else if (j == 25)
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "Name";
					SetConsoleTextAttribute(hConsole, 15);
				}

				else if (j == 37)
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "Surname";
					SetConsoleTextAttribute(hConsole, 15);
				}

				else if (j == 45)
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "Patronymic";
					SetConsoleTextAttribute(hConsole, 15);
				}

				else if (j == 59)
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "Address";
					SetConsoleTextAttribute(hConsole, 15);
				}

				else if (j == 73)
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "Phone Number";
					SetConsoleTextAttribute(hConsole, 15);
				}

				else if (j == 0 || j == 5 || j == 19 || j == 32 || j == 42 || j == 49 || j == 71 || j == 76)
				{
					cout << (char)186;
				}

				else if (j <= 77)
				{
					cout << " ";
				}
			}
		}

		//if (i != 1)
		cout << "\n";
	}



	

	for (auto g : allGuests)
	{

		cout << (char)204;
		for (int j = 0; j <= 114; j++)
		{
			if (j == 5 || j == 23 || j == 39 || j == 55 || j == 71 || j == 99 || j == 116)
				cout << (char)206;

			else
				cout << (char)205;
		}
		cout << (char)185;
		cout << "\n";


		// Empty row
		for (int i = 0; i <= 116; i++)
		{
			if (i == 0 || i == 6 || i == 24 || i == 40 || i == 56 || i == 72 || i == 100 || i == 116)
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

		// Id
		SetConsoleTextAttribute(hConsole, 14);
		cout << id;
		SetConsoleTextAttribute(hConsole, 15);
		if (id < 10) cout << "   ";
		else if (id < 100) cout << "  ";
		else cout << " ";

		cout << (char)186 << " ";


		// login
		SetConsoleTextAttribute(hConsole, 14);
		cout << g.first;
		SetConsoleTextAttribute(hConsole, 15);
		for (int j = 0; j < 16 - g.first.length(); j++) cout << " ";
		
		cout << (char)186 << " ";


		// name
		SetConsoleTextAttribute(hConsole, 14);
		cout << g.second.GetName();
		SetConsoleTextAttribute(hConsole, 15);
		for (int j = 0; j < 14 - g.second.GetName().length(); j++) cout << " ";

		cout << (char)186 << " ";

		
		// surname 
		SetConsoleTextAttribute(hConsole, 14);
		cout << g.second.GetSurname();
		SetConsoleTextAttribute(hConsole, 15);
		for (int j = 0; j < 14 - g.second.GetSurname().length(); j++) cout << " ";

		cout << (char)186 << " ";
		

		// patronymic
		SetConsoleTextAttribute(hConsole, 14);
		cout << g.second.GetPatronymic();
		SetConsoleTextAttribute(hConsole, 15);
		for (int j = 0; j < 14 - g.second.GetPatronymic().length(); j++) cout << " ";

		cout << (char)186 << " ";


		// address
		SetConsoleTextAttribute(hConsole, 14);
		cout << g.second.GetAddress();
		SetConsoleTextAttribute(hConsole, 15);
		for (int j = 0; j < 26 - g.second.GetAddress().length(); j++) cout << " ";

		cout << (char)186 << " ";


		// pnone number
		SetConsoleTextAttribute(hConsole, 14);
		cout << g.second.GetPhoneNumber();
		SetConsoleTextAttribute(hConsole, 15);
		for (int j = 0; j < 14 - g.second.GetPhoneNumber().length(); j++) cout << " ";

		cout << (char)186;

		id++;

		cout << "\n";

		//=============================================================================================


		// Empty row
		for (int i = 0; i <= 116; i++)
		{
			if (i == 0 || i == 6 || i == 24 || i == 40 || i == 56 || i == 72 || i == 100 || i == 116)
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


	cout << (char)200;
	for (int i = 0; i <= 114; i++)
	{
		if (i == 5 || i == 23 || i == 39 || i == 55 || i == 71 || i == 99 || i == 116)
			cout << (char)202;

		else
			cout << (char)205;
	}
	cout << (char)188;
	cout << endl;
}



void TestSystem::ModifyGuestInfo()
{

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	
	int num;

	/* Get guest id */

	cout << "\n\tChoose guest id\n";

	SetConsoleTextAttribute(hConsole, 15);
	cout << "\nEnter choice: ";
	SetConsoleTextAttribute(hConsole, 14);
	cin >> num;
	SetConsoleTextAttribute(hConsole, 15);


	/* Choose guest by login */
	int i = 1;

	for (auto g : allGuests)
	{
		if (i == num)
		{
			system("cls");
			SetConsoleTextAttribute(hConsole, 12);

			cout << "\n\tModify guest info\n\n";
			SetConsoleTextAttribute(hConsole, 15);
			cout << "\n\tChoose an option\n";


			cout << "(1) Change guest name\n" <<
				"(2) Change guest surname\n" <<
				"(3) Change guest patronymic\n" <<
				"(4) Change guest address\n" <<
				"(5) Change guest phone umber\n";
				"(6) Exit\n";


			cout << "\nEnter choice: ";
			SetConsoleTextAttribute(hConsole, 14);
			cin >> num;
			SetConsoleTextAttribute(hConsole, 15);

			string s;
			map<string, Guest>::iterator it = allGuests.find(g.first);


			switch (num)
			{
			case 1:
				cout << "\nEnter new name: ";
				SetConsoleTextAttribute(hConsole, 14);
				cin >> s;
				SetConsoleTextAttribute(hConsole, 15);

				
				it->second.SetName(s);

				return;


			case 2:
				cout << "\nEnter new surname: ";
				SetConsoleTextAttribute(hConsole, 14);
				cin >> s;
				SetConsoleTextAttribute(hConsole, 15);

				it->second.SetSurname(s);
				return;


			case 3:
				cout << "\nEnter new patronymic: ";
				SetConsoleTextAttribute(hConsole, 14);
				cin >> s;
				SetConsoleTextAttribute(hConsole, 15);

				it->second.SetPatronymic(s);
				return;


			case 4:
				cout << "\nEnter new adress: ";
				SetConsoleTextAttribute(hConsole, 14);
				cin >> s;
				SetConsoleTextAttribute(hConsole, 15);

				it->second.SetAddress(s);
				return;

			case 5:
				cout << "\nEnter new phone number: ";
				SetConsoleTextAttribute(hConsole, 14);
				cin >> s;
				SetConsoleTextAttribute(hConsole, 15);

				it->second.SetPhoneNumber(s);
				return;


			case 6:
				return;


			default:
				return;
			}
		}

		i++;
	}
}



// Deletes guest from allGuests
// Works using guest id(initialized inside)
// Used by admin
bool TestSystem::DeleteGuest()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);

	int num;

	/* Get guest id */

	cout << "\n\tChoose guest id\n";

	SetConsoleTextAttribute(hConsole, 15);
	cout << "\nEnter choice: ";
	SetConsoleTextAttribute(hConsole, 14);
	cin >> num;
	SetConsoleTextAttribute(hConsole, 15);

	int i = 1;

	for (auto g : allGuests)
	{
		if (i == num)
		{

			// Remove guest from allGuests
			allGuests.erase(g.first);


			return true;
		}

		i++;
	}

	return false;
}




#pragma endregion



#pragma region Auxiliary guest options


// Accepts number of test
// Modifies main path, so that it leads to test
// Returns true if test was found 
bool TestSystem::ChooseTest(int _num)
{
	mainPath += "*";

	_finddata_t* fileinfo = new _finddata_t;
	long done = _findfirst(mainPath.c_str(), fileinfo);
	int isReadable = done;
	int count = 0;

	cout << "\n";
	while (isReadable != -1)
	{
		if (fileinfo->name[0] != '.')
		{
			count++;

			if (count == _num)
			{
				mainPath.pop_back();
				mainPath += fileinfo->name;
				return true;
				break;
			}
		}

		isReadable = _findnext(done, fileinfo);
	}

	_findclose(done);
	delete fileinfo;
	
	return false;
}

#pragma endregion



#pragma region Help Functions


int CountChar(string s, char c)
{
	int count = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s.at(i) == c)
			count++;
	}
	return count;
}



string GetLastDir(string _path)
{
	string res = "";
	_path.pop_back();

	for (int i = _path.length() - 1; i >= 0; i--)
	{
		if (_path.at(i) == '\\') break;
		res += _path.at(i);
	}

	char tmp;
	for (int i = 0; i < res.length() / 2; i++)
	{
		tmp = res.at(i);
		res.at(i) = res.at(res.length() - i - 1);
		res.at(res.length() - i - 1) = tmp;
	}

	return res;
}



#pragma endregion

