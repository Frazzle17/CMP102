#include "accounts.h"
#include "functions.h"
#include "customer.h"
#include <iostream>

int main()
{
	customer customer1("Linda", "1");
	string val = customer1.get_custID();
	accounts account1(val, 0.0);
	functions func;
	float rates = 0.1;
	int menuNum = -1;
	while (menuNum != 0)
	{
		if (menuNum == -1)
		{
			cout << endl;
			cout << "Welcome to the Bank of Fraser. Please enter a number to make your choice." << endl;
			cout << "1 - Withdraw Money" << endl;
			cout << "2 - Withdraw $10" << endl;
			cout << "3 - Deposit Money" << endl;
			cout << "4 - Display Balance" << endl;
			cout << "5 - Calculate Interest" << endl;
			cout << "6 - Apply for Loan" << endl;
			cout << "0 - Exit" << endl;
			cin >> menuNum;
			system("CLS");
		}
		else if (menuNum == 1 && account1.get_balance() > 0)
		{
			cout << "Please enter withdrawal amount." << endl;
			float withdrawal;
			cin >> withdrawal;
			account1.withdraw(withdrawal);
			menuNum = -1;
		}
		else if (menuNum == 2 && account1.get_balance() > 0)
		{
			account1.withdraw(10);
			menuNum = -1;
		}
		else if ((menuNum == 1 || menuNum == 2) && !account1.get_balance() > 0)
		{
			cout << "You cannot withdraw money. You have none." << endl;
			menuNum = -1;
		}
		else if (menuNum == 3)
		{
			cout << "Please enter deposit amount." << endl;
			float deposit;
			cin >> deposit;
			account1.deposit(deposit);
			menuNum = -1;
		}
		else if (menuNum == 4)
		{
			account1.display_balance();
			menuNum = -1;
		}
		else if (menuNum == 5)
		{
			func.calculate_interest(rates, account1.get_balance());
			menuNum = -1;
		}
		else if (menuNum == 6)
		{
			float num;
			cout << "Enter loan amount." << endl;
			cin >> num;
			if (func.approve_loan(num, account1.get_balance()))
			{
				cout << "Loan approved" << endl;
			}
			else
			{
				cout << "Loan rejected" << endl;
			}
			menuNum = -1;
		}
		else if (menuNum == 0)
		{
			cout << "Thank you for using the Bank of Fraser. Come again!" << endl;
		}
		else
		{
			cout << "Invalid code." << endl;
			menuNum = -1;
		}
	}
}