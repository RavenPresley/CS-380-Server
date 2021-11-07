##pragma once
#include <iostream>

class LoginStorage
{
public:
	bool TryLogin(std::string, std::string);
	void CreateLogin(std::string, std::string);
	
private: 
	std::string correctUserName;
	std::string correctPasword;
};

bool LoginStorage::TryLogin(std::string userNameInput, std::string passwordInput)
{
	if ((userNameInput == correctUserName) && (passwordInput == correctPassword))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void LoginStorage::CreateLogin(std::string newUserName, std::string newPassword)
{
	// Set correctUserName = newUserName for TryLogin() to validate later
	correctUserName = newUserName;

	// Set correctPassword = newPassword for TryLogin() to validate later
	correctPassword = newPassword;

}