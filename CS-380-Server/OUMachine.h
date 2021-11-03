#pragma once
#include "Machine.h"
#include "IUMachine.h"
#include <string>
#include <iostream>

class OUMachine : public Machine
{
public:
	void MoveInUse();
	void SetSurplusStats(bool);
	void SetReimageStatus(bool);
	void SetWorkingStatus(bool);
	void SetITLocation(std::string);
	OUMachine();	//default constructor
	OUMachine(bool surplusStatus, bool reimageStatus, bool workingStatus, std::string IT_Location, IUMachine machine);	//Constructor from IUMachine
private:
	bool surplusStatus;
	bool reimageStatus;
	bool workingStatus;
	std::string IT_Location;

};

OUMachine::OUMachine()
{

}

void OUMachine::MoveInUse()
{

}

