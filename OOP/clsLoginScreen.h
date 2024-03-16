#pragma once
#include <iostream>
#include "Global.h"
#include "clsMainScreen.h"
#include "clsScreen.h"

using namespace std;

class clsLoginScreen:protected clsScreen
{

private:

	static bool _Login()
	{
		bool LoginField = false;
		string UserName,Password;
		int c = 3;
		do
		{
			if (LoginField)
			{
				cout << "\nInvalid Username/Password \n";
				c--;
				cout << "you have " << c << " Trials to login.\n\n";
			}
			if (!c)
			{
				cout << "\nyou are locked after 3 field trial \n";
				return false;
			}

			cout << "Enter Username ? \n";
			cin >> UserName;
			cout << "Enter a password ? \n";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);


			LoginField = CurrentUser.IsEmpty();

		} while (LoginField);

		clsMainScreen::ShowMainMenue();
	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t   Login Screen");
		return _Login();
	}

};

