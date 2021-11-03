#pragma once
#include "Machine.h"
#include <string>
#include <iostream>


class IUMachine : public Machine
{
public:
	void MoveOutOfUse();
	void SetBuildingName(std::string);
	void SetRoomNum(std::string);
	void SetPublicPrivate(std::string);
	void SetDepartmentInfo(std::string);
	void SetOwnerInfo(std::string);
	IUMachine(); //default contructor
	IUMachine(std::string buildingName, std::string roomNum, std::string publicOrPrivate, std::string departmentInfo, std::string ownerInfo, OUMachine machine); //Constructor from OUMachine
private:
	std::string buildingName;
	std::string roomNum;
	std::string publicOrPrivate;
	std::string departmentInfo;
	std::string ownerInfo;
	
};

IUMachine::IUMachine()
{

}

void IUMachine::MoveOutOfUse()
{

}