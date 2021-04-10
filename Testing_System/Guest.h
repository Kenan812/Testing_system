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

public:

	Guest();


	//================================================/



	void SetName(string _name);
	void SetSurname(string _surname);
	void SetPatronymic(string _patronymic);
	void SetAddress(string _address);
	void SetPhoneNumber(string _phoneNumber);

	string GetName() const;
	string GetSurname() const;
	string GetPatronymic() const;
	string GetAddress() const;
	string GetPhoneNumber() const;



	//================================================/



	// Returns true if registration was successfull
	// login and password is set before calling this method
	// Adds name, surname, ...	
	virtual bool Register();


	
	//================================================/





	virtual bool Delete();




};
