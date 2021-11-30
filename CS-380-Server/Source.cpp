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
string TryCommand(string input);

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

string TryCommand(string input)
{
	//Standard Input Format:
	//Command;Data in csv format
	DataManager dm;
	char Command = ' ';
	while (input[0] != ';')
	{
		Command = input[0];
		input.erase(input.begin());
	}
	input.erase(input.begin());

	//Input will contain the data, and the switch statement will do the proper thing with that data.
	
	string message;
	switch (Command)
	{
	case 'A'://AddMachine
		cout << Command << " " << input;
		message = "Machine Added";
		break;
	case 'D'://DeleteMachine
		cout << Command << " " << input;
		message = "Machine Deleted";
		break;
	case 'C'://Send CSV
		cout << Command << " " << input;
		message = "CSV";
		break;
	case 'E'://EditMachine
		cout << Command << " " << input;
		message = "Machine Edited";
		break;
	case 'S'://SearchMachine
		cout << Command << " " << input;
		message = "Machine Found at";
		break;
	case 'L'://CheckLogin
		cout << Command << " " << input;
		message = "Login Successful/Unsuccsessful";
		break;
	default:
		cout << "Invalid Command";
		return "ERR";
	}

	return message;
}



/*
// The following pseudo-code may also be better implemented into LoginStorage instead of into the source file, but I'm going to put this here for now
// There will be 3 options for creating/updating user login information
// 1.) User 1 information
// 2.) User 2 Information
// 3.) Information for both users
// The following code won't be perfect but I think it should be a good framework for what needs to be done

LoginManager Login;

// If logging in
bool loginResult = false;
int numAttempts = 0;

while (!loginResult) // Should probably replace this with a do-while loop
{
	cin >> userNameAttempt;
	cin >> passwordAttempt;

	loginResult = Login.TryLogin(userNameAttempt, passwordAttempt);
	numAttempts++;
	if ((numAttempts < 5) && (loginResult == true))
	{
		// Break Cycle - Successful Login
	}
	else if (numAttempts >= 5)
	{
		// Break cycle - Too many login attempts
	}
}

// For CreateLogin, since we know will have a maximum of 2 users, I figured it would be easiest to have parameters for each user name and password and the userNum
// If only 1 user is used, information for user 2 will be NULL. The only problem is that if you update info for 1 user, you would have to update info for both users
// to work properly. Unless of course we determine that information cannot be updated, only created when the program is first ran. IDK we can mess around with it
// If creating a login
if (num == 1)
{
	cin >> newUserName1;
	cin >> newPassword1;
	newUserName2 = NULL;
	newPassword2 = NULL;
	
	Login.CreateLogin(num, newUserName1, newPassword1, newUserName2, NewPassword2);
}
else if (num == 2)
{
	cin >> newUserName2;
	cin >> newPassword2;
	newUserName2 = NULL;
	newPassword2 = NULL;
	
	Login.CreateLogin(num, newUserName1, newPassword1, newUserName2, NewPassword2);
}
else if (num == 3)
{
	cin >> newUserName1;
	cin >> newPassword1;
	cin >> newUserName2;
	cin >> newPassword2;
	
	Login.CreateLogin(num, newUserName1, newPassword1, newUserName2, NewPassword2);
}


*/