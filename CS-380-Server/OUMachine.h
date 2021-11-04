#pragma once
#include "Machine.h"
#include "IUMachine.h"
#include <string>
#include <iostream>

class OUMachine : public Machine
{
public:
	void SetSurplusStatus(bool);
	void SetReimageStatus(bool);
	void SetWorkingStatus(bool);
	void SetITLocation(std::string);
	OUMachine();	//default constructor
	OUMachine(bool, bool, bool, std::string, IUMachine);	//Constructor from IUMachine
private:
	bool surplusStatus;
	bool reimageStatus;
	bool workingStatus;
	std::string IT_Location;
};

OUMachine::OUMachine(bool surplusStatusInput, bool reimageStatusInput, bool workingStatusInput, std::string IT_LocationInput, IUMachine machineInput)
{
	SetSurplusStatus(surplusStatusInput);
	SetReimageStatus(reimageStatusInput);
	SetWorkingStatus(workingStatusInput);
	SetITLocation(IT_LocationInput);

	SetAssetTag(machineInput.GetAssetTag());
	SetServiceTagNum(machineInput.GetServiceTagNum());
	SetMakeAndModel(machineInput.GetMakeAndModel());
	SetSerialNum(machineInput.GetSerialNum());
	SetIsMac(machineInput.GetIsMac());
}

OUMachine::OUMachine()
{
	this->SetAssetTag("");
	this->SetAssetTag("");
	this->SetServiceTagNum("");
	this->SetMakeAndModel("");
	this->SetSerialNum("");
	this->SetIsMac(false);
	this->SetSurplusStatus(false);
	this->SetReimageStatus(false);
	this->SetWorkingStatus(false);
	this->SetITLocation("");
}

void OUMachine::SetSurplusStatus(bool input)
{
	surplusStatus = input;
	return;
}

void OUMachine::SetReimageStatus(bool input)
{
	reimageStatus = input;
	return;
}

void OUMachine::SetWorkingStatus(bool input)
{
	workingStatus = input;
	return;
}

void OUMachine::SetITLocation(std::string input)
{
	IT_Location = input;
	return;
}