#pragma once
#include <string>
using namespace std;

class customer
{
private:
	string name;
	string customerID;

public:
	customer(string, string);
	~customer();
	string get_name();
	string get_custID();
};

