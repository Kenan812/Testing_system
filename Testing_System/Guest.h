#pragma once

#include "User.h"

class Guest : public User
{
private:
	string name;
	string surname;
	string patronymic;
	string address;
	string phoneNumber;


	// All saved test results
	map<string, int> testResults; // string - path to file, int - score


public:

	Guest();


	//================================================/



	void SetName(string _name);
	void SetSurname(string _surname);
	void SetPatronymic(string _patronymic);
	void SetAddress(string _address);
	void SetPhoneNumber(string _phoneNumber);
	void SetTestResults(map<string, int> _results);

	string GetName() const;
	string GetSurname() const;
	string GetPatronymic() const;
	string GetAddress() const;
	string GetPhoneNumber() const;
	map<string, int> GetTestTesults() const;


	//================================================/



	// Returns true if registration was successfull
	// login and password is set before calling this method
	// Adds name, surname, ...	
	virtual bool Register();


	
	//================================================/



	// Used when sign up
	Guest& operator= (const Guest& g);



	//================================================/



	// Adds result to testResults
	void AddResult(string _path_to_file, int _result);


	// Shows all results by all guests in table format
	void ShowAllResults() const;


	// Shows results of only chosen category in table format
	void ShowCategoryReslts(string _path_to_category) const;


};
