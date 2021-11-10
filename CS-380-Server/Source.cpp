#include "DataManager.h"
#include "HostManager.h"
#include "Machine.h"
#include "LoginStorage.h"
#include <iostream>
using namespace std;

int main()
{
	//Testing Machine FromString and GetInfo, making sure they match.
	Machine m;
	string s = "6818,54561,Dell HP Laptop,8941891,false,Bert Combs,301,Public,Business and Technology,Sherif Rashad,,,,,IU";
	string o;
	m.FromString(s);
	o = m.GetInfo();
	//cout << s << endl;
	//cout << o << endl;

	//Testing DataManager
	DataManager DM;
	//Open Server

	//Wait for Connections/Commands from Client

	//Parse String Commands/Data from Client

	//Create function for each possible command that gets called when the client sends that command

	return 0;
}