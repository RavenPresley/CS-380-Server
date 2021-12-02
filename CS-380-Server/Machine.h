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
	void SetIsMac(std::string);

	std::string GetInfo();

	std::string GetAssetTag();
	std::string GetServiceTagNum();
	std::string GetMakeAndModel();
	std::string GetSerialNum();
	std::string GetIsMac();

	void MoveInUse(std::string buildingName, std::string roomNum, std::string publicOrPrivate, std::string departmentInfo, std::string ownerInfo);
	void MoveOutOfUse(std::string surplusStatus, std::string reimageStatus, std::string workingStatus, std::string IT_Location);
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
	
	void SetSurplusStatus(std::string);
	void SetReimageStatus(std::string);
	void SetWorkingStatus(std::string);
	void SetIT_Location(std::string);

	std::string GetSurplusStatus();
	std::string GetReimageStatus();
	std::string GetWorkingStatus();
	std::string GetIT_Location();

	bool operator< (Machine& other);
private:
	std::string assetTag;
	std::string serviceTagNum;
	std::string makeAndModel;
	std::string serialNum;
	std::string isMac;


	std::string UseStatus; // String that will always contain IU or OU


				// In Use Machine
	std::string buildingName;
	std::string roomNum;
	std::string publicOrPrivate;
	std::string departmentInfo;
	std::string ownerInfo;

				// Out of Use Machine
	std::string surplusStatus;
	std::string reimageStatus;
	std::string workingStatus;
	std::string IT_Location;


};

std::string Machine::GetInfo()
{
	std::string Info;

	Info += GetAssetTag();
	Info += ',';
	Info += GetServiceTagNum();
	Info += ',';
	Info += GetMakeAndModel();
	Info += ',';
	Info += GetSerialNum();
	Info += ',';
	Info += GetIsMac();
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
	Info += GetSurplusStatus();//Surplus Status
	Info += ',';
	Info += GetReimageStatus();//Reimage Status
	Info += ',';
	Info += GetWorkingStatus();//workingStatus
	Info += ',';
	Info += GetIT_Location();//IT_Location
	Info += ',';
	Info += UseStatus;//Use Status

	return Info;
}

bool Machine::operator<(Machine& other)
{
	return (this->GetAssetTag() < other.GetAssetTag());
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

std::string Machine::GetIsMac()
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
	SetIsMac("");
	//In Use
	SetBuildingName("");
	SetRoomNum("");
	SetPublicPrivate("");
	SetDepartmentInfo("");
	SetOwnerInfo("");
	//Out of Use
	SetSurplusStatus("");
	SetReimageStatus("");
	SetWorkingStatus("");
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
				SetIsMac(temp);
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
				SetSurplusStatus(temp);
				temp = "";
				break;
			case 12:
				SetReimageStatus(temp);
				temp = "";
				break;
			case 13:
				SetWorkingStatus(temp);
				temp = "";
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

void Machine::SetIsMac(std::string input)
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

void Machine::MoveOutOfUse(std::string surplusStatus, std::string reimageStatus, std::string workingStatus, std::string IT_Location)
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

void Machine::SetSurplusStatus(std::string input)
{
	surplusStatus = input;
	return;
}
void Machine::SetReimageStatus(std::string input)
{
	reimageStatus = input; 
	return;
}
void Machine::SetWorkingStatus(std::string input)
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

std::string Machine::GetSurplusStatus()
{
	return surplusStatus;
}
std::string Machine::GetReimageStatus()
{
	return reimageStatus;
}
std::string Machine::GetWorkingStatus()
{
	return workingStatus;
}
std::string Machine::GetIT_Location()
{
	return IT_Location;
}