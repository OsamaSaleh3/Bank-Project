#pragma once
#include <iostream>
#include "Global.h"
#include "clsDate.h"


using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";

        cout <<"\t\t\t\t\tUser : " << CurrentUser.UserName << endl;
        cout << "\t\t\t\t\tDate : " << clsDate::DateToString(clsDate()) << endl<<endl;
    }

    static bool CheckAccessRights(clsUser::enPermissions permission)
    {
        if (!CurrentUser.CheckAccessPermission(permission))
        {
            cout << "\t\t\t\t\t_______________________________________________________";
            cout << "\n\n\t\t\t\t\t Access Denied! Contact Your Account Admin";
            cout << "\n\t\t\t\t\t_____________________________________________________";
            return false;
        }
        else
        {
            return true;
        }
    }

    


};
