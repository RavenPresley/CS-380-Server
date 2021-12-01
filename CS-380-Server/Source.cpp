//Standard Includes
#include "DataManager.h"
#include "Machine.h"
#include "LoginStorage.h"
#include <iostream>
#include <string.h>
using namespace std;

//Server & Socket Functionality
//Copied from: https://docs.microsoft.com/en-us/windows/win32/winsock/complete-server-code
//Learn how to Run: https://docs.microsoft.com/en-us/windows/win32/winsock/finished-server-and-client-code
//Will be altered and adapted to our uses, for now is just here to learn from and understand over time how it works.
#undef UNICODE
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")
#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"
string TryCommand(string input, DataManager *dm);
DataManager dm;
// Code for LoginStorage will be placed at the bottom in the form of a comment to be placed appropriately within this file

int main()
{
	//Server
	
	WSADATA wsaData;//Windows socket information
	int iResult;//Test result for success of server

	SOCKET ListenSocket = INVALID_SOCKET;//Initialize the ListenSocket
	SOCKET ClientSocket = INVALID_SOCKET;//Initialize the ClientSocket

	struct addrinfo* result = NULL;//Initialize Addrinfo struct result?
	struct addrinfo hints;//Initialize Addrinfo struct hints?

	int iSendResult;//Test result for success of server
	char recvbuf[DEFAULT_BUFLEN];//Initialize the buffer for received words
	int recvbuflen = DEFAULT_BUFLEN;//Initialize the length of the buffer

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	// Resolve the server address and port
	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		return 1;
	}

	// Create a SOCKET for connecting to server
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ListenSocket == INVALID_SOCKET) {
		printf("socket failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	// Setup the TCP listening socket
	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	freeaddrinfo(result);

	iResult = listen(ListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR) {
		printf("listen failed with error: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	// Accept a client socket
	ClientSocket = accept(ListenSocket, NULL, NULL);
	if (ClientSocket == INVALID_SOCKET) {
		printf("accept failed with error: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	// No longer need server socket
	closesocket(ListenSocket);

	
	// Receive until the peer shuts down the connection
	do {
		string ret = "";
		string buff = "";
		char sendbuf[DEFAULT_BUFLEN];
		iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
		if (iResult > 0) {
			//Print Full Command
			printf("Bytes received: %d\n", iResult);
			for (int i = 0; i < iResult; i++)
			{
				buff += recvbuf[i];
			}
			
			if (buff == "ESTABLISH")
			{
				printf("Connection Established\n");
				iSendResult = send(ClientSocket, recvbuf, iResult, 0);
			}
			else
			{
				cout << "Buffer to pass: " << buff << endl;
				//Send the command to TryCommand for parsing and action
				ret = TryCommand(recvbuf);

				//Check if return is CSV, if so enter loop to send all lines to client
				if (ret == "CSV")
				{

				}

				//Turn the return into the correct format
				strcpy_s(sendbuf, ret.c_str());
				//Send the return back
				iSendResult = send(ClientSocket, sendbuf, iResult, 0);
			}

			//Make sure there was no error
			if (iSendResult == SOCKET_ERROR) {
				printf("send failed with error: %d\n", WSAGetLastError());
				closesocket(ClientSocket);
				WSACleanup();
				return 1;
			}
			//Print what was sent
			printf("Bytes sent: %d\n", iSendResult);
		}
		else if (iResult == 0)
			printf("Connection closing...\n");
		else {
			printf("recv failed with error: %d\n", WSAGetLastError());
			closesocket(ClientSocket);
			WSACleanup();
			return 1;
		}

	} while (iResult > 0);

	// shutdown the connection since we're done
	iResult = shutdown(ClientSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown failed with error: %d\n", WSAGetLastError());
		closesocket(ClientSocket);
		WSACleanup();
		return 1;
	}

	// cleanup
	closesocket(ClientSocket);
	WSACleanup();
	
	return 0;
}

string TryCommand(string input, DataManager *dm)
{
	//Standard Input Format:
	//Command;Data in csv format
	// DataManager dm;
	char Command = ' ';
	while (input[0] != ';')
	{
		Command = input[0];
		input.erase(input.begin());
	}
	input.erase(input.begin());

	//Input will contain the data, and the switch statement will do the proper thing with that data.
	
	string message;
	string loginInfo;
	LoginStorage Login;
	Machine machine;

	switch (Command)
	{
	case 'A'://AddMachine
		cout << Command << " " << input;
		// newMachine.FromString(input);
		// Machine newMachine;
		// ^^ Maybe we could do it this way? Although I believe it is meant to be done as shown below

		machine = dm->NewMachine(input); // Creates a new machine with input machine data
		dm->AddMachine(machine);		// Adds the new machine to the vector of machines
		message = "Machine Added";
		break;
	case 'D'://DeleteMachine
		cout << Command << " " << input;
		
									// Take the asset tag as input
		machine.SetAssetTag(input); // Sets the asset tag for the machine object
		dm->DeleteMachine(machine); // Passes that machine object through to DeleteMachine
		message = "Machine Deleted";
		break;
	case 'C'://Send CSV
		cout << Command << " " << input;



		message = "CSV";
		break;
	case 'E'://EditMachine
		cout << Command << " " << input;

		// This is assuming that when editing a machine, you will just pass all of the machine's information...
		// ...regardless of what data is actually being edited

		machine = dm->NewMachine(input); // Create a machine object with new data for the machine being edited
		dm->EditMachine(machine);		 // Pass that machine through EditMachine for its data to be updated
		message = "Machine Edited";
		break;
	case 'S'://SearchMachine
		cout << Command << " " << input;
		
		// Since SearchMachine is passed a Machine but only searches by the asset tag...
		// ... we'll take the assest tag as "input", use this input to set the asset tag of a machine object...
		// ... then pass that machine through SearchMachine to find its location

		machine.SetAssetTag(input);
		int location = dm->SearchMachine(machine);

		/*
		This is for if we want to display all of the info for the searched asset tag:

		string info = dm->GetMachineAt(location);
		message = "Machine found at index " + location + "; The machine's info is: " + info;

		*/

		message = "Machine Found at index " + location;
		break;
	case 'L'://CheckLogin
		cout << Command << " " << input;

		int attempts;
		bool result;
		
		result = Login.TryLogin(loginInfo);
		Login.IncreaseAttempts();
		attempts = Login.LoginAttempts();

		if ((result == true) && (attempts < 2))
		{
			message = "Login Successful";
		}
		else
		{
			message = "Login Unsuccessful";
		}
		
		break;
	default:
		cout << "Invalid Command";
		return "ERR";
	}

	return message;
}
