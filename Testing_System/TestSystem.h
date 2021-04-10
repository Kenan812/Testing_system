#pragma once

#include "Admin.h"
#include "Guest.h"
#include "Subject.h"

class TestSystem
{
private:
	string mainPath;

	Admin systemAdmin;

	// Values set after SignIn method
	bool is_guest; // is true when guest signed in
	bool is_admin; // is true when admin signed in

	// guests
	// Loads when program starts
	map<string, Guest> allGuests;  // string - login
	int totalNumberOfGuests;

public:
	// Checks if there was an admin
	// If there was no admin Register a new one
	// If admin exists automatically loads login and password from "admin.txt" file
	TestSystem();



	//===========================================================/



	// Lets Use TestSystem
	// Comtains all possible admin and guest actions
	void Use();
	

	// Lets use TestSystem as Admin
	// Contains all possible admin actions
	void UseAdmin();


	// Lets use TestSystem as Guest
	// Contains all possible guest actions
	void UseGuest();



	//===========================================================/



	// Must be done before doing using TestSystem
	bool SignInSystem();


	// Automatically adds guest to guests map and saves in file
	void RegisterNewGuest();


	bool SignInGuest();



	//===========================================================/


	// Allows to add, see categories, add subjects, add tests
	void ManageCategories();


	// To add delete modify guests
	void ManageGuests();



	//===========================================================/



	// Saves 1 Guest info
	// Used after registration
	void SaveGuestInfo(string login, Guest g);

	// Sets all guests to allGuests
	void LoadGuestsInfo();


	// Overrides guests.txt
	void OverrideGuests();



	//===========================================================/



	// Show categories, subjects, tests by mainPath  
	void Show();

	// Modifies main path
	// Goes to categories, subjects by mainPath  
	bool GoTo(int num);


	// Modifies mainPath by deleting last directory
	void GoBack();



	//===========================================================/




	// Adds category to Categories directory
	void Add();


	void ShowAllGuests() const;


	void ModifyGuestInfo();


	// Deletes guest from allGuests
	// Works using guest id(initialized inside)
	bool DeleteGuest();





		/* Not tested */

	// _path is path to test file
	// For guest to take a new test
	void TakeNewTest(string _path_to_file);



	// Used by guest to find test in categories
	// modifies mainPath to lead to test
	bool FindTest();




	

};


int CountChar(string s, char c);


// Returns last directory in path
string GetLastDir(string _path);
