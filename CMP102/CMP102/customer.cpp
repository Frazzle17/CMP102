#include "customer.h"

customer::customer(string i, string j)
{
	name = i;
	customerID = j;
}

customer::~customer()
{

}

string customer::get_name()
{
	return name;
}

string customer::get_custID()
{
	return customerID;
}