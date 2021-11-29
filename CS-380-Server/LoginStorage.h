#pragma once
#include <iostream>

class LoginStorage
{
public:
	void PullFromCSV();		// Will pull the correct login and username from a csv file
	void UpdateCSV();		// Will write the correct username and login to a csv file
	bool TryLogin(std::string, std::string);
	void CreateLogin(int, std::string, std::string, std::string, std::string);
	
private: 
	std::string correctUserName1, correctUserName2, correctPassword1, correctPassword2;
	
};

void LoginStorage::PullFromCSV()
{
	std::fstream csv;
	csv.open("correctLogin.csv");//, std::ios::in);
	// Read the correct user names and passwords from a csv file sequentially and assign them to the appropriate variables
	while (!csv.eof())
	{
		csv >> correctUserName1;
		csv >> correctUserName2;
		csv >> correctPassword1;
		csv >> correctPassword2;
	}
	csv.close();

}

void LoginStorage::UpdateCSV()
{
	std::ofstream csv;

	csv.open("correctLogin.csv"); // I'm assuming this is the correct way to write each user name and password to the csv file individually

	// Write both correct user names and passwords to the csv file sequentially after they have created and updated
	csv << correctUserName1;
	csv << correctUserName2;
	csv << correctPassword1;
	csv << correctPassword2;
	csv.close();
}

bool LoginStorage::TryLogin(std::string userNameInput, std::string passwordInput)
{
	PullFromCSV();

	if ((userNameInput == correctUserName1) && (passwordInput == correctPassword1))
	{
		return true; 
	}
	else if ((userNameInput == correctUserName2) && (passwordInput == correctPassword2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void LoginStorage::CreateLogin(int userNum, std::string newUserName1, std::string newPassword1, std::string newUserName2, std::string newPassword2)
{
	PullFromCSV();

	if (userNum == 1) // If creating/updating User 1
	{
		correctUserName1 = newUserName1;
		correctPassword1 = newPassword1;
	}
	else if (userNum == 2) // If creating/updating User 2
	{
		correctUserName2 = newUserName2;
		correctPassword2 = newPassword2;
	}
	else if (userNum == 3) // If creating/updating information for both Users
	{
		correctUserName1 = newUserName1;
		correctUserName2 = newUserName2;
		correctPassword1 = newPassword1;
		correctPassword2 = newPassword2;
	}

	UpdateCSV();


}