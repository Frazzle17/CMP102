#include "accounts.h"
#include <iostream>
using namespace std;

accounts::accounts(string i, float j)
{
	customerID = i;
	balance = j;
}

accounts::accounts(string i)
{
	customerID = i;
	balance = 0.0;
}

accounts::~accounts()
{

}

bool accounts::validation(float value)
{
	if (value <= 0)
	{
		cout << "Invalid value: value negative" << endl;
		return false;
	}
	else
	{
		float rounded = floorf(value * 100) / 100;
		float diff = value - rounded;
		if (diff > 0)
		{
			cout << "Invalid value: value out of range" << endl;
			return false;
		}
		else
		{
			return true;
		}
	}
}

void accounts::withdraw(float withdrawal)
{
	if (validation(withdrawal) && (balance -= withdrawal) >= 0)
	{
		balance -= withdrawal;
		cout << "You have withdrawn $" << withdrawal << endl;
	}
	else
	{
		cout << "You do not have $" << withdrawal << " in your account." << endl;
	}
}

void accounts::deposit(float deposit)
{
	if (validation(deposit))
	{
		balance += deposit;
		cout << "You have deposited $" << deposit << endl;
	}
}

void accounts::display_balance()
{
	cout << "Balance is $" << balance << endl;
}

float accounts::get_balance()
{
	return balance;
}