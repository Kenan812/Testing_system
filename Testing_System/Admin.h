#pragma once

#include "User.h"

class Admin : public User
{
private:

public:

	// Returns true if registration was successfull
	virtual bool Register();


	// Used by admin to sign in
	// Returns true is successful 
	bool SignInAdmin();



	//====================================================//



	// Saves admin login and password to file in encrypted format
	void SaveAdminInfo();


	// Gets admin login and password and sets it 
	void GetAdminInfo();



	//====================================================//



	// Changes Login and Password 
	void ChangeLoginAndPassword();


	// To delete admin
	virtual bool Delete();
};

