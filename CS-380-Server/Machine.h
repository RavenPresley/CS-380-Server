#pragma once
#include <iostream>
#include<string>

class Machine
{
public:
	Machine(); // Default constructor for Machine
	void FromString(std::string csv); //Construct from Proper String

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

	void MoveInUse(std::string buildingName, std::string roomNum, std::string publicOrPrivate, std::string departmentInfo, std::string ownerInfo);
	void MoveOutOfUse(bool surplusStatus, bool reimageStatus, bool workingStatus, std::string IT_Location);
	void SetUseStatus(std::string);
	std::string GetUseStatus();

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


	std::string UseStatus; // String that will always contain IU or OU


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
	std::string temp;

	Info += GetAssetTag();
	Info += ',';
	Info += GetServiceTagNum();
	Info += ',';
	Info += GetMakeAndModel();
	Info += ',';
	Info += GetSerialNum();
	Info += ',';
	if (GetIsMac() == true)
		temp = "true";
	else if (GetIsMac() == false)
		temp = "false";
	else
		temp = "";
	Info += temp;//IsMac
	Info += ',';
	Info += GetBuildingName(); //Building Name
	Info += ',';
	Info += GetRoomNum();//Room Number
	Info += ',';
	Info += GetPublicPrivate();//Public or Private
	Info += ',';
	Info += GetDepartmentInfo();//DepartmentInfo
	Info += ',';
	Info += GetOwnerInfo();//OwnerInfo
	Info += ',';
	if (GetSurplusStatus() == true)
		temp = "true";
	else if (GetSurplusStatus() == false)
		temp = "false";
	else
		temp = "";
	Info += temp;//SurplusStatus
	Info += ',';
	if (GetReimageStatus() == true)
		temp = "true";
	else if (GetReimageStatus() == false)
		temp = "false";
	else
		temp = "";
	Info += temp;//reimageStatus
	Info += ',';
	if (GetWorkingStatus() == true)
		temp = "true";
	else if (GetWorkingStatus() == false)
		temp = "false";
	else
		temp = "";
	Info += temp;//workingStatus
	Info += ',';
	Info += GetIT_Location();//IT_Location
	Info += ',';
	Info += UseStatus;

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
	//All Machines
	SetAssetTag("");
	SetServiceTagNum("");
	SetMakeAndModel("");
	SetSerialNum("");
	SetIsMac(false);
	//In Use
	SetBuildingName("");
	SetRoomNum("");
	SetPublicPrivate("");
	SetDepartmentInfo("");
	SetOwnerInfo("");
	//Out of Use
	//SetSurplusStatus(NULL);
	//SetReimageStatus(NULL);
	//SetWorkingStatus(NULL);
	SetIT_Location("");
	//UseStatus
	UseStatus = "";
}

void Machine::FromString(std::string csv)
{
	int i = 0;
	int data = 0;
	char curr;
	std::string temp;

	/*
	Basic Idea Behind this Algorithm:
	Create string temp that will hold the current part of the string, up until the next comma.

	Example Data String:
	"6818,54561,Dell HP Laptop,8941891,FALSE,Bert Combs,301,Public,Business and Technology,Sherif Rashad,,,,,IU"

	Will iterate over i, adding csv[i] to temp.
	Whenever curr is a comma, increase data by 1 and enter that particular data into the switch statement.
	Data starts at zero, which will not correlate to any case within the switch statement.
	Each number past zero will correlate to a particular piece of the machine's data.

	1:AssetTag
	2:Servicetag
	3:MakeandModel
	4:SerialNumber
	5:IsMac
	6:Buildingname
	7:RoomNumber
	8:PublicorPrivate
	9:DeparmentInfo
	10:OwnerInfo
	11:SurplusStatus
	12:ReimageStatus
	13:WorkingStatus
	14:ITLocation
	15:IUorOU

	When it reaches a particular case that object will be set to whatever is in temp.
	Temp will then be set to "".
	i will be increased by 1 to move past the comma.
	*/

	while (true)
	{
		curr = csv[i];

		if (curr == ',')//Comma Found
		{
			data++;
			//std::cout << "Data: " << data << " and temp is: " << temp << std::endl;
			switch (data)
			{
			case 1:
				SetAssetTag(temp);
				temp = "";
				break;
			case 2:
				SetServiceTagNum(temp);
				temp = "";
				break;
			case 3:
				SetMakeAndModel(temp);
				temp = "";
				break;
			case 4:
				SetSerialNum(temp);
				temp = "";
				break;
			case 5:
				if (temp == "true")
					SetIsMac(true);
				else if (temp == "false")
					SetIsMac(false);
				temp = "";
				break;
			case 6:
				SetBuildingName(temp);
				temp = "";
				break;
			case 7:
				SetRoomNum(temp);
				temp = "";
				break;
			case 8:
				SetPublicPrivate(temp);
				temp = "";
				break;
			case 9:
				SetDepartmentInfo(temp);
				temp = "";
				break;
			case 10:
				SetOwnerInfo(temp);
				temp = "";
				break;
			case 11:
				if (temp == "true")
					SetSurplusStatus(true);
				else if (temp == "false")
					SetSurplusStatus(false);
				break;
			case 12:
				if (temp == "true")
					SetReimageStatus(true);
				else if (temp == "false")
					SetReimageStatus(false);
				break;
			case 13:
				if (temp == "true")
					SetWorkingStatus(true);
				else if (temp == "false")
					SetWorkingStatus(false);
				break;
			case 14:
				SetIT_Location(temp);
				temp = "";
				break;
			case 15:
				SetUseStatus(temp);
				temp = "";
				break;
			}
		}

		if (curr == NULL)//EOF
		{
			SetUseStatus(temp);
			temp = "";
			break;
		}

		if (curr != ',')//Ignore next character if it is also a comma.
		{
			temp += curr;
		}
		i++;//Move to next character
	}

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

void Machine::MoveInUse(std::string buildingName, std::string roomNum, std::string publicOrPrivate, std::string departmentInfo, std::string ownerInfo)
{
	if (UseStatus == "IU")
	{
		return;
	}
	UseStatus = "IU";
	SetBuildingName(buildingName);
	SetRoomNum(roomNum);
	SetPublicPrivate(publicOrPrivate);
	SetDepartmentInfo(departmentInfo);
	SetOwnerInfo(ownerInfo);
	//SetSurplusStatus(NULL);
	//SetReimageStatus(NULL);
	//SetWorkingStatus(NULL);
	SetIT_Location("");
}

void Machine::MoveOutOfUse(bool surplusStatus, bool reimageStatus, bool workingStatus, std::string IT_Location)
{
	if (UseStatus == "OU")
	{
		return;
	}
	UseStatus = "OU";
	SetBuildingName("");
	SetRoomNum("");
	SetPublicPrivate("");
	SetDepartmentInfo("");
	SetOwnerInfo("");
	SetSurplusStatus(surplusStatus);
	SetReimageStatus(reimageStatus);
	SetWorkingStatus(workingStatus);
	SetIT_Location(IT_Location);
}

void Machine::SetUseStatus(std::string Status)
{
	UseStatus = Status;
}

std::string Machine::GetUseStatus()
{
	return UseStatus;
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