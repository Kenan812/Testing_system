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





bool Guest::Delete() { return false; }

