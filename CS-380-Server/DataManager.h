#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Machine.h"
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
	//Update csv file with current contents of Data vector
	void UpdateCsv();
	//Pull info from csv into Data Vector
	void PullFromCsv();
	//Will print all machine's GetInfo
	void PrintInfo();
	//Will return the size of the data
	int GetSize();
	//Will return machine information at given index
	std::string GetMachineAt(int index);
private:
	std::vector<Machine> Data;
};

DataManager::DataManager()
{
	PullFromCsv();
}

int DataManager::GetSize()
{
	return Data.size();
}

std::string DataManager::GetMachineAt(int index)
{
	UpdateCsv();
	PullFromCsv();
	string temp;
	temp = Data.at(index).GetInfo();
	return temp;
}

void DataManager::UpdateCsv()
{
	std::string Header = "AssetTag,ServiceTagNum,MakeAndModel,SerialNumber,IsMac,BuildingName,RoomNumber,PublicOrPrivate,DepartmentInfo,OwnerInfo,SurplusStatus,ReimageStatus,WorkingStatus,ITLocation,IUorOU";
	
	std::ofstream csv("data.csv");
	csv.clear();

	csv << Header << std::endl;

	for (int i = 0;i < Data.size(); i++)
	{
		csv << Data.at(i).GetInfo() << std::endl;
	}

	csv.close();
}

void DataManager::PullFromCsv()
{
	std::fstream csv;

	csv.open("data.csv", std::ios::in);

	std::string line,temp;
	//Empty Vector
	Data.clear();
	//Get Header
	std::getline(csv, line,'\n');
	//std::cout << "Header: " <<line << std::endl;
	while (!csv.eof())
	{
		std::getline(csv, line,'\n');
		//std::cout << "New Line: " << line << std::endl;
		if (line == "")
		{
			//std::cout << "Skipping Empty Line" << std::endl;
			continue;
		}
		Machine temp;
		temp = NewMachine(line);
		Data.push_back(temp);
	}
	//std::cout << "Data Size: " << Data.size() << std::endl;
}

void DataManager::PrintInfo()
{
	for (int i = 0; i < Data.size(); i++)
	{
		std::cout << Data.at(i).GetInfo() << std::endl;
	}
}

Machine DataManager::NewMachine(std::string NewData)
{
	Machine newMachine;
	newMachine.FromString(NewData);
	return newMachine;
}

void DataManager::AddMachine(Machine newMachine)
{
	Data.push_back(newMachine);
	UpdateCsv();
}

void DataManager::DeleteMachine(Machine delMachine)
{
	int index = SearchMachine(delMachine);
	
	if (index != -999)
		Data.erase(Data.begin() + index);
	else
		std::cout << "Machine to be deleted not found.";

	UpdateCsv();
}

void DataManager::EditMachine(Machine newMachine)
{
	std::string mString = newMachine.GetInfo();
	
	int index = SearchMachine(newMachine);

	Data.at(index) = newMachine;

	UpdateCsv();
}

int DataManager::SearchMachine(Machine searchMachine)
{	
	int index = -999;
	std::string aTag = searchMachine.GetAssetTag();

	auto it = find_if(Data.begin(), Data.end(), [&aTag](Machine& m) {return m.GetAssetTag() == aTag; });
	
		if (it != Data.end())
		{
			 index = std::distance(Data.begin(), it); 
		}
			
	return index;	//returns -999 if matching assetTag not found
}

void DataManager::DisplayInfo(Machine displayMachine)
{
	std::string info = displayMachine.GetInfo();
	std::cout << info;
}