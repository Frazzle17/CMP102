#include "functions.h"
#include <iostream>
using namespace std;
void functions::calculate_interest(float interest_rate, float balance)
{
	float interest = balance * interest_rate;
	cout << "Interest is $" << interest << endl;
}

bool functions::approve_loan(float loan, float balance)
{
	float threshold = balance * 2;
	if (loan > threshold)
	{
		return false;
	}
	else
	{
		return true;
	}
}

