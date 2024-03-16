#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
using namespace std;

class clsCurrencyMainScreen:protected clsScreen
{

private:
	enum enCurrencyExchangeOptions{istCurrencies=1,FindCurrency=2,
		UpdateCurrency=3,CurrencyCalculater=4,MainMenue=5};


	static int _ReadCurrencyExchangeOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}

	static void GoBackToCurrencyExchange()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Currencies Menue...\n";

		system("pause>0");
		ShowCurrencyExchangeMenue();
	}

	static void ShowListCurrenciesScreen()
	{
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}
	static void ShowFindCurrenciesScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	static void ShowUpdateCurrenciesScreen()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateRateScreen();
	}
	static void ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}
	


	static void PerformCurrencyExchangeOptions(enCurrencyExchangeOptions Option)
	{
		switch (Option)
		{
		case clsCurrencyMainScreen::istCurrencies:
			system("cls");
			ShowListCurrenciesScreen();
			GoBackToCurrencyExchange();
			break;
		case clsCurrencyMainScreen::FindCurrency:
			system("cls");
			ShowFindCurrenciesScreen();
			GoBackToCurrencyExchange();
			break;
		case clsCurrencyMainScreen::UpdateCurrency:
			system("cls");
			ShowUpdateCurrenciesScreen();
			GoBackToCurrencyExchange();
			break;
		case clsCurrencyMainScreen::CurrencyCalculater:
			system("cls");
			ShowCurrencyCalculatorScreen();
			GoBackToCurrencyExchange();
			break;
		case clsCurrencyMainScreen::MainMenue:
			break;
		default:
			break;
		}
	}

public:

	static void ShowCurrencyExchangeMenue()
	{

		system("cls");
		_DrawScreenHeader("   Currency Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t    Currency Exchange\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Currency.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		PerformCurrencyExchangeOptions((enCurrencyExchangeOptions)_ReadCurrencyExchangeOption());

   }


};

