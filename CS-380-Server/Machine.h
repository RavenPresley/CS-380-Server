#pragma once
#include <iostream>
#include<string>

class Machine
{
public:
	Machine(); // Default constructor for Machine

private:
	std::string assetTag;
	std::string serviceTagNum;
	std::string makeAndModel;
	std::string serialNum;
	bool isMac;
};

Machine::Machine()
{

}