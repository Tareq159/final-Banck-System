#include <iostream>
#include <exception>
#include "Screen.h"
using namespace std;

int main()
{
	Screen::runApp();
	system("color f0");
	Screen::welcome();
	Sleep(2000);
	system("cls");
	try
	{
		while (true) {
			int s = Screen::loginAs();
			Screen::loginScreen(s);
			system("cls");
		}
	}
	catch (exception& s)
	{
		cout << s.what();
	}
	
}
