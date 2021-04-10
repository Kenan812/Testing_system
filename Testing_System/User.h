#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <io.h>

#define KEY 17

using std::cout;
using std::cin;
using std::string;
using std::ios;
using std::fstream;
using std::endl;

class User
{
protected:
	string login;  // No spaces allowed
	string password;  // No spaces allowed

public:


	User();
	User(string _login, string _password);



	//===============================================//



	void SetLogin(string _login);
	void SetPassword(string _password);

	string GetLogin() const;
	string GetPassword() const;



	//====================================================//



	// To Encrypt
	// Return encrypted result
	static string Encrypt(string _word);

	// To Decrypt
	// Return decrypted result
	static string Decrypt(string _word);



	//====================================================//


	virtual bool Register() = 0;
	virtual bool Delete() = 0;

};


// Returns true if 'word' has space
bool CheckForSpace(string word);
