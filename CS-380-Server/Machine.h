#pragma once
#include <iostream>
#include<string>

class Machine
{
public:
	Machine(); // Default constructor for Machine

			// Every Machine

	void SetAssetTag(std::string);
	void SetServiceTagNum(std::string);
	void SetMakeAndModel(std::string);
	void SetSerialNum(std::string);
	void SetIsMac(bool);

	std::string GetInfo();

	std::string GetAssetTag();
	std::string GetServiceTagNum();
	std::string GetMakeAndModel();
	std::string GetSerialNum();
	bool GetIsMac();

	void MoveUseStatus(bool);

			// In Use Machine
	
	void SetBuildingName(std::string);
	void SetRoomNum(std::string);
	void SetPublicPrivate(std::string);
	void SetDepartmentInfo(std::string);
	void SetOwnerInfo(std::string);

	std::string GetBuildingName();
	std::string GetRoomNum();
	std::string GetPublicPrivate();
	std::string GetDepartmentInfo();
	std::string GetOwnerInfo();

			// Out of Use Machine
	
	void SetSurplusStatus(bool);
	void SetReimageStatus(bool);
	void SetWorkingStatus(bool);
	void SetIT_Location(std::string);

	bool GetSurplusStatus();
	bool GetReimageStatus();
	bool GetWorkingStatus();
	std::string GetIT_Location();

private:
	std::string assetTag;
	std::string serviceTagNum;
	std::string makeAndModel;
	std::string serialNum;
	bool isMac;


	bool InUse; // True for In-Use, false for Out-of-Use??
				// In Use Machine
	std::string buildingName;
	std::string roomNum;
	std::string publicOrPrivate;
	std::string departmentInfo;
	std::string ownerInfo;

				// Out of Use Machine
	bool surplusStatus;
	bool reimageStatus;
	bool workingStatus;
	std::string IT_Location;


};

std::string Machine::GetInfo()
{
	std::string Info;

	Info += this->GetAssetTag();
	Info += ',';
	Info += this->GetServiceTagNum();
	Info += ',';
	Info += this->GetMakeAndModel();
	Info += ',';
	Info += this->GetIsMac();
	Info += ',';
	Info += this->GetBuildingName(); //Building Name
	Info += ',';
	Info += this->GetRoomNum();//Room Number
	Info += ',';
	Info += this->GetPublicPrivate();//Public or Private
	Info += ',';
	Info += this->GetDepartmentInfo();//DepartmentInfo
	Info += ',';
	Info += this->GetOwnerInfo();//OwnerInfo
	Info += ',';
	Info += this->GetSurplusStatus();//SurplusStatus
	Info += ',';
	Info += this->GetReimageStatus();//reimageStatus
	Info += ',';
	Info += this->GetWorkingStatus();//workingStatus
	Info += ',';
	Info += this->GetIT_Location();//IT_Location
	Info += ',';
	Info += "BASECLASS";

	return Info;
}

std::string Machine::GetAssetTag()
{
	return assetTag;
}

std::string Machine::GetServiceTagNum()
{
	return serviceTagNum;
}

std::string Machine::GetMakeAndModel()
{
	return makeAndModel;
}

std::string Machine::GetSerialNum()
{
	return serialNum;
}

bool Machine::GetIsMac()
{
	return isMac;
}

Machine::Machine()
{
	this->SetAssetTag("");
	this->SetAssetTag("");
	this->SetServiceTagNum("");
	this->SetMakeAndModel("");
	this->SetSerialNum("");
	this->SetIsMac(false);
}

void Machine::SetIsMac(bool input)
{
	isMac = input;
	return;
}

void Machine::SetAssetTag(std::string input)
{
	assetTag = input;
	return;
}

void Machine::SetServiceTagNum(std::string input)
{
	serviceTagNum = input;
	return;
}

void Machine::SetMakeAndModel(std::string input)
{
	makeAndModel = input;
	return;
}

void Machine::SetSerialNum(std::string input)
{
	serialNum = input;
	return;
}

///////////////////////////////////////////////////////////////////////
// In-Use Machine - Set Info

void Machine::MoveUseStatus(bool input) // Input true = IU; false = OU;
{
	if (input)
	{
		InUse = true;
	}
	else if(!input)
	{
		InUse = false;
	}
	else
	{
		// Error - must be true or false
	}
}
void Machine::SetBuildingName(std::string input)
{
	buildingName = input;
	return;
}
void Machine::SetRoomNum(std::string input)
{
	roomNum = input;
	return;
}
void Machine::SetPublicPrivate(std::string input)
{
	publicOrPrivate = input;
	return;
}
void Machine::SetDepartmentInfo(std::string input)
{
	departmentInfo = input;
	return;
}
void Machine::SetOwnerInfo(std::string input)
{
	ownerInfo = input;
	return;
}

// In-Use Machine - Get Info 

std::string Machine::GetBuildingName()
{
	return buildingName;
}
std::string Machine::GetRoomNum()
{
	return roomNum;
}
std::string Machine::GetPublicPrivate()
{
	return publicOrPrivate;
}
std::string Machine::GetDepartmentInfo()
{
	return departmentInfo;
}
std::string Machine::GetOwnerInfo()
{
	return ownerInfo;
}  

///////////////////////////////////////////////////////////////
// Out-of-Use Machine - Set Info

void Machine::SetSurplusStatus(bool input)
{
	surplusStatus = input;
	return;
}
void Machine::SetReimageStatus(bool input)
{
	reimageStatus = input; 
	return;
}
void Machine::SetWorkingStatus(bool input)
{
	workingStatus = input;
	return;
}
void Machine::SetIT_Location(std::string input)
{
	IT_Location = input;
	return;
}

// Out-of-Use Machine - Get Info

bool Machine::GetSurplusStatus()
{
	return surplusStatus;
}
bool Machine::GetReimageStatus()
{
	return reimageStatus;
}
bool Machine::GetWorkingStatus()
{
	return workingStatus;
}
std::string Machine::GetIT_Location()
{
	return IT_Location;
}