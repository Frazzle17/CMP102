#pragma once
#include <string>
using namespace std;
class accounts
{
private:
	float balance;
	string customerID;

public:
	accounts(string);
	accounts(string, float);
	~accounts();
	bool validation(float value);
	void withdraw(float withdrawal);
	void deposit(float deposit);
	void display_balance();
	float get_balance();
};

