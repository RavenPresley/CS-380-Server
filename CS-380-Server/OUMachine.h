#pragma once
#include "Machine.h"
#include <string>
#include <iostream>

class OUMachine : public Machine
{
public:
	void MoveInUse();
	OUMachine();	//default constructor

private:
	bool surplusStatus;
	bool reimageStatus;
	bool workingStatus;
	std::string IT_Location;

};