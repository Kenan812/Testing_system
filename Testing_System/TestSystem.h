#pragma once

#include "Admin.h"
#include "Guest.h"
#include "Subject.h"
#include "MakeChoice.h"

class TestSystem
{
private:
	string mainPath;  // Show where in Categories user is

	Admin systemAdmin;

	// Values set after SignIn method
	bool is_guest; // is true when guest signed in
	bool is_admin; // is true when admin signed in


	// guests
	// Loads when program starts
	map<string, Guest> allGuests;  // string - guest login
	Guest currentGuest;  // guest, who is currently signed in system
	int totalNumberOfGuests;


public:
	// Checks if there was an admin
	// If there was no admin Register a new one
	// If admin exists :
	//		automatically loads login and password from "admin.txt" file
	//		Loads guests
	//
	// If admin doesn't exist 
	//		Register new admin
	//		create 'Categories' directory
	TestSystem();



	//===========================================================/



			/* Using Test System */



	// Lets Use TestSystem
	// Contains all possible admin and guest actions
	void Use();
	

	// Lets use TestSystem as Admin
	// Contains all possible admin actions
	void UseAdmin();


	// Lets use TestSystem as Guest
	// Contains all possible guest actions
	void UseGuest();



	//===========================================================/



			/* Admin options */



	// Allows to add, see categories, add subjects, add tests
	void ManageCategories();


	// To add delete modify guests
	void ManageGuests();


	// To show statistics
	void ManageStatistics();



	//===========================================================/
	
	


	// _path is path to test file
	// For guest to take a new test
	void TakeNewTest(string _path_to_file);



	// Used by guest to find test in categories
	// modifies mainPath to lead to test
	bool FindTest();

	
	
	
	//===========================================================/




	// Must be done before doing using TestSystem
	bool SignInSystem();


	// Automatically adds guest to guests map and saves in file
	void RegisterNewGuest();


	// Sings in guest and sets him to currentGuest
	bool SignInGuest();




	//===========================================================/




	// Show categories, subjects, tests by using mainPath  
	void Show();

	// Modifies main path
	// Goes to categories, subjects by mainPath  
	bool GoTo(int num);


	// Modifies mainPath by deleting last directory
	void GoBack();



	//===========================================================/



	// Saves 1 Guest info
	// Used after registration and to override guests info
	// Save process:
	//		1)encrypted_login
	//		2)encrypted_password
	//		3)name
	//		4)surname
	//		5)patronymic
	//		6)address
	//		7)phone number
	//		8)test results
	//			1)(int)number of tests done
	//			2)(int)size (path to file)
	//			3)(char*)path to file
	//			4)(int)test result
	void SaveGuestInfo(string login, Guest g);

	// Sets all guests to allGuests
	void LoadGuestsInfo();


	// Overrides guests.txt
	void OverrideGuests();




	//===========================================================/


		/* Auxiliary admin options */
		


	// Adds category to Categories directory
	void Add();


	void ShowAllGuests() const;


	void ModifyGuestInfo();


	// Used by admin
	// Deletes guest from allGuests
	// Works using guest id(initialized inside)
	bool DeleteGuest();




	//===========================================================/

		

		/* Auxiliary guest options */
		


	// Accepts number of test
	// Modifies main path, so that it leads to test
	// Returns true if test was found 
	bool ChooseTest(int _num);

	

};


int CountChar(string s, char c);


// Returns last directory in path
string GetLastDir(string _path);
