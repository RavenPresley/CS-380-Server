#pragma once
#include "Machine.h"
#include <string>
#include <iostream>


class IUMachine : public Machine
{
public:
	void MoveOutOfUse();
	IUMachine(); //default contructor

private:
	std::string buildingName;
	std::string roomNum;
	std::string publicOrPrivate;
	std::string departmentInfo;
	std::string ownerInfo;
	
};