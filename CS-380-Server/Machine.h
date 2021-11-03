#pragma once
#include <iostream>
#include<string>

class Machine
{
public:
	Machine(); // Default constructor for Machine
	void SetAssetTag(std::string);
	void SetServiceTagNum(std::string);
	void SetMakeAndModel(std::string);
	void SetSerialNum(std::string);
	void SetIsMac(bool);
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