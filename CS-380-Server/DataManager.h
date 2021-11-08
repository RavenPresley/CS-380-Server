#pragma once
#include <iostream>
#include <vector>
#include "IUMachine.h"
#include "OUMachine.h"

class DataManager
{
public:
	DataManager(); // Default constructor for DataManager
	//Gets passed a machine's data in the form of string, returns the machine object form of it.
	Machine NewMachine(std::string);
	//Adds new IU/OU Machine to Data
	void AddMachine(Machine);
	//Removes Passed IU/OU Machine from Data
	//Must have way to search for given machine, will do so using SearchMachine and AssetTag
	void DeleteMachine(Machine);
	//Will take passed machine and overwrite machine already in Data that has the same asset tag.
	//Must have way to search for given machine, will do so using SearchMachine and AssetTag
	void EditMachine(Machine);
	//Will take given machine, and search against the other machines for matching asset tag.
	//Will search through the machines in Data for a match, and return what spot the found data is at.
	//If matching asset tag is not found, return -999
	int SearchMachine(Machine);
	//Take passed machine and display its info to the server console. Mainly to be used internally.
	void DisplayInfo(Machine);
private:
	std::vector<Machine> Data;
};

DataManager::DataManager()
{
	//Eventually, when constructed, will load all data from data.csv into the vector. For now won't do anything except create the object.
}

Machine NewMachine(std::string NewData)
{

}

void DataManager::AddMachine(Machine newMachine)
{
	Data.push_back(newMachine);

}

void DataManager::DeleteMachine(Machine delMachine)
{
	

}

void DataManager::EditMachine(Machine newMachine)
{

}

int DataManager::SearchMachine(Machine searchMachine)
{

}

void DataManager::DisplayInfo(Machine displayMachine)
{
	std::string info = displayMachine.GetInfo();
	std::cout << info;
}