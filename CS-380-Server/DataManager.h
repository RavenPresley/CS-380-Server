#pragma once
#include <iostream>
#include <vector>
#include "IUMachine.h"
#include "OUMachine.h"

class DataManager
{
public:
	DataManager(); // Default constructor for DataManager
	void AddMachine();
	void DeleteMachine();
	void EditMachine();
	void SearchMachine();
	void DisplayInfo();
private:
	std::vector<Machine> Data;
};

DataManager::DataManager()
{

}

void DataManager::AddMachine()
{

}

void DataManager::DeleteMachine()
{

}

void DataManager::EditMachine()
{

}

void DataManager::SearchMachine()
{

}

void DataManager::DisplayInfo()
{


}