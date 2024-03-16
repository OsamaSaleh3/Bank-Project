#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrency.h"
class clsFindCurrencyScreen:protected clsScreen
{
private:

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "Currency Found :-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "Currency Not Found :-(\n";
		}
	}
	

public:
	static void ShowFindCurrencyScreen()
	{
		system("cls");
		_DrawScreenHeader("\t\tFind Currency Screen");

		cout << "\nFind By : [1] Code or [2] Country ? ";

		short Answer; 
		Answer=clsInputValidate::ReadShortNumberBetween(1,2);

		if (Answer == 1)
		{
			string CurrencyCode;
			cout << "\nplease Enter Currency Code : ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
				_ShowResults(Currency);

		}
		else
		{
			string Country;
			cout << "\nplease enter country name : ";
			Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);
		}

	}
};

