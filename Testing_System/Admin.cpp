#include "Admin.h"


#pragma region Admin Register and Sign In


// Returns true if registration was successfull
bool Admin::Register()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);


	string login_tmp;
	string password_tmp = "";
	string password_tmp_tmp = "";  // To recheck admin password
	bool flag = true;

	// Set Admin login
	while (flag)
	{
		try
		{
			system("cls");
			SetConsoleTextAttribute(hConsole, 12);
			cout << "\n\t\tRegister New Admin\n\n";
			SetConsoleTextAttribute(hConsole, 15);


			cout << "Create login(No spaces allowed): ";

			SetConsoleTextAttribute(hConsole, 14);
			getline(cin, login_tmp);
			
			SetConsoleTextAttribute(hConsole, 15);

			if(CheckForSpace(login_tmp))
				throw "No spaces allowed";

			SetLogin(login_tmp);
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

	flag = true;

	SetConsoleTextAttribute(hConsole, 10);
	cout << "Login accepted\n";
	SetConsoleTextAttribute(hConsole, 15);
	system("pause");

//---------------------------------------------------------------------------
	
	// Set Admin password
	while (flag)
	{
		try
		{
			system("cls");
			SetConsoleTextAttribute(hConsole, 12);
			cout << "\n\t\tRegister New Admin\n\n";
			SetConsoleTextAttribute(hConsole, 15);



			SetConsoleTextAttribute(hConsole, 15);
			cout << "Create pasword(No spaces allowed): ";

			SetConsoleTextAttribute(hConsole, 14);
			getline(cin, password_tmp);

			SetConsoleTextAttribute(hConsole, 15);

			if (CheckForSpace(password_tmp))
				throw "No spaces allowed";

			SetPassword(password_tmp);
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
	flag = true;
	system("pause");


//---------------------------------------------------------------------------

	// Admin repeats the password
	while (password_tmp != password_tmp_tmp)
	{
		system("cls");
		SetConsoleTextAttribute(hConsole, 12);
		cout << "\n\t\tRegister New Admin\n\n";
		SetConsoleTextAttribute(hConsole, 15);


		cout << "\tEnter '0' to set a new password\n";
		cout << "Repeat password: ";

		SetConsoleTextAttribute(hConsole, 14);
		getline(cin, password_tmp_tmp);

		SetConsoleTextAttribute(hConsole, 15);


		if (password_tmp_tmp == "0")
		{
			system("cls");
			while (flag)
			{
				try
				{
					system("cls");
					SetConsoleTextAttribute(hConsole, 12);
					cout << "\n\t\tRegister New Admin\n\n";
					SetConsoleTextAttribute(hConsole, 15);


					SetConsoleTextAttribute(hConsole, 15);
					cout << "Create pasword(No spaces allowed): ";

					SetConsoleTextAttribute(hConsole, 14);
					getline(cin, password_tmp);

					SetConsoleTextAttribute(hConsole, 15);

					if (CheckForSpace(password_tmp))
						throw "No spaces allowed";

					SetPassword(password_tmp);
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
			flag = true;
		}


		else if (password_tmp == password_tmp_tmp)
		{
			SetConsoleTextAttribute(hConsole, 10);
			cout << "Accepted\n";
			SetConsoleTextAttribute(hConsole, 15);
			system("pause");
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 12);
			cout << "Not correct password\n";
			SetConsoleTextAttribute(hConsole, 15);
			system("pause");
			
		}
	}



	if (password == password_tmp)
	{
		system("cls");
		SetConsoleTextAttribute(hConsole, 10);
		cout << "Admin registration completed" << endl;
		SetConsoleTextAttribute(hConsole, 15);
		system("pause");
		return true;
	}
	else
	{
		system("cls");
		SetConsoleTextAttribute(hConsole, 12);
		cout << "Unable to complete registration" << endl;
		SetConsoleTextAttribute(hConsole, 15);
		system("pause");
		return false;
	}
	return false;
}


// Used by admin to sign in
bool Admin::SignInAdmin()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	string login_input;
	string password_input;

	while (true)
	{
		SetConsoleTextAttribute(hConsole, 12);
		printf("\n\t\tSign In\n\n");
		SetConsoleTextAttribute(hConsole, 15);

		cout << "Enter login: ";
		SetConsoleTextAttribute(hConsole, 14);
		getline(cin, login_input);
		SetConsoleTextAttribute(hConsole, 15);

		cout << "Enter password: ";
		SetConsoleTextAttribute(hConsole, 14);
		getline(cin, password_input);


		if (login_input == login && password_input == password)
		{
			SetConsoleTextAttribute(hConsole, 10);
			cout << "\nSign in successful" << endl;
			SetConsoleTextAttribute(hConsole, 15);
			system("pause");
			system("cls");
			return true;
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 12);
			cout << "\nIncorrect login or password" << endl;
			SetConsoleTextAttribute(hConsole, 15);
			system("pause");
			system("cls");
		}
	}
	return false;
}


#pragma endregion



#pragma region Save and Get Admin login and password to file


// Saves admin login and password to file in encrypted format
void Admin::SaveAdminInfo()
{
	string encrypted_login = Encrypt(login);
	string encrypted_password = Encrypt(password);

	int size;

	fstream file("admin.txt", ios::out | ios::binary | ios::app);

	try
	{
		if (!file) throw "Unable to open the file for write";

		size = encrypted_login.length();
		file.write((char*)&size, sizeof(size));
		file.write(encrypted_login.c_str(), size * sizeof(char));

		size = encrypted_password.length();
		file.write((char*)&size, sizeof(size));
		file.write(encrypted_password.c_str(), size * sizeof(char));

		file.close();
	}
	catch (const char* c)
	{
		cout << "Error: " << c << endl;
	}
}



// Gets admin login and password and sets it 
void Admin::GetAdminInfo()
{
	fstream file("admin.txt", ios::in | ios::binary);

	string encrypted_login;
	string encrypted_password;

	char* enc_login, * enc_password;
	int size;

	try
	{
		if (!file) throw "Unable to open the file for read";

		while (file.read((char*)&size, sizeof(int)))
		{
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
			if (enc_login) delete[] enc_login;
			if (enc_password) delete[] enc_password;

		}

			
	}
	catch (const char* c)
	{
		cout << "Error: " << c << endl;
	}
	string decrypted_login = Decrypt(encrypted_login);
	string decrypted_password = Decrypt(encrypted_password);

	login = decrypted_login;
	password = decrypted_password;
}


#pragma endregion




#pragma region Additional Settings


// Changes Login and Password 
void Admin::ChangeLoginAndPassword()
{
	Delete();
	Register();
	SaveAdminInfo();
}


bool Admin::Delete()
{
	if (remove("admin.txt") != 0)
	{
		cout << "Error...\n";
		return false;
	}
	else
	{
		cout << "Complete...\n";
		return true;
	}
}



#pragma endregion




