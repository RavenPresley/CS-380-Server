#pragma once
#include "Machine.h"
#include <string>
#include <iostream>


class IUMachine : public Machine
{
public:
	void SetBuildingName(std::string);
	void SetRoomNum(std::string);
	void SetPublicPrivate(std::string);
	void SetDepartmentInfo(std::string);
	void SetOwnerInfo(std::string);

	IUMachine(); //default contructor
	IUMachine(std::string, std::string, std::string, std::string, std::string, OUMachine); //Constructor from OUMachine
private:
	std::string buildingName;
	std::string roomNum;
	std::string publicOrPrivate;
	std::string departmentInfo;
	std::string ownerInfo;
	
};

IUMachine::IUMachine(std::string buildingNameInput, std::string roomNumInput, std::string publicOrPrivateInput, std::string departmentInfoInput, std::string ownerInfoInput, OUMachine machineInput)
{
	SetBuildingName(buildingNameInput);
	SetRoomNum(roomNumInput);
	SetPublicPrivate(publicOrPrivateInput);
	SetDepartmentInfo(departmentInfoInput);
	SetOwnerInfo(ownerInfoInput);

	SetAssetTag(machineInput.GetAssetTag());
	SetServiceTagNum(machineInput.GetServiceTagNum());
	SetMakeAndModel(machineInput.GetMakeAndModel());
	SetSerialNum(machineInput.GetSerialNum());
	SetIsMac(machineInput.GetIsMac());
}

IUMachine::IUMachine()
{
	this->SetAssetTag("");
	this->SetAssetTag("");
	this->SetServiceTagNum("");
	this->SetMakeAndModel("");
	this->SetSerialNum("");
	this->SetIsMac(false);

	SetBuildingName("");
	SetRoomNum("");
	SetPublicPrivate("");
	SetDepartmentInfo("");
	SetOwnerInfo("");
}

void IUMachine::SetBuildingName(std::string input)
{
	buildingName = input;
	return;
}

void IUMachine::SetRoomNum(std::string input)
{
	roomNum = input;
	return;
}

void IUMachine::SetPublicPrivate(std::string input)
{
	publicOrPrivate = input;
	return;
}

void IUMachine::SetDepartmentInfo(std::string input)
{
	departmentInfo = input;
	return;
}

void IUMachine::SetOwnerInfo(std::string input)
{
	ownerInfo = input;
	return;
}