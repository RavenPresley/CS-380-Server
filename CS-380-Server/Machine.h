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

	std::string GetAssetTag();
	std::string GetServiceTagNum();
	std::string GetMakeAndModel();
	std::string GetSerialNum();
	bool GetIsMac();
private:
	std::string assetTag;
	std::string serviceTagNum;
	std::string makeAndModel;
	std::string serialNum;
	bool isMac;
};

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