/*
Input.exe - Returns the input type and input values by the user...

(c) 2016 - Karanveer Chouhan [kvc]
Email: karanveerchouhan@gmail.com
www.thebateam.org
June 5, 2016
No warranties. Please feel free to modify and re-distribute.

*/

#include <windows.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	
	if (argv[1]) {
	if ((int)*argv[1]==104||(int)*argv[1]==72) {
		cout << " Input (v1.0) | by Kvc" << endl 
		<< " As Cmd has a limitation of not getting both, mouse and Keyboard inputs" <<endl
		<< " togehter, but we can get either keyboard or mouse input separately via" <<endl 
		<< " various external plugins... like 'batbox.exe', 'fn.dll', 'bg.exe' etc." <<endl <<endl
		<< " But, this plugin here... will allow you to get both inputs given by user" <<endl
		<< " It will return, the input was mouse 'm' or Keyboard 'k' and corresponding" <<endl
		<< " related data for the input." <<endl
		<< " Created by: Kvc" <<endl
		<< " June 5, 2016" <<endl
		<< " karanveerchouhan@gmail.com " <<endl
		<< " Visit: www.thebateam.org" <<endl<<endl
		<< "You can get more batch plugins like this on the website above..."<<endl
		<< "Usage:" <<endl
		<< " Input.exe \t - \t Normal Usage [Without Mouse Hover Info]" <<endl
		<< " Input.exe F\t - \t Full Usage [With Mouse Hover Info, may use aLot of CPU]" <<endl
		<< " Input.exe H\t- \t Help Msg" <<endl
		<< " For help, type 'h' after Input... otherwise call it as it is." <<endl
		<< " #Kvc with #TheBATeam"<<endl;
		return 0;
	}
	}

	HANDLE hConsoleInput;
	hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);
	if(hConsoleInput == INVALID_HANDLE_VALUE)
	{
		cout<<"Failed to get console handle.\n";
		exit(0);
	}

	DWORD mode;
	LPDWORD lpMode = &mode;
	if(GetConsoleMode(hConsoleInput, lpMode) == 0)
	{
		cout<<"Failed to read console mode.\n";
		exit(0);
	}

	if(SetConsoleMode(hConsoleInput, ENABLE_MOUSE_INPUT) == 0)
	{
		cout<<"Failed to set console mode.\n";
		exit(0);
	}

	INPUT_RECORD buf;
	PINPUT_RECORD lpBuffer = &buf;
	DWORD nLength = 1;
	DWORD nNumberOfEventsRead;

	int key, x, y, button;
	while (1)
	{
		if(ReadConsoleInput(hConsoleInput, lpBuffer, nLength, &nNumberOfEventsRead) == 0)
		{
			cout<<"Failed to read console events.\n";
			exit(0);
		}

		if(buf.EventType == MOUSE_EVENT)	// MOUSE event
		{
			if(buf.Event.MouseEvent.dwButtonState)
			{
			x = buf.Event.MouseEvent.dwMousePosition.X;
			y = buf.Event.MouseEvent.dwMousePosition.Y;
			button = buf.Event.MouseEvent.dwButtonState;
			cout << "m:" << button << ":" << x << ":" << y << endl;
			break;
			}
			if (argv[1]) {
				if ((int)*argv[1]==102||(int)*argv[1]==70) {
					x = buf.Event.MouseEvent.dwMousePosition.X;
					y = buf.Event.MouseEvent.dwMousePosition.Y;
					button = buf.Event.MouseEvent.dwButtonState;
					cout << "m:" << button << ":" << x << ":" << y << endl;
					break;
				}
			}
	
		}

		if(buf.EventType == KEY_EVENT)	// KEY event
		{
			ReadConsoleInput(hConsoleInput, lpBuffer, nLength, &nNumberOfEventsRead);
			key = buf.Event.KeyEvent.uChar.UnicodeChar;
			cout << "k:" << buf.Event.KeyEvent.uChar.AsciiChar << ":" << key << endl;
			break;
			}
	}
	
	return 0;
}
