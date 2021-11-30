#pragma once
#include <iostream>

class LoginStorage
{
public:
	void PullFromText();		// Will pull the correct login and username from a text file
	bool TryLogin(std::string);
	int LoginAttempts();
	void IncreaseAttempts();
	
private: 
	std::string loginInfo;
	int numAttempts = 0;
};

int LoginStorage::LoginAttempts()
{
	return numAttempts;
}

void LoginStorage::IncreaseAttempts()
{
	numAttempts++;
}

void LoginStorage::PullFromText()
{
	std::fstream infile;
	infile.open("correctLogin.txt");

	// Read the correct user names and passwords from a text file sequentially and assign them to the appropriate variables
	infile >> loginInfo;

	infile.close();

}

bool LoginStorage::TryLogin(std::string loginInput)
{
	PullFromText();

	if ((loginInput == loginInfo))
	{
		return true; 
	}
	else
	{
		return false;
	}
}
