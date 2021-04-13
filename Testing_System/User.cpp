#include "User.h"

#pragma region Constructers


User::User()
{
	login = "";
	password = "";
}

User::User(string _login, string _password)
{
	login = _login;
	password = _password;
}


#pragma endregion


#pragma region Getters and Setters


void User::SetLogin(string _login)
{
	login = _login;
}

void User::SetPassword(string _password)
{
	password = _password;
}

string User::GetLogin() const
{
	return login;
}

string User::GetPassword() const
{
	return password;
}


#pragma endregion



#pragma region Encryption and Decryption

// To Encrypt
// Return encrypted result
string User::Encrypt(string _word)
{
	string res = _word;

	for (int i = 0; i < res.length(); i++)
	{
		res.at(i) = res.at(i) + KEY;
	}

	return res;
}


// To Decrypt
// Return or decrypted result
string User::Decrypt(string _word)
{
	string res = _word;

	for (int i = 0; i < res.length(); i++)
	{
		res.at(i) = res.at(i) - KEY;
	}

	return res;
}


#pragma endregion



#pragma region Help Functions


// Returns true if 'word' has space
bool CheckForSpace(string word)
{
	for (int i = 0; i < word.length(); i++)
		if (word.at(i) == ' ')
			return true;
	return false;
}


#pragma endregion

