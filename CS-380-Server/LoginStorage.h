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
	if (correctUserName == NULL)
	{
		std::cout << "There is no user name or password set up currently. Please set up a User Name and Password..." << endl;
	}
	else if ((userNameInput == correctUserName) && (passwordInput == correctPassword))
	{
		// Grant access to the registry
	}
	else
	{
		// Deny access to the registry - will need to attempt login again

	}
}

void LoginStorage::CreateLogin(std::string newUserName, std::string newPassword)
{
	// Set correctUserName = newUserName for TryLogin() to validate later
	correctUserName = newUserName;

	// Set correctPassword = newPassword for TryLogin() to validate later
	correctPassword = newPassword;

	/*
	std::cout << "Your User Name and Password have been registered!" << endl;
	std::cout << "You may now proceed to Login." << endl;
	*/
}